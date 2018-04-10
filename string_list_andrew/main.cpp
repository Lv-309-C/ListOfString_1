#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
/* Preprocessor block, just comment define */
#define DEBUG

#ifdef DEBUG
#include <stdio.h>

void str_list_print(list_element head)
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
	gets_s(str1);
	gets_s(str2);
	gets_s(str3);

	str_list_add(&str_list, str1);
	str_list_add(&str_list, str3);
	str_list_add(&str_list, str2);
	str_list_add(&str_list, str1);
	str_list_add(&str_list, str3);
	str_list_add(&str_list, str3);

#ifdef DEBUG
	str_list_print(str_list);
#endif // DEBUG

	str_list_remove(&str_list, str2);
	str_list_sort(str_list);

#ifdef DEBUG
	str_list_print(str_list);
#endif // DEBUG

	str_list_remove_duplicates(str_list);
	char data2[] = "hi there";
	str_list_replace_strings(str_list, str1, data2);

#ifdef DEBUG
	str_list_print(str_list);
	printf("List index of: %d\n", str_list_index_of(str_list, str3));
	printf("List size: %d\n", str_list_size(str_list));
#endif // DEBUG
	str_list_destroy(&str_list);
}