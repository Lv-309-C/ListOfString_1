#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	ListElement list = nullptr;
	//AddStringToList(&list, "Andriy");
	//AddStringToList(&list, "Orest");
	//AddStringToList(&list, "SOLID");
	//AddStringToList(&list, "Orest is looking at the window");
	//AddStringToList(&list, "Hello world");
	//AddStringToList(&list, "Orest");
	//AddStringToList(&list, "Orest");
	AddStringToList(&list, "ABCD");
	AddStringToList(&list, "BBCC");
	AddStringToList(&list, "CACD");
	AddStringToList(&list, "BCAD");
	AddStringToList(&list, "DAAA");
	AddStringToList(&list, "CABD");
	AddStringToList(&list, "BCDA");


	PrintList(list);
	cout << "Number of items in the list: " << GetNumberOfElements(list) << endl;
	cout << "Index of str \"Andriy\" in the list: "
		 << GetIndexOfString(list, "andriy") << endl;


	ReplaceStringsInList(list, "Orest", "Andriy");
	RemoveDublicates(&list);
	PrintList(list);
	cout << "***" << endl;
	
	SortList(list, AlphabetComparator);
	PrintList(list);
	DestroyList(&list);


	system("pause");
	return 0;
}