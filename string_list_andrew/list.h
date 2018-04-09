#pragma once
#include <stdlib.h>
#include <string.h>

#define DATA(list) (list[0])
#define NEXT(head) ((list_element)(head)[1])
#define PTR_TO_NEXT(head) (head[1])

typedef char**	list_element;
typedef char*	char_ptr;

void str_list_init(list_element* list)
{
	*list = (list_element)malloc(2 * sizeof(char_ptr));
}

void str_list_destroy(list_element* list)
{
	while (*list != NULL)
	{
		list_element next = NEXT(*list);
		free(*list);
		*list = next;
	}
	*list = NULL;
}

size_t str_list_size(list_element head)
{
	size_t	counter	= 0U;
	for (; head != NULL; ++counter)
	{
		head = NEXT(head);
	}
	return counter;
}

size_t str_list_index_of(list_element head, char_ptr str)
{
	size_t counter = 0U;
	while (head != NULL)
	{
		if (strstr(str, DATA(head)) != NULL)
		{
			++counter;
		}
		head = NEXT(head);
	}
	return counter;
}

list_element str_element_of(list_element head, char_ptr str)
{
	while (head != NULL)
	{
		if (strstr(DATA(head), str) != NULL)
		{
			return head;
		}
		head = NEXT(head);
	}
	return NULL;
}

void str_list_add(list_element* head_ptr, char_ptr str)
{
	list_element node = NULL;

	str_list_init(&node);
	DATA(node) = (char_ptr)malloc(strlen(str));
	strcpy(DATA(node), str);
	PTR_TO_NEXT(node) = NULL;

	if (*head_ptr == NULL)
	{
		*head_ptr = node;
	}
	else
	{
		list_element temp = *head_ptr;
		while (PTR_TO_NEXT(temp) != NULL)
		{
			temp = NEXT(temp);
		}
		PTR_TO_NEXT(temp) = (char_ptr)node;
	}
}

bool str_list_remove(list_element* head_ptr, char_ptr str)
{
	if (strcmp(DATA(*head_ptr), str) == 0)
	{
		list_element temp = NEXT(*head_ptr);

		free(DATA(head_ptr));
		*head_ptr = temp;

		return true;
	}

	list_element	first_element	=	*head_ptr;
	list_element	curr_element	=	NULL;

	while (*head_ptr != NULL && PTR_TO_NEXT(head_ptr) != NULL)
	{
		curr_element = *head_ptr;

		if (strcmp(DATA(NEXT(*head_ptr)), str) == 0)
		{
			list_element temp = NEXT(NEXT(*head_ptr));

			free(NEXT(*head_ptr));
			PTR_TO_NEXT(curr_element) = (char_ptr)temp;
			*head_ptr = first_element;

			return true;
		}
		*head_ptr = NEXT(*head_ptr);
	}
	return false;
}

void str_list_sort(list_element list)
{
	if (list == NULL) 
	{
		return;
	}

	list_element	tail		= NULL;
	list_element	current		= NULL;
	list_element	next		= NULL;

	while (NEXT(list) != tail)
	{
		current = list;
		while (NEXT(current) != tail)
		{
			next = NEXT(current);
			if (strlen(DATA(current)) > strlen(DATA(next)))
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
	list_element	first_element	= list;

	while (list != NULL && PTR_TO_NEXT(list) != NULL)
	{
		list_element	curr_element	= list;
		list_element	next_element	= NEXT(list);
		if (strcmp(DATA(list), DATA(next_element)) == 0)
		{
			list_element temp = NEXT(next_element);
			
			free(next_element);
			PTR_TO_NEXT(curr_element) = (char_ptr)temp;
			list = first_element;
		}
		else if (strcmp(DATA(curr_element), DATA(next_element)) != 0)
		{
			list = NEXT(list);
		}
	}
}

void str_list_replace_strings(list_element list, char_ptr before, char_ptr after)
{
	list_element	_before		= NULL;
	list_element	_after		= NULL;

	while (list != NULL)
	{
		_before		=	str_element_of(list, before);
		_after		=	str_element_of(list, after);

		if (_before != NULL && _after != NULL)
		{
			char_ptr tmp = DATA(_before);
			DATA(_before) = DATA(_after);
			DATA(_after) = tmp;
		}
		list = NEXT(list);
	}

}