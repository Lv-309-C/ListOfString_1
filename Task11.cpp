// Task_1_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;

void StringListInit(char*** list);
void StringListDestroy(char*** list); // error
void StringListAdd(char*** list, char* str); // error
//int StringListRemove(char** list, char* str);  // error // returns the index of deleted element, -100 wasn't found
int StringListSize(char** list);
int StringListIndexOf(char** list, char* str);
//void StringListRemoveDuplicates(char** list);
bool StringListReplaceStrings(char** list, char* before, char* after);
bool StringListReplaceInStrings(char** list, char* before, char* after);
//void StringListSort(char** list);

void PRINT(char** list);


int main() {

	char** list = NULL;

	char str1[] = "This is 1.";
	char str2[] = "I'm the second line. \n";
	char str3[] = "I'm out! \n";
	char str4[] = "I'm fourth \n";

	StringListAdd(&list, str1);
	StringListAdd(&list, str2);
	StringListAdd(&list, str3);
	StringListAdd(&list, str4);
	//StringListAdd(&list, ""); // throws an exception after system ("pause")


	cout << "----------------------------------------------" << endl;
	PRINT(list);
	cout << "----------------------------------------------" << endl;

	cout << "SIZE " << StringListSize(list) << endl;

	cout << "I'm the second line. INDEX " << StringListIndexOf(list, str2) + 1 << endl; // comp counts from 0, people from 1

	//cout << "REMOVED " << StringListRemove(list, str1) << endl;
	//cout << "REMOVED " << StringListRemove(list, str3) << endl;

	StringListReplaceStrings(list, "I'm fourth", "4");
	cout << "CHANGED " << "I'm fourth -> 4" << endl;

	//StringListReplaceInStrings(list, "This", "qwer");
	//cout << "CHANGED " << "This -> qwer" << endl;

	StringListReplaceInStrings(list, "is", "QQQQQ");
	cout << "CHANGED " << "is -> QQQQQ" << endl;

	//StringListReplaceInStrings(list, "I'm", "X");
	//cout << "CHANGED " << "I'm -> X" << endl;


	cout << "----------------------------------------------" << endl;
	PRINT(list);
	cout << "----------------------------------------------" << endl;



	system("pause");
	return 0;
}

void StringListInit(char*** list)
{
	// StringListDestroy(list); // error

	*list = (char**)malloc(2 * sizeof(char*));
}

void StringListDestroy(char*** list)
{
	char**  next = NULL;

	for (int i(0); list != NULL; i++)
	{
		next = (char**)list[0];
		free(*list); // error
		*list = next;
	}

	*list = NULL;
}

void StringListAdd(char*** list, char* str)
{
	char** node;
	StringListInit(&node);

	if (str == NULL)
	{
		node[1] = (char*)malloc(strlen("default string") * sizeof(char));
		node[1] = "default string";
	}
	else
	{
		node[1] = (char*)malloc(strlen(str) * sizeof(char));
		node[1] = str;
	}
	node[0] = NULL;
	

	if (*list == NULL) // if list is empty
	{
		*list = node;
	}
	else
	{
		char **temp = *list;
		while ((temp[0]) != NULL)
		{
			temp = (char**)(temp[0]);
		}

		temp[0] = (char*)node;
	}
}

void PRINT(char** list)
{
	if (list == NULL)
		return;

	for (int i(0); list != NULL; i++)
	{
		cout << list[1] << endl;
		list = (char**)list[0];
	}
}

int StringListSize(char** list)
{
	if (list == NULL)
		return 0;

	int count = 0;

	for (int i(0); list != NULL; i++)
	{
		count++;
		list = (char**)list[0];
	}

	return count;
}

int StringListIndexOf(char** list, char* str)
{
	if ((list == NULL) || (str == NULL))
		return -100;

	int index = -100;

	for (int i(0); list != NULL; i++)
	{
		if (strcmp(str, list[1]) == NULL)
		{
			index = i;
			break;
		}
		else
		{
			list = (char**)list[0];
		}

	}

	return index;
}

/*
int StringListRemove(char** list, char* str)
{
	// remove first element of the list
	if (strcmp(str, list[1]) == NULL)
	{
		char** new_head = (char**)list[0];
		free(list[0]);
		//free(list[1]); // error
		list = new_head;
		return 0;
	}

	// remove an element in the middle
	char** head = list;
	char** prev = list; // element before deleted
	list = (char**)list[0]; // move to 2nd el of the list

	for (int i(0); list[0] != NULL; i++)
	{
		char** cur = list;
		if (strcmp(str, list[1]) == NULL)
		{
			char** next = (char**)list[0];
			free(list[0]);
			//free(list[1]); // error
			prev[0] = (char*)cur;
			//list = prev; // for remove all
			return i;
		}
		list = (char**)list[0];
	}
	return -100;
}
*/


bool StringListReplaceStrings(char** list, char* before, char* after)
{
	if (strcmp(before, after) == NULL || (before == NULL) || (after == NULL) || (list == NULL))
		return 1;

	for (int i(0); list != NULL; i++, list = (char**)list[0])
	{
		if (strcmp(before, list[1]) == NULL)
		{
			list[1] = after;
		}
	}

	return 0;
}

bool StringListReplaceInStrings(char** list, char* before, char* after)
{
	if (strcmp(before, after) == NULL || (before == NULL) || (after == NULL) || (list == NULL))
		return 1;

	bool before_found = 0;
	char *substr_ptr = NULL;
	int index = 0;

	for (int i(0); list != NULL; i++, list = (char**)list[0])
	{
		while (strstr(list[1], before) != NULL) // while before is present in list[1]
		{
			before_found = 1;

			substr_ptr = strstr(list[1], before);
			index = strlen(list[1]) - strlen(substr_ptr);
			//cout << index;

			int before_length = strlen(before);
			int after_length = strlen(after);

			if (before_length == after_length)
			{
				for (int j(0); j < after_length; j++)
				{
					list[1][index + j] = after[j];
				}
			}
			else
				if (before_length > after_length)
				{
					int delta = before_length - after_length;

					for (int j(0); j < after_length; j++)
					{
						list[1][index + j] = after[j];
					}

					int after_insert = strlen(substr_ptr) - before_length; // chars that need to be moved and attached to "after"
					
					for (int j(after_length); j < after_insert; j++)
					{
						list[1][index + j] = list[1][index + j + delta];
					}
				}
				else
					if (before_length < after_length)
					{
						int delta = after_length - before_length;

						// reallocate memory
						char* initial_string = list[1];
						// free(*list); // ERROR
						list[1] = (char*)malloc(strlen(list[1] + delta) * sizeof(char));

						// fill the end first, that insert "after" string
						
						int after_insert = strlen(substr_ptr) - before_length; // chars that need to be moved and attached to "after"
						int end_cycle = index + after_length;
						
						for (int j(strlen(initial_string) + delta - 1); j > end_cycle - 1; j--)
						{
							list[1][j] = initial_string[j - delta];
						}


						for (int j(0); j < after_length; j++)
						{
							list[1][index + j] = after[j];
						}

					}
		}
	}

	if (before_found)
		return 0;
	else return 1;
}




