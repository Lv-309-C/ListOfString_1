#include <stdio.h>
#include "list.h"

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

int main(void)
{

	char data1[] = "str1";
	char data2[] = "str22";
	char data3[] = "str333";


	char str1[256];
	char str2[256];
	char str3[256];
	gets_s(str1);
	gets_s(str2);
	gets_s(str3);

	list_element str_list = NULL;

	str_list_add(&str_list, str1);
	str_list_add(&str_list, str3);
	str_list_add(&str_list, str2);
	str_list_add(&str_list, str1);
	str_list_add(&str_list, str3);
	str_list_add(&str_list, str3);


	//str_list_remove(&str_list, str2);
	str_list_sort(str_list);
	//str_list_remove_duplicates(str_list);

	str_list_print(str_list);

	printf("List index of: %d\n", str_list_index_of(str_list, data2));
	printf("List size: %d\n", str_list_size(str_list));
}