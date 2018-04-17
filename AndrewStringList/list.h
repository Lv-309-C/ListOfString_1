#pragma once
#include <stdlib.h>
#include <string.h>

#define DATA(list) (list[0])
#define NEXT(head) ((list_element)(head)[1])
#define PTR_TO_NEXT(head) (head[1])

typedef char**	list_element;
typedef char*	char_ptr;

void StringListInit(list_element* list_ptr)
{
	*list_ptr = (list_element)malloc(2 * sizeof(char_ptr));
}

void swap(list_element first, list_element second)
{
	char_ptr temp  =  DATA(first);
	DATA(first)	   =  DATA(second);
	DATA(second)   =  temp;
}

void CorrectFree(list_element list_ptr)
{
	free(DATA(list_ptr));
	PTR_TO_NEXT(list_ptr) = NULL;
	free(list_ptr);
}

list_element GetStringListTail(list_element head_ptr)
{
	for ( ; head_ptr != NULL && PTR_TO_NEXT(head_ptr) != NULL;
			head_ptr  = NEXT(head_ptr));
	return head_ptr;
}

void StringListDestroy(list_element* list_ptr)
{
	list_element next_element = NULL;
	for ( ; *list_ptr != NULL; *list_ptr = next_element)
	{
		next_element = NEXT(*list_ptr);
		CorrectFree(*list_ptr);
	}
	*list_ptr = NULL;
}

size_t StringListSize(list_element head_ptr)
{
	size_t counter = 0U;
	for ( ; head_ptr != NULL; ++counter)
	{
		head_ptr = NEXT(head_ptr);
	}
	return counter;
}

size_t StringListIndexOf(list_element head_ptr, 
		char_ptr str)
{
	size_t counter = 0U;
	for ( ; head_ptr != NULL; head_ptr = NEXT(head_ptr), 
			++counter)
	{
		if (strcmp(DATA(head_ptr), str) == 0)
		{
			return counter;
		}
	}
	return counter;
}

char_ptr StringListElementOf(list_element head_ptr, 
		char_ptr str)
{
	for ( ; head_ptr != NULL; head_ptr = NEXT(head_ptr))
	{
		if (strcmp(DATA(head_ptr), str) == 0)
		{
			return DATA(head_ptr);
		}
	}
	return NULL;
}

void StringListAdd(list_element* head_ptr, char_ptr str)
{
	if (str == NULL || strlen(str) <= 3)
	{
		return;
	}

	list_element node = NULL;
	StringListInit(&node);
	DATA(node) = (char_ptr)malloc(strlen(str) + 1);
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

bool StingListRemove(list_element* head_ptr, list_element first, 
		char_ptr str)
{
	list_element	curr_element =  *head_ptr;
	list_element	next_element =   NEXT(*head_ptr);

	if (strcmp(DATA(*head_ptr), str) == 0)
	{
		list_element temp = NEXT(next_element);

		CorrectFree(next_element);
		PTR_TO_NEXT(curr_element)	=  (char_ptr)temp;
		*head_ptr					=  first;

		return true;
	}
	return false;
}

bool StringListRemove(list_element* head_ptr, char_ptr str)
{
	if (str == NULL || *str == '\0' || *head_ptr == NULL)
	{
		return false;
	}

	list_element  first_element	 =  *head_ptr;
	list_element  next_element   =   NULL;

	if (strcmp(DATA(*head_ptr), str) == 0)
	{
		next_element = NEXT(*head_ptr);

		CorrectFree(*head_ptr);
		*head_ptr = next_element;

		return true;
	}

	for ( ; PTR_TO_NEXT(*head_ptr) != NULL; *head_ptr = NEXT(*head_ptr))
	{
		if (StingListRemove(head_ptr, first_element, str) == true)
		{
			return true;
		}
	}
	return false;
}

void StringListSort(list_element list_ptr)
{
	if (list_ptr == NULL)
	{
		return;
	}

	list_element	last_element	=  NULL;
	list_element	curr_element	=  NULL;
	list_element	next_element	=  NULL;

	while (NEXT(list_ptr) != last_element)
	{
		curr_element = list_ptr;
		while (NEXT(curr_element) != last_element)
		{
			next_element = NEXT(curr_element);
			if (strlen(DATA(curr_element)) > strlen(DATA(next_element)))
			{
				swap(next_element, curr_element);
			}
			curr_element = next_element;
		}
		last_element = curr_element;
	}
}

list_element ElementPartition(list_element head_ptr, list_element tail_ptr)
{
	list_element q_element		= head_ptr;
	list_element curr_element	= head_ptr;

	while (curr_element != tail_ptr)
	{
		curr_element = NEXT(curr_element);
		if (strlen(DATA(curr_element)) < strlen(DATA(head_ptr)))
		{
			q_element = NEXT(q_element);
			swap(q_element, curr_element);
		}
	}
	swap(head_ptr, q_element);
	return q_element;
}

void StringListQSort(list_element head_ptr, list_element tail_ptr)
{
	if (head_ptr == NULL || head_ptr == tail_ptr)
	{
		return;
	}
	list_element q_element = ElementPartition(head_ptr, tail_ptr);
	
	StringListQSort(head_ptr, q_element);
	if (q_element != tail_ptr)
		StringListQSort(NEXT(q_element), tail_ptr);
}

void StringListQSort(list_element list_ptr)
{
	StringListQSort(list_ptr, GetStringListTail(list_ptr));
}

void StringListRemoveDuplicates(list_element list_ptr)
{
	if (list_ptr == NULL)
	{
		return;
	}

	list_element	first_element	=  list_ptr;
	list_element	next_element	=  NULL;

	for ( ; PTR_TO_NEXT(list_ptr) != NULL; list_ptr = NEXT(list_ptr))
	{
		next_element	=  NEXT(list_ptr);
		StingListRemove(&list_ptr, first_element, DATA(next_element));
	}
}

bool StringListReplaceInStrings(list_element list_ptr, char_ptr before, 
		char_ptr after)
{
	char_ptr _before = StringListElementOf(list_ptr, before);

	if (_before == NULL || *after == '\0' || list_ptr == NULL)
	{
		return false;
	}

	for ( ; PTR_TO_NEXT(list_ptr) != NULL; list_ptr = NEXT(list_ptr))
	{
		if (strcmp(DATA(list_ptr), _before) == 0)
		{
			free(DATA(list_ptr));
			DATA(list_ptr) = (char_ptr)malloc(strlen(after) + 1);
			strcpy(DATA(list_ptr), after);

			return true;
		}
	}
	return false;
}