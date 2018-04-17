#include <chrono>
#include "list.h"
#include "MakeRandStr.h"

/* Preprocessor block, just comment define */
#define DEBUG

#ifdef DEBUG
#include <stdio.h>

void StringListPrint(list_element head_ptr)
{
	printf("display:\n");
	for (size_t i = 0; head_ptr != NULL; ++i)
	{
		printf("list[%d] -> %s\n", i, DATA(head_ptr));
		head_ptr = NEXT(head_ptr);
	}
	printf("\n");
}
#endif // DEBUG

void CheckSortingTime(void(*foo)(list_element), list_element list_ptr)
{
	std::chrono::high_resolution_clock::time_point t1, t2;
	t1 = std::chrono::high_resolution_clock::now();
	foo(list_ptr);
	t2 = std::chrono::high_resolution_clock::now();
	__int64 time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	printf("Sorting time: %lldns\n", time);
}

void DoWork()
{
	list_element str_list1 = NULL;
	list_element str_list2 = NULL;
	char data1[256];

	for (size_t i = 0; i < 1000; ++i)
	{
		StringListAdd(&str_list1, MakeString(data1));
		StringListAdd(&str_list2, MakeString(data1));
	}

	CheckSortingTime(StringListQSort, str_list1);
	CheckSortingTime(StringListSort,  str_list2);
}

int main(void)
{
	DoWork();
/*
	auto check = [&](list_element list_ptr, char_ptr str) -> bool
	{
		if (strcmp(DATA(list_ptr), str) == 0)
		{
			return true;
		}
		while (list_ptr != NULL && PTR_TO_NEXT(list_ptr) != NULL)
		{
			if (strcmp(DATA(NEXT(list_ptr)), str) == 0)
			{
				return true;
			}
			list_ptr = NEXT(list_ptr);
		}
		return false;
	};

	list_element str_list = NULL;

	char data1[] = "Hi, im a very long string";
	char data2[] = "String list init";
	char data3[] = "Another long string";

	//char data1[256];
	//char data2[256];
	//char data3[256];
	//gets_s(data1);
	//gets_s(data2);
	//gets_s(data3);

	StringListAdd(&str_list, data1);
	StringListAdd(&str_list, data3);
	StringListAdd(&str_list, data2);
	StringListAdd(&str_list, data3);
	StringListAdd(&str_list, data1);
	StringListAdd(&str_list, data3);
	StringListAdd(&str_list, data2);

#ifdef DEBUG
	StringListPrint(str_list);
#endif // DEBUG

	StringListRemove(&str_list, data1);
	StringListQSort(str_list);
	//StringListSort(str_list);

#ifdef DEBUG
	StringListPrint(str_list);
#endif // DEBUG

	StringListRemoveDuplicates(str_list);
	char data[] = "hi there";
	StringListReplaceInStrings(str_list, data1, data);

#ifdef DEBUG
	StringListPrint(str_list);
	printf("List index of: %d\n", StringListIndexOf(str_list, data3));
	printf("List size: %d\n", StringListSize(str_list));
#endif // DEBUG
	StringListDestroy(&str_list);
*/
}