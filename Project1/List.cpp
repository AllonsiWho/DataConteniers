#include"List.h"




////////////////////////////////////////////////////////////////////////////////
//								Elements	mETHODS							  //
////////////////////////////////////////////////////////////////////////////////


template<typename T>List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) :Data(Data), pNext(pNext), pPrev(pPrev)
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

template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
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
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
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
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator:: operator--()
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

template<typename T>T& List<T>::Iterator::operator *()
{
	return ConstBaseIterator::Temp->Data;
}
template<typename T>T& List<T>::ReverseIterator::operator *()
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