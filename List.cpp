#include <stdlib.h>
#include <string.h>

#include "List.h"

void StringListInit(char*** list)
{
	*list = (char**)malloc(2 * sizeof(char*));
}

void StringListDestroy(char*** list)
{
	if (*list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else 
	{
		char** next_element = NULL;

		while (*list != NULL)
		{
			next_element = (char**)(*list)[1];
			free(*list);
			*list = next_element;
		}

		*list = NULL;
	}
}

void StringListAdd(char*** list, char* str)
{
	char** new_element = NULL;

	StringListInit(&new_element);

	new_element[0] = str;
	new_element[1] = NULL;

	if (*list = NULL)
	{
		*list = new_element;
	}
	else
	{
		while (list != NULL)
		{
			list = (char***)list[1];
		}

		list[1] = (char**)new_element;
	}
}

void StringListRemove(char*** list, char* str)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		char** necessary_element = *list;

		while (necessary_element != NULL && necessary_element[0] != str)
		{
			necessary_element = (char**)necessary_element[1];
		}

		if (necessary_element != NULL)
		{
			if (list[0] == (char**)str)
			{
				*list = (char**)list[1];
				free(list);
			}
			else
			{
				while ((char**)list[1] != necessary_element)
				{
					list = (char***)list[1];
				}

				list[1] = (char**)necessary_element[1];
				free(necessary_element);
			}
		}
		else
		{
			std::cout << "Necessary stuff wasn't finded\n";
		}
	}
}

size_t StringListSize(char** list)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		size_t counter = 0;

		while (list != NULL)
		{
			list = (char**)list[1];
			counter++;
		}

		return counter;
	}
}

size_t StringListIndexOf(char** list, char* str)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		size_t counter = 0;

		while (list != NULL)
		{
			counter++;

			if (strstr(str, list[0]) != NULL)
			{
				return counter;
			}

			list = (char**)list[1];
		}
	}
}

void StringListRemoveDuplicates(char** list)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		char** first_element = list;

		while (list != NULL && list[1] != NULL)
		{
			char** current_element = list;
			char** next_element = (char**)list[1];

			if (strcmp(list[0], next_element[0]) == 0)
			{
				char** temp = (char**)next_element[1];
				free(next_element);
				current_element[1] = (char*)temp;
				list = first_element;
			}
			else if (strcmp(current_element[0], next_element[0]) != 0)
			{
				list = (char**)list[1];
			}
		}
	}
}

void StringListReplaceInStrings(char*** list, char* before, char* after)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		while (list != NULL)
		{
			if (strcmp((char*)list[0], before) == 0)
			{
				list[0] = (char**)after;
			}

			list = (char***)list[1];
		}
	}
}

void StringListSort(char** list)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}

	else
	{
		char** last_element = NULL;
		char** current_element = NULL;
		char** next_element = NULL;

		while ((char**)list[1] != last_element)
		{
			current_element = list;

			while ((char**)current_element[1] != last_element)
			{
				next_element = (char**)current_element[1];

				if (strlen(current_element[0]) > strlen(next_element[0]))
				{
					char* temp = next_element[0];
					next_element[0] = current_element[0];
					current_element[0] = temp;
				}

				current_element = next_element;
			}

			last_element = current_element;
		}
	}
}

void StringListPrint(char** list)
{
	if (list == NULL)
	{
		std::cout << "It is nothing to print\n";
	}
	else
	{
		while (list != NULL)
		{
			std::cout << list[0];
			list = (char**)list[1];
		}

		std::cout << "\n";
	}
}