#include"Header.h"
#include<conio.h>
#include<iostream>

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

	string_list_add(&list, str3);
	string_list_add(&list, str4);
	string_list_add(&list, str1);
	string_list_add(&list, str2);
	string_list_add(&list, str3);
	string_list_add(&list, str4);
	string_list_add(&list, str1);
	string_list_add(&list, str3);
	string_list_add(&list, str4);

	cout << "List: ";
	
	show_list(list); // shows primary state of list

	string_list_sort(&list); // sorting list
	
	cout << endl << "Sorted list: ";

	show_list(list);

	cout << endl << "index of '4': " << string_list_inedx_of(list,"4"); // shows index of string

	string_list_remove(&list, "4"); // removes string

	cout << endl << "size of list: " <<  string_list_size(list) << endl;

	cout << "Remove duplicates: ";

	string_list_remove_duplicates(&list);

	show_list(list);

	cout << endl << "size of list: " << string_list_size(list) << endl;

	cout << "Replace '2' on '5': ";

	string_list_replace(&list, "2", "5");

	show_list(list);

	string_list_destroy(&list);

	cout << endl << "Destroy list: ";

	show_list(list);

	//actions_of_list(&list);

	_getch();
	return 0;
}
