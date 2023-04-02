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

	int Deptc(Element* Root)const
	{
		
		if (Root == nullptr) return 0;
		
		if ((Deptc(Root->pLeft) + 1) > Deptc(Root->pRight) + 1) return Deptc(Root->pLeft) + 1;
		else return Deptc(Root->pRight) + 1;

	}

	void Clear(Element* Root)
	{
		if (Root == nullptr)
		{
			cout << "Деврево пустое " << endl;
			return;
		}
		if (Root->pRight!=nullptr)
		{
			Clear(Root->pRight);
		}
		else if (Root->pLeft!=nullptr)
		{
			Clear(Root->pLeft);
		}
		if (Root->pRight==nullptr)
		{
			delete Root->pRight;
			Root->pRight = nullptr;

		}
		else if(Root->pLeft == nullptr)
		{
			delete Root->pLeft;
			Root->pLeft = nullptr;
		}
		else
		{
			delete Root;
			//Root = nullptr;
			
		}
		 
	}

	void Erase(Element* Root, int value)
	{
		if (Root == nullptr) return;
		if (Root->Data == value)
		{	
			if(Root->pRight==nullptr&&Root->pLeft==nullptr)
			{
			  delete Root;
			 Root = nullptr;
			 return;
			}
			if (Root->pRight != nullptr)
			{
				Root->Data = Root->pRight->Data;
				delete Root->pRight;
				Root->pRight = nullptr;
			}
			if (Root->pLeft != nullptr)
			{
				Root->Data = Root->pLeft->Data;
				delete Root->pLeft;
				Root->pLeft = nullptr;
			}	
		}
		if (Root->Data < value)
		{
			Erase(Root->pRight, value);
		}
		if (Root->Data > value)
		{
			Erase(Root->pLeft, value);
		}

		//if (Root->pRight->Data == value)
		//{
		//	if (Root->pRight->pRight == nullptr && Root->pRight->pLeft == nullptr)
		//	{
		//		delete Root->pRight;
		//		Root->pRight = nullptr;
		//	}
		//	if(Root->pRight->pRight!=nullptr&&Root->pRight->pLeft==nullptr)
		//	{
		//		delete Root->pRight;
		//		Root->pRight = Root->pRight->pRight;
		//	}
		//	if (Root->pRight->pRight == nullptr && Root->pRight->pLeft != nullptr)
		//	{
		//		delete Root->pRight;
		//		Root->pRight = Root->pRight->pLeft;
		//	}
		//	if (Root->pRight->pRight != nullptr && Root->pRight->pLeft != nullptr)
		//	{
		//		//в доработке
		//		return;


		//	}

		//}
		//if (Root->pLeft->Data == value)
		//{
		//	if (Root->pLeft->pRight == nullptr && Root->pLeft->pLeft == nullptr)
		//	{
		//		delete Root->pLeft;
		//		Root->pLeft = nullptr;
		//	}
		//	if (Root->pLeft->pRight != nullptr && Root->pLeft->pLeft == nullptr)
		//	{
		//		delete Root->pLeft;
		//		Root->pLeft = Root->pLeft->pRight;
		//	}
		//	if (Root->pLeft->pRight == nullptr && Root->pLeft->pLeft != nullptr)
		//	{
		//		delete Root->pLeft;
		//		Root->pLeft = Root->pLeft->pLeft;
		//	}
		//	if (Root->pLeft->pRight != nullptr && Root->pLeft->pLeft != nullptr)
		//	{
		//		//в доработке
		//		return;


		//	}

		//}

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
	cout << "Кол-во эллементов " << tree.Count(tree.getRoot()) << endl;
	cout << "Сумма эллементов дерева: " << tree.Sum(tree.getRoot()) << endl;
	cout << "Среднее значение эллементов: " << tree.Avg() << endl;
	cout << "Глубина дерева " << tree.Deptc(tree.getRoot()) << endl;
	cout << "del elment " << endl; int Q; cin >> Q;

	tree.Erase(tree.getRoot(), Q);
	//tree.Clear(tree.getRoot());
	tree.print(tree.getRoot());
	cout << "\n------------------------------------\n";
	//tree.print();
	cout << "\n------------------------------------\n";

	/*UniqueTree tree2;
	for (int i = 0; i < n; i++)
	{
		tree2.insert(rand() % 100, tree2.getRoot());
	}	
	tree2.print(tree2.getRoot());
	cout << endl;*/
	
	
}
