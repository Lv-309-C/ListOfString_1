#include "stdafx.h"

#include <cstdlib>
#include <string.h>

// DEBUG
#include <iostream>
using namespace std;
// ~DEBUG

//#define String char*

void StringListInit(char*** list);
void StringListDestroy(char*** list);
void StringListAdd(char*** list, char* str);
//int StringListRemove(char** list, char* str); // doen't work
int StringListSize(char** list);
int StringListIndexOf(char** list, char* str);
//void StringListRemoveDuplicates(char** list);
bool StringListReplaceStrings(char** list, char* before, char* after);
bool StringListReplaceInStrings(char** list, char* before, char* after);
//void StringListSort(char** list);

// DEBUG
void PRINT(char** list);
// ~DEBUG


int main() {

	char** list = NULL;

	char str1[] = "This is the first line. \n";
	char str2[] = "I'm the second line. \n";
	char str3[] = "I'm out! \n";
	char str4[] = "I'm fourth \n";

	StringListAdd(&list, str1);
	StringListAdd(&list, str2);
	StringListAdd(&list, str3);
	StringListAdd(&list, str4);

	// DEBUG
	cout << "----------------------------------------------" << endl;
	PRINT(list);
	cout << "----------------------------------------------" << endl;

	cout << "SIZE " << StringListSize(list) << endl;

	cout << "I'm the second line. INDEX " << StringListIndexOf(list, str2) + 1 << endl; // comp counts from 0, people from 1

	//cout << "REMOVED " << StringListRemove(list, str1) << endl;
	//cout << "REMOVED " << StringListRemove(list, str3) << endl;

	StringListReplaceStrings(list, "I'm fourth \n", "4 \n*");
	cout << "CHANGED " << "I'm fourth -> 4" << endl;

	//StringListReplaceInStrings(list, "This", "qwer");
	//cout << "CHANGED " << "This -> qwer" << endl;

	StringListReplaceInStrings(list, "is", "QQQQQ"); // doesn't work yet
	cout << "CHANGED " << "is -> QQQQQ" << endl;

	//StringListReplaceInStrings(list, "I'm", "X");
	//cout << "CHANGED " << "I'm -> X" << endl;


	cout << "----------------------------------------------" << endl;
	PRINT(list);
	cout << "----------------------------------------------" << endl;

	// ~DEBUG


	system("pause");
	return 0;
}

void StringListInit(char*** list)
{
	*list = (char**)malloc(2 * sizeof(char*));
}

void StringListDestroy(char*** list)
{
	char**  next = NULL;

	for (int i(0); list != NULL; i++)
	{
		next = (char**)list[0];
		free(*list);
		*list = next;
	}

	*list = NULL;
}

void StringListAdd(char*** list, char* str)
{
	char** node;
	StringListInit(&node);

	node[0] = NULL;
	node[1] = (char*)malloc(strlen(str) * sizeof(char));
	node[1] = str;

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

// DEBUG
void PRINT(char** list)
{
	for (int i(0); list != NULL; i++) // ++i ?
	{
		cout << list[1];
		list = (char**)list[0];
	}
}
// ~DEBUG

int StringListSize(char** list)
{
	int count = 0;

	for (int i(0); list != NULL; i++) // put list = (char**)list[0]; in here
	{
		count++;
		list = (char**)list[0];
	}

	return count;
}

int StringListIndexOf(char** list, char* str)
{
	int index = -100;

	for (int i(0); list != NULL; i++)
	{
		if (!strcmp(str, list[1]))
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
#define DATA(list) (list[1])
#define NEXT(head) ((char**)head[0])
#define PTR_TO_NEXT(head) (head[0])

bool StringListRemove(char*** head_ptr, char* str)
{
	if (strcmp(DATA(*head_ptr), str) == 0)
	{
		char** temp = NEXT(*head_ptr);

		free(DATA(head_ptr));
		*head_ptr = temp;

		return true;
	}

	char**	first_element = *head_ptr;
	char**	curr_element = NULL;

	while (*head_ptr != NULL && PTR_TO_NEXT(head_ptr) != NULL)
	{
		curr_element = *head_ptr;

		if (strcmp(DATA(NEXT(*head_ptr)), str) == 0)
		{
			char** temp = NEXT(NEXT(*head_ptr));

			free(NEXT(*head_ptr));
			PTR_TO_NEXT(curr_element) = (char*)temp;
			*head_ptr = first_element;

			return true;
		}
		*head_ptr = NEXT(*head_ptr);
	}
	return false;
}


int StringListRemove(char** list, char* str)
{
	// remove first element of the list
	if (!strcmp(str, list[1]))
	{
		char** new_head = (char**)list[0];
		free(list[0]);
		//free(list[1]); // can we do free(list)???????????????????????????????????????????????
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
		if (!strcmp(str, list[1]))
		{
			char** next = (char**)list[0];
			free(list[0]);
			//free(list[1]); //????????????????????????????????????????????
			prev[0] = (char*)cur;
			//list = prev; // for remove all
			return i;
		}
		list = (char**)list[0];
	}
	return -100;

	// remove last element of the list
	//int index_of_last = StringListSize(list) - 1; // the index of the 1st element is 0
	//if (!strcmp(str, list[1]))
	//{
	//	char** new_head = (char**)list[0];
	//	free(list[0]);
	//	free(list[1]);
	//	list = new_head;
	//	return;
	//}
}

*/


bool StringListReplaceStrings(char** list, char* before, char* after)
{
	if (!strcmp(before, after) || (before == NULL) || (after == NULL) || (list == NULL)) return 1;

	for (int i(0); list != NULL; i++, list = (char**)list[0])
	{
		if (!strcmp(before, list[1]))
		{
			list[1] = after;
		}
	}

	return 0;
}

bool StringListReplaceInStrings(char** list, char* before, char* after)
{
	if (!strcmp(before, after) || (before == NULL) || (after == NULL) || (list == NULL)) return 1;

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
						// free(list[1]); // ERROR
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




