#include <iostream>

#include "List.h"

int main()
{
	char** list = NULL;

	char str1[100];
	char str2[100];
	char str3[100];
	char str4[100];
	char str5[100];

	std::cout << "str1: ";
	std::cin >> str1;

	std::cout << "str2: ";
	std::cin >> str2;

	std::cout << "str3: ";
	std::cin >> str3;

	std::cout << "str4: ";
	std::cin >> str4;

	std::cout << "str5: ";
	std::cin >> str5;

	StringListAdd(&list, str1);
	StringListAdd(&list, str3);
	StringListAdd(&list, str5);
	StringListAdd(&list, str3);
	StringListAdd(&list, str2);
	StringListAdd(&list, str4);
	StringListAdd(&list, str2);
	StringListAdd(&list, str1);
	StringListAdd(&list, str5);
	StringListAdd(&list, str2);

	std::cout << "List\n";
	StringListPrint(list);

	StringListSort(list);
	std::cout << "Sorted list\n";
	StringListPrint(list);

	StringListRemove(&list, str1);
	std::cout << "List after removing str1\n";
	StringListPrint(list);

	StringListRemoveDuplicates(list);
	std::cout << "List after removing duplicates\n";
	StringListPrint(list);

	char another_str[] = "Some text";
	StringListReplaceInStrings(&list, str1, another_str);
	std::cout << "List with replaced str\n";
	StringListPrint(list);

	std::cout << "Index of str4: " << StringListIndexOf(list, str4);

	std::cout << "List size: " << StringListSize(list) << "\n";

	StringListDestroy(&list);

	system("pause");
	return 0;
}