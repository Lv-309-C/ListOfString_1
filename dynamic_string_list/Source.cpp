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

//void print_menu()
//{
//	printf("To add string - enter 1 %-10\t");
//	printf("To remove string - enter 5 \n");
//	printf("To get size of list - enter 2 \t");
//	printf("To get index position of string - enter 6 \n");
//	printf("To remove duplicates - enter 3 \t");
//	printf("To replace the text in items - enter 7 \n");
//	printf("To sort list - enter 4 \t\t");
//	printf("To show list - enter 8 \n");
//	printf("To end programme - enter 0 \n");
//
//	printf("\nYour choise: ");
//}
//
//void actions_of_list(char*** list)
//{
//	char choice = ' ';
//	char* str = " ";
//
//	while (true)
//	{
//		print_menu();
//
//		choice = getchar();
//
//		system("cls");
//
//		switch (choice)
//		{
//			case '1':
//			{
//				printf("Enter a string: ");
//				scanf_s(str);
//				
//
//				printf("\nstr: %s", str);
//				string_list_add(list, str);
//				break;
//			}
//			case '2':
//			{
//
//			}
//			case '3':
//			{
//
//			}
//			case '4':
//			{
//
//			}
//			case '5':
//			{
//
//			}
//			case '6':
//			{
//
//			}
//			case '7':
//			{
//
//			}
//			case '8':
//			{
//				show_list(*list);
//				break;
//			}
//			case '0':
//				return;
//			default:
//			{
//
//			}
//		}
//	}
//}

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
