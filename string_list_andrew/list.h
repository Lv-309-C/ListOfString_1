#pragma once
#include <stdlib.h>
#include <string.h>

// I hate comments, so, enjoy =)

typedef char**	list_element;
typedef char*	char_ptr;

void str_list_init(list_element* list)
{
	*list = (list_element)malloc(2 * sizeof(char_ptr));
}

list_element next_element(list_element head)
{
	return (list_element)head[1];
}

list_element last_element(list_element head)
{
	while (true)
	{
		if (head[1] == NULL)
		{
			return head;
		}
		next_element(head);
	}
}

void str_list_destroy(list_element* list)
{
	while (*list != NULL)
	{
		list_element next = next_element(*list);
		free(*list);
		*list = next;
	}
	*list = NULL;
}

size_t str_list_size(list_element head)
{
	size_t counter;
	for (counter = 0U; head != NULL; ++counter)
	{
		head = next_element(head);
	}
	return counter;
}

size_t str_list_index_of(list_element list, char_ptr str)
{
	size_t counter = 0U;
	while (list != NULL)
	{
		if (!strstr(str, list[0]) == NULL)
			return counter;
		++counter;
		list = next_element(list);
	}
}

void str_list_add(list_element* head, char_ptr str)
{
	list_element node;
	str_list_init(&node);
	node[0] = (char_ptr)malloc(sizeof(char));
	strcpy(node[0], str);
	node[1] = NULL;

	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		list_element tmp = *head;
		while (tmp[1] != NULL)
		{
			tmp = next_element(tmp);
		}
		tmp[1] = (char_ptr)node;
	}
}

bool str_list_remove(list_element* head, char_ptr str)
{
	if (strcmp(*head[0], str) == 0)
	{
		list_element temp = next_element(*head);

		free(head[0]);
		*head = temp;

		return true;
	}

	list_element prev_element = *head;
	while (*head != NULL)
	{
		list_element curr = *head;
		if (strcmp(next_element(*head)[0], str) == 0)
		{
			list_element temp = next_element(next_element(*head));

			free(next_element(*head));
			prev_element[1] = (char_ptr)curr;
			next_element(prev_element)[1] = (char_ptr)temp;
			*head = prev_element;

			return true;
		}
		*head = next_element(*head);
	}
	return false;
}

void str_list_sort(list_element list)
{
	if (list == NULL) {
		return;
	}

	list_element tail = NULL, current, next;

	while (next_element(list) != tail) 
	{
		current = list;
		while (next_element(current) != tail) 
		{
			next = next_element(current);
			if (strcmp(current[0], next[0]) >0) 
			{
				char_ptr tmp = next[0];
				next[0] = current[0];
				current[0] = tmp;
			}
			current = next;
		}
		tail = current;
	}
}

void str_list_remove_duplicates(list_element list)
{
	list_element first_element = list;
	while (list != NULL)
	{
		if (strcmp(list[0], next_element(list)[0]) == 0)
		{
			list_element temp = next_element(next_element(list));

			free(next_element(list));
			first_element[1] = (char_ptr)temp;
			list = first_element;
		}
		first_element = list;
		list = next_element(list);
	}
}

void str_list_replace_strings(list_element list, char_ptr before, char_ptr after)
{
	while (list != NULL)
	{	if (str_list_index_of(list, before) > 0)
		{
			// TODO
		}
	}
}