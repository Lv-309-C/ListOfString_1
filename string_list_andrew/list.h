#pragma once
#include <stdlib.h>
#include <string.h>

#define DATA(list) (list[0])
#define NEXT(head) ((list_element)head[1])
#define PTR_TO_NEXT(head) (head[1])

typedef char**	list_element;
typedef char*	char_ptr;

void str_list_init(list_element* list)
{
	*list = (list_element)malloc(2 * sizeof(char_ptr));
}

list_element last_element(list_element head)
{
	while (true)
	{
		if (PTR_TO_NEXT(head) == NULL)
		{
			return head;
		}
		NEXT(head);
	}
}

void str_list_destroy(list_element* list)
{
	list_element root = *list;
	while (root != NULL)
	{
		list_element next = NEXT(root);
		free(root);
		root = next;
	}
	*list = NULL;
}

size_t str_list_size(list_element head)
{
	size_t counter;
	for (counter = 0U; head != NULL; ++counter)
	{
		head = NEXT(head);
	}
	return counter;
}

size_t str_list_index_of(list_element list, char_ptr str)
{
	size_t counter = 0U;
	while (list != NULL)
	{
		if (strstr(str, DATA(list)) != NULL)
		{
			++counter;
		}
		list = NEXT(list);
	}
	return counter;
}

void str_list_add(list_element* head, char_ptr str)
{
	list_element node;
	str_list_init(&node);
	DATA(node) = (char_ptr)malloc(sizeof(char));
	strcpy(DATA(node), str);
	PTR_TO_NEXT(node) = NULL;

	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		list_element tmp = *head;
		while (PTR_TO_NEXT(tmp) != NULL)
		{
			tmp = NEXT(tmp);
		}
		PTR_TO_NEXT(tmp) = (char_ptr)node;
	}
}

bool str_list_remove(list_element* head, char_ptr str)
{
	list_element root = *head;

	if (strcmp(DATA(root), str) == 0)
	{
		list_element temp = NEXT(root);

		free(DATA(root));
		root = temp;

		return true;
	}

	list_element prev_element = *head;
	while (root != NULL)
	{
		list_element curr = root;
		if (strcmp(DATA(NEXT(root)), str) == 0)
		{
			list_element temp = NEXT(NEXT(root));

			free(NEXT(root));
			PTR_TO_NEXT(prev_element) = (char_ptr)curr;
			PTR_TO_NEXT(NEXT(prev_element)) = (char_ptr)temp;
			root = prev_element;

			return true;
		}
		root = NEXT(root);
	}
	return false;
}

void str_list_sort(list_element list)
{
	if (list == NULL) 
	{
		return;
	}

	list_element tail = NULL, current, next;

	while (NEXT(list) != tail)
	{
		current = list;
		while (NEXT(current) != tail)
		{
			next = NEXT(current);
			if (strcmp(DATA(current), DATA(next)) < 0)
			{
				char_ptr tmp = DATA(next);
				DATA(next) = DATA(current);
				DATA(current) = tmp;
			}
			current = next;
		}
		tail = current;
	}
}

void str_list_remove_duplicates(list_element list)
{
	list_element first_element = list;
	while (list != NULL && PTR_TO_NEXT(list) != NULL)
	{
		if (strcmp(DATA(list), DATA(NEXT(list))) == 0)
		{
			list_element temp = NEXT(NEXT(list));
			if (temp != NULL)
			{
				free(NEXT(list));
				PTR_TO_NEXT(first_element) = (char_ptr)temp;
				list = first_element;
			}
			else
			{
				free(NEXT(list));
				PTR_TO_NEXT(list) = NULL;
			}
		}
		first_element = list;
		list = NEXT(list);
	}
}

void str_list_replace_strings(list_element list, char_ptr before, char_ptr after)
{
	while (list != NULL)
	{	if (str_list_index_of(list, before) > 0)
		{
			// TODO: ???
		}
	}
}