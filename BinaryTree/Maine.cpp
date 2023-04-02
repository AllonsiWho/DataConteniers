#include<iostream>
#include<ctime>
using namespace std;

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public: 
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			//cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			//cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}


	}


	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}

	int minValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)
	{

		if (Root == nullptr) return 0;
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int Count(Element* Root)
	{	
		/*static int count = 0;
		if (Root == nullptr) return 0;		
		Count(Root->pLeft);
		count++;
		Count(Root->pRight);
		count++;
		return count/2;*/

		if (Root == nullptr) return 0;
		else return Count(Root->pLeft) + Count(Root->pRight) + 1;
	}

	int Sum(Element* Root)
	{
		if (Root == nullptr) return 0;

		else return Sum(Root->pLeft) + Sum(Root->pRight)+Root->Data;
	}
	double Avg()
	{
		return(double)Sum(Root) / Count(Root);
	}
};

class UniqueTree :public Tree
{
public:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if(Data>Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}


	}

};




void main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100,tree.getRoot());
	}

	tree.print(tree.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве: " << tree.minValue(tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue(tree.getRoot()) << endl;	
	//unsigned int start_time = clock();	
	cout << "Кол-во эллементов " << tree.Count(tree.getRoot()) << endl;
	cout << "Сумма эллементов дерева: " << tree.Sum(tree.getRoot()) << endl;
	cout << "Среднее значение эллементов: " << tree.Avg() << endl;
	UniqueTree tree2;

	for (int i = 0; i < n; i++)
	{
		tree2.insert(rand() % 100, tree2.getRoot());
	}
	/*while (tree2.Count(tree2.getRoot()) < n)
	{
		tree2.insert(rand() % 100, tree2.getRoot());
	}*/
	tree2.print(tree2.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве: " << tree2.minValue(tree2.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << tree2.maxValue(tree2.getRoot()) << endl;	
	cout << "Кол-во эллементов " << tree2.Count(tree2.getRoot()) << endl;
	cout << "Сумма эллементов дерева: " << tree2.Sum(tree2.getRoot()) << endl;
	cout << "Среднее значение эллементов: " <<tree2.Avg() << endl;
	//unsigned int end_time = clock();	
	//unsigned int search_time = end_time - start_time;
	//cout << "Время подссчета: " << search_time << " c " << endl;
}
