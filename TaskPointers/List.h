#pragma once
#include <stdlib.h>
#include <string.h>

typedef char** ListElement;
typedef char* ListField;
typedef char* String;

enum NameOfFields
{
	Prev,
	Data,
	Next
};

ListElement InitElementOfList();
void AddStringToList(ListElement*, String);
bool RemoveStringFromList(ListElement, String);
ListElement GetLastElementOfList(ListElement);
void PrintList(ListElement);
int GetNumberOfElements(ListElement);
int GetIndexOfString(ListElement, String);

ListElement InitElementOfList()
{
	ListElement element = (ListElement)malloc(3*sizeof(ListField));
	element[Prev] = element[Data] = element[Next] = nullptr;
	return element;
}
void DestroyList(ListElement* head)
{
	if (*head == nullptr)
		return;
	do {
		*head = (ListElement)(*head)[Next];
		free(((ListElement)(*head)[Prev])[Data]);
		free((ListElement)(*head)[Prev]);
	} while ((ListElement)(*head)[Next] != nullptr);
	free((*head)[Data]);
	free(*head);
	*head = nullptr;

	return;
}
void AddStringToList(ListElement* head, String str)
{
	if (str == nullptr)
		return;

	ListElement new_element = InitElementOfList();
	new_element[Data] = (char*)malloc(strlen(str) + 1);
	strcpy(new_element[Data], str);

	if (*head == nullptr) {
		*head = new_element;
		return;
	}

	ListElement last_element = GetLastElementOfList(*head);
	last_element[Next] = (ListField)new_element;
	new_element[Prev] = (ListField)last_element;
	return;
}
ListElement GetLastElementOfList(ListElement head)
{
	if (head == nullptr)
		return nullptr;
	ListElement element = head;
	while ((ListElement)element[Next] != nullptr)
		element = (ListElement)element[Next];
	return element;
}
bool RemoveStringFromList(ListElement head, String str)
{
	// in progres
}
int GetNumberOfElements(ListElement head)
{
	int count = 0;
	while (head != nullptr) {
		count++;
		head = (ListElement)head[Next];
	}
	return count;
}
int GetIndexOfString(ListElement head, String str)
{
	int index = -1;
	ListElement element = head;
	while (element != nullptr) {
		index++;
		if (_strcmpi(element[Data], str) == 0)
			return index;
		element = (ListElement)element[Next];
	}
	return index;
}
void PrintList(ListElement element)
{
	if (element == nullptr)
		return;
	std::cout << element[Data] << std::endl;
	PrintList((ListElement)element[Next]);
}
