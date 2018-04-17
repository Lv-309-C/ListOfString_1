#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	ListElement list = nullptr;
	AddStringToList(&list, "Andriy");
	AddStringToList(&list, "Orest");
	AddStringToList(&list, "SOLID");
	AddStringToList(&list, "OOD");
	AddStringToList(&list, "Unit Test Task");
	AddStringToList(&list, "Orest is looking at the window");
	AddStringToList(&list, "Hello world");
	AddStringToList(&list, "Andriy");
	AddStringToList(&list, "Orest");


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
	cout << "***" << endl;

	SortList(list, SizeComparator);
	PrintList(list);
	DestroyList(&list);


	system("pause");
	return 0;
}