#include <iostream>

struct rb_node
{
	int red;
	int data;
	struct rb_node* link[2];
};
struct rb_tree
{
	struct rb_node* root; // указатель на корневой узел
	long  count; // количество узлов в дереве
};
int is_red(struct rb_node* node)
{
	return node != NULL && node->red == 1;
}
/* функция для однократного поворота узла */
struct rb_node* rb_single(struct rb_node* root, int dir)
{
	struct rb_node* save = root->link[!dir];

	root->link[!dir] = save->link[dir];
	save->link[dir] = root;

	root->red = 1;
	save->red = 0;

	return save;
}

/* функция для двукратного поворота узла */
struct rb_node* rb_double(struct rb_node* root, int dir)
{
	root->link[!dir] = rb_single(root->link[!dir], !dir);
	return rb_single(root, dir);
}
/*функция создания узла*/
struct rb_node* make_node(int data)
{
	struct rb_node* rn = new rb_node();

		rn->data = data;
		rn->red = 1; /* –инициализация красным цветом */
		rn->link[0] = NULL;
		rn->link[1] = NULL;
	return rn;
}
/*добавление узла в дерево*/
int rb_insert(struct rb_tree* tree, int data)
{
	/* если добавляемый элемент оказывается первым – то ничего делать не нужно*/
	if (tree->root == NULL) {
		tree->root = make_node(data);
		if (tree->root == NULL)
			return 0;
	}
	else {
		struct rb_node head = { 0 }; /* временный корень дерева*/
		struct rb_node* g, * t;     /* дедушка и родитель */
		struct rb_node* p, * q;     /* родитель и итератор */
		int dir = 0, last;

		/* вспомогательные переменные */
		t = &head;
		g = p = NULL;
		q = t->link[1] = tree->root;

		/* основной цикл прохода по дереву */
		for (; ; )
		{
			if (q == NULL) {
				/* вставка ноды */
				p->link[dir] = q = make_node(data);
				tree->count++;
				if (q == NULL)
					return 0;
			}
			else if (is_red(q->link[0]) && is_red(q->link[1]))
			{
				/* смена цвета */
				q->red = 1;
				q->link[0]->red = 0;
				q->link[1]->red = 0;
			}
			/* совпадение 2-х красных цветов */
			if (is_red(q) && is_red(p))
			{
				int dir2 = t->link[1] == g;

				if (q == p->link[last])
					t->link[dir2] = rb_single(g, !last);
				else
					t->link[dir2] = rb_double(g, !last);
			}

			/* такой узел в дереве уже есть  - выход из функции*/
			if (q->data == data)
			{
				break;
			}
			last = dir;
			dir = q->data < data;

			if (g != NULL)
				t = g;
			g = p, p = q;
			q = q->link[dir];
		}

		/* обновить указатель на корень дерева*/
		tree->root = head.link[1];
	}
	/* сделать корень дерева черным */
	tree->root->red = 0;

	return 1;
}
int br_remove(struct rb_tree* tree, int data)
{
	if (tree->root != NULL)
	{
		struct rb_node head = { 0 }; /* временный указатель на корень дерева */
		struct rb_node* q, * p, * g; /* вспомогательные переменные */
		struct rb_node* f = NULL;  /* узел, подлежащий удалению */
		int dir = 1;

		/* инициализация вспомогательных переменных */
		q = &head;
		g = p = NULL;
		q->link[1] = tree->root;

		/* поиск и удаление */
		while (q->link[dir] != NULL) {
			int last = dir;

			/* сохранение иерархии узлов во временные переменные */
			g = p, p = q;
			q = q->link[dir];
			dir = q->data < data;

			/* сохранение найденного узла */
			if (q->data == data)
				f = q;

			if (!is_red(q) && !is_red(q->link[dir])) {
				if (is_red(q->link[!dir]))
					p = p->link[last] = rb_single(q, dir);
				else if (!is_red(q->link[!dir])) {
					struct rb_node* s = p->link[!last];


					if (s != NULL) {
						if (!is_red(s->link[!last]) && !is_red(s->link[last])) {
							/* смена цвета узлов */
							p->red = 0;
							s->red = 1;
							q->red = 1;
						}
						else {
							int dir2 = g->link[1] == p;

							if (is_red(s->link[last]))
								g->link[dir2] = rb_double(p, last);
							else if (is_red(s->link[!last]))
								g->link[dir2] = rb_single(p, last);

							/* корректировка цвета узлов */
							q->red = g->link[dir2]->red = 1;
							g->link[dir2]->link[0]->red = 0;
							g->link[dir2]->link[1]->red = 0;
						}
					}
				}
			}
		}

		/* удаление найденного узла */
		if (f != NULL) {
			f->data = q->data;
			p->link[p->link[1] == q] =
				q->link[q->link[0] == NULL];
			free(q);
		}

		/* обновление указателя на корень дерева */
		tree->root = head.link[1];
		if (tree->root != NULL)
			tree->root->red = 0;
	}

	return 1;
}
rb_tree* tree_create()
{
	rb_tree* root = new rb_tree();
	root->count = 0;
	return root;
}
void printTree(rb_node *tree,int i)
{
	if (tree == NULL)
		return;
	printTree(tree->link[1],++i);
	for (int j = 0; j < i; j++)
		std::cout << "|";
	std::cout << tree->data << std::endl;
	printTree(tree->link[0],i);
	
}
int depth(rb_node* E) //губина дерева, начиная с узла E (самая длинная ветвь)
{
	if (E == NULL) //если элем равен 0
		return 0;
	else
	{
		int A = depth(E->link[0]); //ф-ция вызывает сама себя (рекурсия)
		int B = depth(E->link[1]); //переменнная длz янахождения глубины справа
		if (A < B)
			return A + 1; //узлы +корень(1)
		else  return B + 1;
	}
}
int HeightTree(rb_node* E)
{
	int x = 0, y = 0;
	if (E == NULL) return 0;     //пустое дерево или дошли до листа
	if (E->link[0]) x = HeightTree(E->link[0]); //высота левого поддерева
	if (E->link[1]) y = HeightTree(E->link[1]);  //высота правого поддерева
	if (x > y) return x + 1;    //+1 от корня к левому поддереву
	else return y + 1;   //+1 от корня к правому поддереву
}
bool IsBalanced(rb_node* E) //функция проверки сбалансиров. дерева
{
	if (E == NULL)
		return true;
	else if (IsBalanced(E->link[0]) && IsBalanced(E->link[1])) //если сбалансированы правое и левое поддеревья
	{
		int l = depth(E->link[0]); //расчитываем глубину левого поддерева
		int r = depth(E->link[1]);
		if (abs(l - r) <= 1) //если модуль разницы глубин меньше либо равен 1
			return true; //дерево сбалансировано
		else return false;
	}
	else return false;
}
int  main()
{
	setlocale(LC_ALL, "ru");
	int count = 500000000;
	int res = 0;
	int i = 0;
	int rnd = 0;

	struct rb_tree* my_tree = tree_create();
	int choice;
	do {
		std::cout << "1 - Добавить элемент\n";
		std::cout << "2 - Удалить элемент\n";
		std::cout << "3 - Посчитать высоту\n";
		std::cout << "4 - Вывод дерева\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:int data; std::cout << "Введите число\n";
			std::cin >> data; rb_insert(my_tree,data);
			break;
		case 2:int data2; std::cout << "Введите число\n";
			std::cin >> data2; br_remove(my_tree,data2);
			break;
		case 3:std::cout << "Высота "<<HeightTree(my_tree->root)<<std::endl;
			break;
		case 4:printTree(my_tree->root, 0);
			break;
	}
	} while (choice!=0);
	return 0;
}