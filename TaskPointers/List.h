#pragma once
#include <stdlib.h>
#include <string.h>


typedef char** ListElement;
typedef char* ListField;
typedef char* String;

enum NamesOfFields
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


int GetNumberOfElements(ListElement);
int GetIndexOfString(ListElement, String);

void ReplaceStringsInList(ListElement, String, String);

void SortList(ListElement, int(*f)(const void* arg1, const void* arg2));
int Partition(String*, int, int, int(*f)(const void* arg1, const void* arg2));
void QuickSort(String*, int, int, int(*f)(const void* arg1, const void* arg2));
void Swap(void**, void**);

void PrintList(ListElement);

ListElement InitElementOfList()
{
	ListElement element = (ListElement)malloc(3*sizeof(ListField));
	element[Prev] = element[Data] = element[Next] = nullptr;
	return element;
}
void DestroyList(ListElement* head)
{
	if (head == nullptr || *head == nullptr)
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
	if (str == nullptr || head == nullptr)
		return;

	ListElement new_element = InitElementOfList();
	new_element[Data] = (String)malloc(strlen(str) + 1);
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

	while ((ListElement)head[Next] != nullptr)
		head = (ListElement)head[Next];
	return head;
}
void RemoveElement(ListElement* head, ListElement delete_element)
{
	if (head == nullptr || *head == nullptr)
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
	if (head == nullptr || *head == nullptr)
		return false;
	ListElement delete_element = GetElementWithString(*head, str);
	if (delete_element == nullptr)
		return false;
	RemoveElement(head, delete_element);
	return true;
}
void RemoveDublicates(ListElement* head)
{
	if (head == nullptr)
		return;
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
	if (*str == '\0')
		return index;
	ListElement element = head;
	while (element != nullptr) {
		index++;
		if (_strcmpi(element[Data], str) == 0)
			return index;
		element = (ListElement)element[Next];
	}
	return element != nullptr? index : -1;
}
void ReplaceStringsInList(ListElement head, String before, String after)
{
	if (before == nullptr || *before == 0)
		return;
	if (after == nullptr || *after == 0)
		return;

	while (head != nullptr) {
		String sub_string;
		if ((sub_string = strstr(head[Data], before)) != NULL) {
			String buffer = (String)malloc(strlen(head[Data]) + strlen(after));
			
			strcpy(buffer, head[Data]);
			buffer[sub_string - head[Data]] = 0;
			strcat(buffer, after);
			strcat(buffer, sub_string + strlen(before));

			head[Data] = (String)realloc(head[Data], strlen(buffer)+1);
			strcpy(head[Data], buffer);
			free(buffer);
		}
		head = (ListElement)head[Next];
	}
}
int GetStringArray(ListElement head, char*** array)
{
	if (head == nullptr)
		return 0;
	if (*array != nullptr)
		*array = nullptr;
	int k = GetNumberOfElements(head);
	*array = (char**)malloc(k * sizeof(String));
	for (int i = 0; i < k; i++) {
		(*array)[i] = head[Data];
		head = (ListElement)head[Next];
	}
	return k;
}
void PushStringsInList(ListElement head, char*** array, int k)
{
	if (head == nullptr || array == nullptr || *array == nullptr)
		return;
	for (int i = 0; i < k; i++) {
		head[Data] = (*array)[i];
		head = (ListElement)head[Next];
	}
	free(*array);
	*array = nullptr;
	return;
}
int SizeComparator(void const* arg1, void const* arg2)
{
	return strlen((String)arg1) - strlen((String)arg2);
}
int AlphabetComparator(void const* arg1, void const* arg2)
{
	return _strcmpi((String)arg1, (String)arg2);
}
void SortList(ListElement head, int(*Comparator)(const void* arg1, const void* arg2))
{
	if (head == nullptr)
		return;
	String* array_of_string = nullptr;
	int k = GetStringArray(head, &array_of_string);
	QuickSort(array_of_string, 0, k - 1, Comparator);
	PushStringsInList(head, &array_of_string, k);
	return;
}
void QuickSort(String* arr, int p, int q, int(*Comparator)(const void* arg1, const void* arg2))
{
	if (p >= q) return;
	int x = Partition(arr, p, q, Comparator);
	QuickSort(arr, p, x - 1, Comparator);
	QuickSort(arr, x + 1, q, Comparator);
}

int Partition(String* arr, int p, int q, int(*Comparator)(const void* arg1, const void* arg2))
{
	String pivot = arr[q];
	int i = p;
	for (int j = p; j < q; j++)
		if (Comparator(arr[j], pivot) < 0)
			Swap((void**)&arr[i++], (void**)&arr[j]);
	Swap((void**)&arr[i], (void**)&arr[q]);
	return i;
}
void Swap(void** arg1, void** arg2)
{
	void* temp = (String)*arg1;
	*arg1 = *arg2;
	*arg2 = temp;
	return;
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