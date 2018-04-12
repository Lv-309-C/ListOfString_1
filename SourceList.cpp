#include<iostream>
#include<conio.h>
#include"HeaderList.h"

using namespace std;

void show_list(char** list)
{
	while (list != NULL)
	{
		//cout << list[0] << " ";
		printf("%s ", list[0]);
		list = (char**)list[1];
	}
	printf("NULL");
}

int main()
{
	char** list = NULL;
	char* str1 = "1";
	char* str2 = "2";
	char* str3 = "3";
	char* str4 = "4";

	StringListAdd(&list, str3);
	StringListAdd(&list, str3);
	StringListAdd(&list, str1);
	StringListAdd(&list, str2);
	StringListAdd(&list, str4);
	StringListAdd(&list, str4);
	StringListAdd(&list, str1);
	StringListAdd(&list, str3);
	StringListAdd(&list, str4);

	cout << "List: ";

	show_list(list);
//-------------------------------------------------------------------
	StringListSort(&list);

	cout << endl << "Sorted list: ";

	show_list(list);
//-------------------------------------------------------------------
	cout << endl << "index of '4': " << StringListIndexOf(list, "4");
//-------------------------------------------------------------------
	StringListRemove(&list, "4");

	cout << endl << "size of list: " << StringListSize(list) << endl;
//-------------------------------------------------------------------
	cout << "Remove duplicates: ";

	StringListRemoveDuplicates(&list);

	show_list(list);
//-------------------------------------------------------------------
	cout << endl << "size of list: " << StringListSize(list) << endl;
//-------------------------------------------------------------------
	cout << "Replace '2' on '5': ";

	StringListReplace(&list, "2", "5");

	show_list(list);
//-------------------------------------------------------------------
	StringListDestroy(&list);

	cout << endl << "Destroy list: ";

	show_list(list);
//-------------------------------------------------------------------
	//actions_of_list(&list);

	_getch();
	return 0;
}
