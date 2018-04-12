#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

/* Preprocessor block, just comment define */
#define DEBUG

#ifdef DEBUG
#include <stdio.h>

void StringListPrint(list_element head)
{
	printf("display:\n");
	for (size_t i = 0; head != NULL; ++i)
	{
		printf("list[%d] = %s\n", i, &*(DATA(head)));
		head = NEXT(head);
	}
	printf("\n");
}
#endif // DEBUG

int main(void)
{
	list_element str_list = NULL;

	char str1[256];
	char str2[256];
	char str3[256];
	gets(str1);
	gets(str2);
	gets(str3);

	str_list_add(&str_list, str1);
	str_list_add(&str_list, str3);
	str_list_add(&str_list, str2);
	str_list_add(&str_list, str1);
	str_list_add(&str_list, str3);
	str_list_add(&str_list, str3);

#ifdef DEBUG
	StringListPrint(str_list);
#endif // DEBUG

	StringListRemove(&str_list, data1);
	StringListSort(str_list);

#ifdef DEBUG
	StringListPrint(str_list);
#endif // DEBUG

	StringListRemoveDuplicates(str_list);
	char data[] = "hi there";
	StringListReplaceInStrings(&str_list, data1, data);

#ifdef DEBUG
	StringListPrint(str_list);
	printf("List index of: %d\n", StringListIndexOf(str_list, data3));
	printf("List size: %d\n", StringListSize(str_list));
#endif // DEBUG
	StringListDestroy(&str_list);
}