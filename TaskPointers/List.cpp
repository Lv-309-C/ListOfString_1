#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	ListElement list = nullptr;
	AddStringToList(&list, "Andriy");
	AddStringToList(&list, "Orest");
	AddStringToList(&list, "SOLID");
	AddStringToList(&list, "Hello world");

	PrintList(list);
	cout << "Number of items in the list: " << GetNumberOfElements(list) << endl;
	cout << "Index of str \"Andriy\" in the list: "
		 << GetIndexOfString(list, "andriy") << endl;
	DestroyList(&list);

	system("pause");
	return 0;
}