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
void RemoveElement(ListElement*, ListElement);
bool RemoveStringFromList(ListElement*, String);
void RemoveDublicates(ListElement*);
ListElement GetElementWithString(ListElement, String);
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
void RemoveElement(ListElement* head, ListElement delete_element)
{
	if (*head == nullptr)
		return;
	if (delete_element == nullptr)
		return;
	if (*head == delete_element) {	// at begin of list
		*head = (ListElement)delete_element[Next];
		if (*head != nullptr)
			(*head)[Prev] = nullptr;
		delete_element[Next] = nullptr;
	}
	else if ((ListElement)delete_element[Next] == nullptr) { //at the end of list
		((ListElement)delete_element[Prev])[Next] = nullptr;
		delete_element[Prev] = nullptr;
	}
	else { // in other cases
		((ListElement)delete_element[Prev])[Next] = delete_element[Next];
		((ListElement)delete_element[Next])[Prev] = delete_element[Prev];
		delete_element[Next] = nullptr;
		delete_element[Prev] = nullptr;
	}
	free(delete_element[Data]);
	free(delete_element);
	return;
}
bool RemoveStringFromList(ListElement* head, String str)
{
	if (*head == nullptr)
		return false;
	ListElement delete_element = GetElementWithString(*head, str);
	if (delete_element == nullptr)
		return false;
	RemoveElement(head, delete_element);
	return true;
}
void RemoveDublicates(ListElement* head)
{
	ListElement list = *head;
	ListElement element, next;
	while (list != nullptr) {
		element = (ListElement)list[Next];
		while (element != nullptr) {
			next = (ListElement)element[Next];
			if (_strcmpi(list[Data], element[Data]) == 0)
				RemoveElement(head, element);
			element = next;
		}
		list = (ListElement)list[Next];
	}
	return;
}
ListElement GetElementWithString(ListElement head, String str)
{
	if (str == NULL)
		return nullptr;
	while (head != nullptr) {
		if (_strcmpi(head[Data], str) == 0)
			return head;
		head = (ListElement)head[Next];
	}
	return nullptr;
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
void PrintListReverse(ListElement element)
{
	if (element == nullptr)
		return;
	PrintListReverse((ListElement)element[Next]);
	std::cout << element[Data] << std::endl;
}