#include <stdio.h>
#include "list.h"

void str_list_print(list_element head)
{
	printf("display:\n");
	for (size_t i = 0; head != NULL; ++i)
	{
		printf("list[%d] = %s\n", i, &*(head[0]));
		head = next_element(head);
	}
	printf("\n");
}


int main(void)
{

	list_element str_list = NULL;

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


	str_list_remove(&str_list, str2);

	//str_list_destroy(&str_list);

	str_list_sort(str_list);
	printf("%d", str_list_index_of(str_list, data2));
	str_list_remove_duplicates(str_list);

	str_list_print(str_list);

}