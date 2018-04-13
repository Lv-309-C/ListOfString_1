#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	ListElement list = nullptr;
	AddStringToList(&list, "Andriy");
	AddStringToList(&list, "Orest");
	AddStringToList(&list, "SOLID");
	AddStringToList(&list, "Orest");
	AddStringToList(&list, "Hello world");
	AddStringToList(&list, "Orest");
	AddStringToList(&list, "Orest");

	PrintList(list);
	cout << "Number of items in the list: " << GetNumberOfElements(list) << endl;
	cout << "Index of str \"Andriy\" in the list: "
		 << GetIndexOfString(list, "andriy") << endl;

	RemoveStringFromList(&list, "solid");
	PrintList(list);
	//PrintListReverse(list);
	RemoveDublicates(&list);
	PrintList(list);
	DestroyList(&list);

	//ListElement elem = InitElementOfList();
	//String str = "Orest";
	//elem[Data] = (String)malloc(strlen(str) + 1);
	//strcpy(elem[Data], str);
	//cout << elem[Data] << endl;

	//String* str2 = &elem[Data];
	//free(elem);
	//cout << *str2 << endl;

	system("pause");
	return 0;
}