
#include <iostream>

#include "List.h"

void ShowList(char*** list) {

	if (IsEmpty(list)) {
		std::cout << "Empty" << std::endl;
		return;
	}

	size_t i = 0;

	while (list[i] != nullptr) {
		std::cout << *list[i] << " ";
		++i;
	}
	std::cout<<std::endl;
}

int main() {	
	
	char str1[] = "Serhii";
	char str2[] = "Tom";
	char str3[] = "Sem";
	char str4[] = "Bob";
	char str5[] = "All";
	char str6[] = "All";

	char** list = nullptr;

	StringListInit(&list);

	StringListAdd(&list,str1);
	StringListAdd(&list, str2);
	StringListAdd(&list, str2);
	StringListAdd(&list, str2);
	StringListAdd(&list, str3);
	StringListAdd(&list, str4);
	StringListAdd(&list, str5);

	ShowList(&list);	
	std::cout << " Size " << StringListSize(&list) << std::endl << std::endl;

	std::cout << " After Sorting " << std::endl;
	StringListSort(&list);	
	ShowList(&list);

	std::cout << std::endl << " After Removing " << str5 << std::endl;
	StringListRemove(&list, str5);
	ShowList(&list);

	std::cout << std::endl << " After Removing duplicates " << std::endl;
	StringListRemoveDuplicates(&list);
	ShowList(&list);

	char strRep[] = "Replaced";

	std::cout << std::endl << " After Replacing Serhii" << std::endl;
	StringListReplaceInStrings(&list, str1, strRep);
	ShowList(&list);

	StringListDestroy(&list);
	
	std::cout << std::endl;
	std::cin.get();
	return 0;
}