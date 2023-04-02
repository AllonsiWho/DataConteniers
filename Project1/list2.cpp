#include"List.cpp"


//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "RUS");
#ifdef BASE_CHECK


	//srand(time(NULL));
	int n;
	cout << "¬ведите размер списка: "; cin >> n;
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
	cout << "¬ведите индекс добовл€емого эллемента: "; cin >> index;
	cout << "¬ведите значение добовл€емого эллемента: "; cin >> value;
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