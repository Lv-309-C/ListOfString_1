#pragma once

#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

void StringListInit(char*** list)
{
	//if (*list != NULL)
	//{
	//	if ((*list)[1] != NULL) free((*list)[1]);
	//	free(*list);
	//}

	*list = (char**)malloc(2 * sizeof(char*));
}

void StringListDestroy(char*** list)
{
	char**  next = NULL;
	for (int i(0); *list != NULL; i++)
	{
		next = (char**)(*list)[0];
		free((*list)[1]);
		free(*list);
		*list = next;
	}

	*list = NULL;
}

void StringListAdd(char*** list, const char* str)
{
	char** node;

	StringListInit(&node);

	if (str == NULL || strlen(str) == 0)
	{
		node[1] = (char*)malloc(strlen("default string") * sizeof(char) + 1);
		strcpy(node[1], "default string");
	}
	else
	{
		node[1] = (char*)malloc(strlen(str) * sizeof(char) + 1);
		strcpy(node[1], str);
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

int StringListIndexOf(char** list, const char* str)
{
	if ((list == NULL) || (str == NULL))
		return -100;

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

bool StringListReplaceStrings(char** list, const char* before, const char* after)
{
	if (!strcmp(before, after) || (before == NULL) || (after == NULL) || (list == NULL))
		return 1;

	for (int i(0); list != NULL; i++, list = (char**)list[0])
	{
		if (!strcmp(before, list[1]))
		{
			list[1] = (char*)after;
		}
	}

	return 0;
}

bool StringListReplaceInStrings(char** list, const char* before, const char* after)
{
	if (!strcmp(before, after) || (before == NULL) || (after == NULL) || (list == NULL))
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
			//index is the location of the "before" first element
			index = strlen(list[1]) - strlen(substr_ptr);

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
					//first - part of string before replacing
					//after - (second) replaced part
					//third - part after replacing

					char *first = (char*)malloc(sizeof(char));
					char *third = (char*)malloc(sizeof(char));

					for (int j(0); j < index; j++)
					{
						first[j] = list[1][j];
					}
					first[index] = '\0'; // delete the rubbish

					for (int j(index + before_length), index_of_third(0); j < strlen(list[1]); j++, index_of_third++)
					{
						third[index_of_third] = list[1][j];
					}
					third[strlen(list[1]) - index - before_length] = '\0'; // delete the rubbish

					free(list[1]);
					list[1] = (char*)malloc(sizeof(char) * (strlen(first) + strlen(after) + strlen(third)));

					list[1][0] = '\0'; //set cursor to start of list[1]

					strcat(list[1], first);
					strcat(list[1], after);
					strcat(list[1], third);

					free(first);
					free(third);
				}
				else
					if (before_length < after_length)
					{
						//first - part of string before replacing
						//after - (second) replaced part
						//third - part after replacing

						char *first = (char*)malloc(sizeof(char));
						char *third = (char*)malloc(sizeof(char));

						for (int j(0); j < index; j++)
						{
							first[j] = list[1][j];
						}
						first[index] = '\0'; // delete the rubbish

						int delta = after_length - before_length;
						int end_cycle = strlen(list[1]) + delta;

						for (int j(index + before_length), index_of_third(0); j < end_cycle; j++, index_of_third++)
						{
							third[index_of_third] = list[1][j];
						}
						third[end_cycle - index - before_length] = '\0'; // delete the rubbish

						free(list[1]);
						list[1] = (char*)malloc(sizeof(char) * (strlen(first) + strlen(after) + strlen(third)));

						list[1][0] = '\0'; //set cursor to start of list[1]

						strcat(list[1], first);
						strcat(list[1], after);
						strcat(list[1], third);

						free(first);
						free(third);
					}
		}
	}

	if (before_found)
		return 0;
	else return 1;
}





