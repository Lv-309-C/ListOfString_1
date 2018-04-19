#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS

#include "../ListOfString/ListOfStrings.h"

void MenuPrint()
{
	printf("\n\t\t******List of strings******\n\n\n");
	printf("\tIf you want to add a string press\t\t 1\n");
	printf("\tIf you want to delete a string press\t\t 2\n");
	printf("\tIf you want to know the size of list press\t 3\n");
	printf("\tIf you want to replace strings press\t\t 4\n");
	printf("\tIf you want to find strings index press\t\t 5\n");
	printf("\tIf you want to sort the list press\t\t 6\n");
	printf("\tIf you want to show current list press\t\t 7\n");
	printf("\tIf you want to remove duplicates press\t\t 8\n");
	printf("\tIf you want to exit press\t\t\t 0\n");
}

void StrListPrint(char** my_list)
{
	printf("Current list:\n");
	for (size_t i = 0; my_list != NULL; ++i)
	{
		std::cout << "List[" << i << "] : " << my_list[0] << std::endl;
		my_list = (char**)my_list[1];
	}
	printf("\n");
}


void StrListInit(char*** list_ptr)
{
	*list_ptr = NULL;
	*list_ptr = (char**)malloc(2 * sizeof(char*));
	if (!(*list_ptr))
	{
		printf("Memory allocation error\n");
		exit(1);
	}
	(*list_ptr)[1] = NULL;
}

void StrListDestroy(char*** list_ptr)
{
	char**  next_element = NULL;
	while (*list_ptr != NULL)
	{
		next_element = (char**)(*list_ptr)[1];
		free(*list_ptr);
		*list_ptr = next_element;
	}
	*list_ptr = NULL;
}

size_t StrListSize(char** my_list)
{
	size_t	counter = 0U;
	for (; my_list != NULL; ++counter)
		my_list = (char**)my_list[1];
	return counter;
}

size_t StrListIndexOf(char** last_elem, char* str)
{
	size_t counter = 0U;
	while (last_elem != NULL)
	{
		if (strstr(last_elem[0], str) == NULL) ++counter;
		last_elem = (char**)last_elem[1];
	}
	return counter;
}

void StrListAdd(char*** head_ptr, char* str)
{
	char** node = NULL;
	StrListInit(&node);
	node[0] = (char*)malloc(strlen(str));
	if (!node[0])
	{
		printf("Memory allocation error\n");
		exit(1);
	}
	strcpy_s(node[0], 200,  str);
	node[1] = NULL;
	if (*head_ptr == NULL)
		*head_ptr = node;
	else
	{
		char** temp = *head_ptr;
		while (temp[1] != NULL)
			temp = (char**)temp[1];
		temp[1] = (char*)node;
	}
}

bool StrListRemove(char*** my_list, char* str)
{
	if (strcmp((*my_list)[0], str) == 0)
	{
		char** temp = (char**)(*my_list)[1];
		free(my_list[0]);
		*my_list = temp;
		return true;
	}
	char**	first_element = *my_list;
	char**	curr_element = NULL;
	while (*my_list != NULL && my_list[1] != NULL)
	{
		curr_element = *my_list;

		if (strcmp(((char**)(*my_list)[1])[0], str) == 0)
		{
			char** temp = (char**)((char**)(*my_list)[1])[1];
			free((char**)(*my_list)[1]);
			curr_element[1] = (char*)temp;
			*my_list = first_element;
			return true;
		}
		*my_list = (char**)(*my_list)[1];
	}
	return false;
}

void StrListReplaceStrings(char** my_list, char* str, char* new_str)
{
	if (str == NULL || new_str == NULL) return;
	char* before = StrElementOf(my_list, str);
	while (my_list != NULL)
	{
		if (strcmp(my_list[0], before) == 0)
			my_list[0] = new_str;
		my_list = (char**)my_list[1];
	}
}

char* StrElementOf(char** last_elem, char* str)
{
	while (last_elem != NULL)
	{
		if (strstr(last_elem[0], str) != NULL)
			return last_elem[0];
		last_elem = (char**)last_elem[1];
	}
	return NULL;
}

void StrListSort(char** my_list)
{
	if (my_list == NULL) return;
	char**	last_element = NULL;
	char**	curr_element = NULL;
	char**	next_element = NULL;
	while ((char**)my_list[1] != last_element)
	{
		curr_element = my_list;
		while ((char**)curr_element[1] != last_element)
		{
			next_element = (char**)curr_element[1];
			if (strlen(curr_element[0]) > strlen(next_element[0]))
			{
				char* temp = next_element[0];
				next_element[0] = curr_element[0];
				curr_element[0] = temp;
			}
			curr_element = next_element;
		}
		last_element = curr_element;
	}
}

void StrListRemoveDuplicates(char** my_list)
{
	char**  first_element = my_list;

	while (my_list != NULL && my_list[1] != NULL)
	{
		char**	curr_element = my_list;
		char**	next_element = (char**)my_list[1];

		if (strcmp(my_list[0], next_element[0]) == 0)
		{
			char** temp = (char**)next_element[1];

			free(next_element);
			curr_element[1] = (char*)temp;
			my_list = first_element;
		}
		else if (strcmp(curr_element[0], next_element[0]) != 0)
		{
			my_list = (char**)my_list[1];
		}
	}
}
