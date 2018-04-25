#include<iostream>
#include<conio.h>
#include<random>
#include<time.h>
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

void QuickSort(int* numbers, int start, int end)
{
	int i, j;

	i = start;
	j = end;
	int middle = numbers[(i + j) / 2];

	do
	{
		while (middle > numbers[i]) i++;
		while (middle < numbers[j]) j--;

		if (i <= j)
		{
			swap(numbers[i], numbers[j]);
			i++;
			j--;
		}
	} while (i < j);

	if (i < end) QuickSort(numbers, i, end);
	if (j > start) QuickSort(numbers, start, j);
}

void BubbleSort(int* numbers, int quantity)
{
	for (int i(0); i < quantity; i++)
	{
		for (int j(1); j < quantity; j++)
		{
			if (numbers[j - 1] > numbers[j])
			{
				int temp = numbers[j - 1];
				numbers[j - 1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
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

	/*
	srand(time(NULL));

	int quantity;
	cin >> quantity;

	for (int i(0); i < quantity; i++)
	{
		char* str = (char*)malloc(2 * sizeof(char));

		str[0] = (char)(48 + (rand() % (57 - 48)));
		str[1] = '\0';

		StringListAdd(&list, str);
	}

	cout << "List: ";

	//show_list(list);

	double time_one = clock();

	StringListQuickSort(list);
	//StringListBubbleSort(&list);

	double time_two = clock() - time_one;

	cout << "Time of sorting: " << time_two / CLOCKS_PER_SEC; // 1 sec = 1000 CLOCKS

	cout << endl;
	*/

	show_list(list);

//-------------------------------------------------------------------
	StringListQuickSort(list);
	//StringListBubbleSort(&list);

	cout << endl << "Sorted list: ";

	show_list(list);
//-------------------------------------------------------------------
	cout << endl << "index of '4': " << StringListIndexOf(list, "4");
//-------------------------------------------------------------------
	cout << "\nRemove from list '4'";
	
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

	
	//int n;

	//cin >> n;

	//system("cls");

	//int* numbers = new int[n];

	//srand(time(NULL));

	//for (int i(0); i < n; i++)
	//	numbers[i] = rand();

	//double time_one = clock();

	//QuickSort(numbers, 0, n - 1);
	////BubbleSort(numbers, n);

	//double time_two = clock() - time_one;

	//cout << "Time of sorting: " << time_two / CLOCKS_PER_SEC; // 1 sec = 1000 CLOCKS
	//

	_getch();
	return 0;
}
