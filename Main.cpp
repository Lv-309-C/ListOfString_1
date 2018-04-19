#include "stdafx.h"
#include "../ListOfString/ListOfStrings.h"

#include <iostream>

int main(void)
{
	char** str_list = NULL;
	int menu_selection = 1;
	while (menu_selection)
	{
		MenuPrint();
		std::cin >> menu_selection;
		switch (menu_selection)
		{
		case 1: {
			printf("Enter the string to add ");
			char str[200];
			std::cin >> str;
			StrListAdd(&str_list, str);
			continue;
		}
		case 2: {
			printf("Enter the string to remove ");
			char str[200];
			std::cin >> str;
			StrListRemove(&str_list, str);
			continue;
		}
		case 3: {
			printf("The size of current list: %d\n", StrListSize(str_list));
			continue;
		}
		case 4: {
			printf("Enter the string to replace ");
			char str[200];
			std::cin >> str;
			printf("Enter new string ");
			char str_new[200];
			std::cin >> str_new;
			StrListReplaceStrings(str_list, str, str_new);
			continue;
		}
		case 5: {
			printf("Enter the string to find ");
			char str[200];
			std::cin >> str;
			printf("String index in list : %d\n", StrListIndexOf(str_list, str));
			continue;
		}
		case 6: {
			StrListSort(str_list);
			continue;
		}
		case 7: {
			StrListPrint(str_list);
			continue;
		}
		case 8: {
			StrListRemoveDuplicates(str_list);
			continue;
		}
		default:
			break;
		}
	}
	StrListPrint(str_list);
	StrListDestroy(&str_list);
	return 0;
}
