#pragma once
#include <stdlib.h>
#include <string.h>

void StringListInit(char*** list)
 {
	list = nullptr;
	list = (char***)malloc(2 * sizeof(char**));
	list[0] = nullptr;
}

bool IsEmpty(char*** list)
 {
	if ((list == nullptr) || (*list == nullptr))
		return true;

	return false;
}

size_t StringListSize(char*** list)
{
	if (IsEmpty(list))
		return 0;

	size_t i = 0;
	char** next = *(list);

	while (next != nullptr)
	{
		++i;
		next = *(list + i);
	}
	return i;
}

void StringListDestroy(char*** list)
{
	if (IsEmpty(list))
		return;

	size_t i = 1;
	char** p = nullptr;

	while (*list != nullptr)
	{
		p = *(list + i);
		free(*list);
		*list = p;
		++i;
	}
	*list = nullptr;
}

void StringListAdd(char*** list, const char* str)
{
	if (list == nullptr)
		return;

	if (str == nullptr)
		return;

    size_t size = StringListSize(list);

  	if (size == 0)
  	{
  		*list[0] = (char*)malloc(strlen(str) * sizeof(char));
  		strcpy(*list[0], str);
  		list[1] = nullptr;
  		return;
  	}

  	list[size] = (char**)malloc(1 * sizeof(char*));
  	*list[size] = (char*)malloc(strlen(str) * sizeof(char));
  	strcpy(*list[size], str);
  	list[size+1] = nullptr;
}

size_t StringListIndexOf(char*** list, char* str)
{
	if (IsEmpty(list))
		return 0;

	if (str == nullptr)
		return 0;

	const size_t SIZE = StringListSize(list);

	for (size_t i = 0; i != SIZE; ++i)
	{
		if (strcmp(*list[i], str) == 0)
			return i;
	}

	return SIZE;
}

void StringListSort(char*** list)
{
	if (IsEmpty(list))
		return;

	size_t i = 1, j = 0;
	size_t index = StringListSize(list);

	char** current = *list;
	char** next = *(list + i);

	while (index != 0) {

		while ((j != index) && (next != nullptr))
		{
			if (strcmp(current[0], next[0]) > 0)
			{
				char* tmp = next[0];
				next[0] = current[0];
				current[0] = tmp;
			}
			current = *(list + i);
			next = *(list + i + 1);
			++i;
			++j;
		}

		i = 1;
		j = 0;
		--index;
		current = *list;
		next = *(list + i);
	}
}

bool StringListRemove(char*** list, char* str)
{
	if (IsEmpty(list))
		return false;

	size_t i = 0;
	char** current = *(list + i);
	char** next = *(list + i + 1);

	while (current)
	{
		if (strcmp(current[0], str) == 0)
		{
			free(list[i]);
			while (next) {

				list[i] = next;
				++i;
				next = *(list + i + 1);
			}
			list[i] = nullptr;
			return true;
		}

		++i;
		current = *(list + i);
		next = *(list + i + 1);
	}

	return false;
}

void StringListRemoveDuplicates(char*** list)
{
	if (IsEmpty(list))
		return;

	size_t index_of_deleted_word = 0;
	size_t index_second = 1, index_first = 0;

	char** str_first = *(list + index_first);
	char** str_second = *(list + index_second);
	char** after_second = *(list + index_second + 1);

	char** end = *(list + index_first + 1);

	bool deleted = false;

	while (str_first)
	{
		if (!str_second)
		{

			++index_first;

			index_second = index_first + 1;
			str_first = *(list + index_first);
			str_second = *(list + index_second);
			after_second = *(list + index_second + 1);
			end = *(list + index_first + 1);

			if (end == nullptr)
				return;
		}

		if (strcmp(str_first[0], str_second[0]) == 0)
		{

			free(list[index_second]);
			index_of_deleted_word = index_second;

			while (after_second) {

				list[index_second] = after_second;
				++index_second;
				after_second = *(list + index_second + 1);

			}
			list[index_second] = nullptr;
			deleted = true;
		}

		if (deleted)
		{
			index_second = index_of_deleted_word;
			str_second = *(list + index_second);
			after_second = *(list + index_second + 1);
			deleted = false;

		} else {
				++index_second;
				str_second = *(list + index_second);
				after_second = *(list + index_second + 1);
			}
	}
}

void StringListReplaceInStrings(char*** list, char* before, char* after)
{
	if (IsEmpty(list))
		return;

	if ((before == nullptr) || (after == nullptr))
		return;

	size_t i = 0;
	char** str_current = *(list);

	while (str_current)
	{
		if (strcmp(str_current[0], before) == 0)
		{

			size_t index = StringListIndexOf(list, before);

			*list[index] = after;
		}
		++i;
		str_current = *(list + i);
	}
}

void QuikSortList(char*** list, int left, int right)
 {

	int i = left, j = right;
	char** middle = nullptr;

	middle = list[(i + j) / 2];

	do {
		while (strcmp(*middle, *list[i]) > 0) i++;
		while (strcmp(*middle, *list[j]) < 0) j--;

		if (i <= j)
		{
			char** tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
			i++;
			j--;
		}

	} while (i < j);

	if (i < right) QuikSortList(list, i, right);
	if (j > left) QuikSortList(list, left, j);
}
