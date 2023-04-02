#include <iostream>
using namespace std;
#define tab "\t"
template<typename T>class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List<T>;
	}*Head, * Tail;
	unsigned int size;
	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp) :Temp(Temp) {}
		~ConstBaseIterator() {}
		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		const T& operator*()const;
		
			

	};
public:

	class ConstIterator :public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
			
		}
		~ConstIterator()
		{
 #ifdef DEBUG


			cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG
		}
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};
	class ConstReverseIterator :public ConstBaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG
		}
		~ConstReverseIterator()
		{
#ifdef DEBUG
			cout << "RItdestructor:\t" << this << endl;
#endif // DEBUG
		}
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);
	};

	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp ):ConstIterator(Temp){}
		~Iterator()
		{

		}
		T& operator *();
	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp):ConstReverseIterator(Temp){}
		~ReverseIterator(){}
		T& operator*();
	};
	ConstIterator cbegin()const;
	ConstIterator cend()const;
	ConstIterator begin()const;
	ConstIterator end()const;
	Iterator begin();
	Iterator end();

	ConstReverseIterator crbegin()const;
	ConstReverseIterator crend()const;

	ReverseIterator rbegin();
	ReverseIterator rend();

	List();

	List(const std::initializer_list<T>& il);

	~List();
	// Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insret(int Index, T Data);



	//			Removing elements
	void pop_front();
	void pop_back();
	//			Methods

	void print()const;
	void revers_print()const;

};
////////////////////////////////////////////////////////////////////////////////
//								Elements	mETHODS							  //
////////////////////////////////////////////////////////////////////////////////


template<typename T>List<T>::Element::Element(T Data, Element* pNext , Element* pPrev ) :Data(Data), pNext(pNext), pPrev(pPrev)
{
#ifdef DEBUG


	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::Element::~Element()
{
#ifdef DEBUG


	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
}



////////////////////////////////////////////////////////////////////////////////
//								Const Iterator methods						  //
////////////////////////////////////////////////////////////////////////////////

template<typename T>bool List <T>::ConstBaseIterator::operator==(const ConstBaseIterator& other)const
{
	return ConstBaseIterator::Temp == other.Temp;
}
template<typename T>bool List <T>::ConstBaseIterator::operator!=(const ConstBaseIterator& other)const
{
	return ConstBaseIterator::Temp != other.Temp;
}
template<typename T>const T& List <T>::ConstBaseIterator::operator*()const
{
	return ConstBaseIterator::Temp->Data;
}
////////////////////////////////////////////////////////////////////////////////
//								ConstBaseIte								  //
////////////////////////////////////////////////////////////////////////////////

 template<typename T>typename List<T>::ConstIterator&List<T>::ConstIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
 template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::  operator++(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
 template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::  operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return*this;
}
 template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::  operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
//-------------------------------------------------------------------------------------------------
 template<typename T>typename List<T>::ConstReverseIterator&List<T>::ConstReverseIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
 template<typename T>typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator:: operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
 template<typename T>typename List<T>::ConstReverseIterator & List<T>::ConstReverseIterator:: operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
 template<typename T>typename List<T>::ConstReverseIterator  List<T>::ConstReverseIterator:: operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}



////////////////////////////////////////////////////////////////////////////////
//								Iterator									  //
////////////////////////////////////////////////////////////////////////////////

template<typename T>T&  List<T>::Iterator::operator *()
{
	return ConstBaseIterator::Temp->Data;
}
template<typename T>T&  List<T>::ReverseIterator::operator *()
{
	return ConstBaseIterator::Temp->Data;
}


////////////////////////////////////////////////////////////////////////////////
//								Methods list								  //
////////////////////////////////////////////////////////////////////////////////
template<typename T>typename List<T>::ConstIterator List<T>::cbegin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ConstIterator List<T>::begin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::end()const
{
	return nullptr;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>List<T>::~List()
{
	while (Head)pop_front();
	cout << "LDestructor:\t" << this << endl;
}
// Adding elements:
template<typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	//Element* New = new Element (Data);//1) создали эллемент
	//Head->pPrev = New;//3)новый эллемент к голове
	//New->pNext = Head;//2)головной эллемент к новому
	//Head = New;//4)новый эллемент в голову

	Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template<typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)return push_front(Data);
	/*Element* New_Back = new Element(Data);
	New_Back->pPrev = Tail;
	Tail->pNext = New_Back;
	Tail = New_Back;*/

	Tail = Tail->pNext = new Element(Data, nullptr, Tail);

	size++;
}
template<typename T>void List<T>::insret(int Index, T Data)
{
	if (Index > size)return;

	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}

	/*Element* New = new Element(Data);
	New->pNext = Temp;
	New->pPrev = Temp->pPrev;
	Temp->pPrev->pNext = New;
	Temp->pPrev = New;*/
	Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
	size++;

}
//			Removing elements
template<typename T>void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		return;
	}
	Head = Head->pNext;
	delete Head->pPrev;
	Head->pPrev = nullptr;
	size--;
}
template<typename T>void List<T>::pop_back()
{

	if (Head == Tail)return pop_front();

	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;

}
//			Methods
template<typename T>void List<T>::print()const
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
	{
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	cout << "Кол-во элементов списка = " << size << endl;
}
template<typename T>void List<T>::revers_print()const
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
	{
		cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
	}

	cout << "Кол-во элементов списка = " << size << endl;
}
/// /////////////////////////////////////////////////////////////////////////

template<typename T>void print(const List<T>& list)
{
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
}
template<typename T>void reverse_print(const List<T>& list)
{
	for (typename List<T>::ConstReverseIterator rit = list.crbegin(); rit != list.crend(); ++rit)
	{
		//*rit *= 10;
		cout << *rit << tab;
	}
	cout << endl;
}

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "RUS");
#ifdef BASE_CHECK


	//srand(time(NULL));
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	//list.push_back(5);
	list.print();
	//list.pop_back();
	cout << "________________________________" << endl;
	list.revers_print();
	int index, value;
	cout << "Введите индекс добовляемого эллемента: "; cin >> index;
	cout << "Введите значение добовляемого эллемента: "; cin >> value;
	list.insret(index, value);
	list.print();
	list.revers_print();
#endif // BASE_CHECK

	List<int> list = { 3,5,8,13,21 };
	//list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	for (int& i : list)i *= 10;
	print(list);
	for (List<int>::ReverseIterator rit = list.rbegin(); rit != list.rend(); rit++)*rit /= 10;
	reverse_print(list);
	List<double> d_list = { 2.5,3.14,8.3,4.7 };
	for (double i : d_list)cout << i << tab; cout << endl;

}