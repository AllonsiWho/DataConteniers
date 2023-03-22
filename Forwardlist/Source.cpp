#include <iostream>
using namespace std;
#define tab "\t"
class Element
{
	int Data;//Значение эллемента
	Element* pNext;// адрес следующего эллемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		//cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		//cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
class ForwardList // Forward-односвязный, однонаправленный
{
	Element* Head;//Голова списка содержит указатель на нулевой эллемент списка
public:
	ForwardList()
	{
		Head = nullptr;// Если список пуст то его Голова указывает на 0
		//cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		//cout << "LDistructor:\t" << this << endl;
	}

	// Adding elements:
	void pop_front()
	{
		Element* bof = Head;
		Head = Head->pNext;
		delete bof;

	}
	void pop_back()
	{
		Element* bof = Head;
		while (bof->pNext->pNext)
		{
			bof = bof->pNext;
		}
		delete bof->pNext;
		bof->pNext = nullptr;
	}
	void push_front(int Data)
	{
		Element* New = new Element(Data);// создаем новый эллемент
		//2) Новый эллемент должен указываеть на начало списка
		New->pNext = Head;
		//3)Голову списка переводим на новый эллемент
		Head = New;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* New_back = new Element(Data);
		
		Element* Temp = Head;
		while (Temp->pNext)
		{	Temp = Temp->pNext;
		}	
			Temp->pNext = New_back;//Не в цикле						
	}

	//						Methods:
	void print()const
	{
		Element* Temp = Head;//temp итератор
		//Итератор -это указатель при помощи которго можно получить 
		//доступ к эллементам структуры данных
		//while (Temp)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext;
		//	Temp = Temp->pNext;//Ппереход на следующий эллемент
		//}
		while (Temp)
		{
			cout << Temp->Data << tab;
			Temp = Temp->pNext;//Ппереход на следующий эллемент
		}
		cout << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
		list.print();

		list.pop_back();
		list.print();
		list.pop_front();
		list.print();
		/*list.push_back(5);
	
		list.print();*/
		
}