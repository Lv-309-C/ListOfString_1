#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Верхний колонтитул.h"
unsigned counter = 0;
bool initlist = false;

void StringListInit(char **list){
	if (initlist == false){
		
		list = NULL;
		initlist = true;
	}
	else{
		printf("     Your List is already initialised.");
	}
	
}

void StringListAdd(char **list, char *str)
{

	if (counter % 9 == 0){
		list = (char**)realloc(list, (counter + 9) * sizeof(char*));
	}

	int length = strlen(str);
	list[counter] = (char*)malloc(length + 1);
	strcpy(list[counter], str);

	counter++;
}

void ShowList(char **list){
	printf(" \n");
	if (counter == 0){
		printf("     List is empty");
	}
	else{
		for (int i = 0; i < counter; i++) {
			printf("     %i. %s\n", (i + 1), list[i]);
		}
	}
}

void RemoveString(char **list){
	int number = 0;
	printf(" \n");
	ShowList(list);
	printf(" \n");

	printf("     What number of string do you want remove ? - ");
	scanf("%i", &number);

	if (number > counter || number <= 0){
		printf("     Sorry you entered incorrect value. Try again. \n");
	}
	else{
		if (number == counter){
			free(list[counter - 1]);
			counter--;
		}
		else{
			for (int i = number - 1; i < counter - 1; i++){
				list[i] = (char*)realloc(list[i], strlen(list[i + 1] + 1));
				strcpy(list[i], list[i + 1]);
			}
			free(list[counter - 1]);
			counter--;
		}
	}

}

void NumberOfItems(){
	printf(" \n");
	printf("     Number of items - %i\n", counter);
}

void StringListDestroy(char** list){

	for (int i = 0; i < counter; i++) {
		free(list[i]);
	}
	//free(list);
}

int FirstMatch(char **list, char *str)
{	
	unsigned lengthWord;
	unsigned lengthString;
	int line = 0;
	int matchCount = 0;
	bool flag = 0;

	lengthWord = strlen(str);
	
	for (int i = 0; i < counter; i++){
		lengthString = strlen(list[i]);
		if (lengthWord > lengthString){
			continue;
		}
		for (int k = 0; k <= (lengthString - lengthWord); k++){
			for (int h = 0; h < lengthWord; h++){
				if (str[h] == list[i][k + h]){
					matchCount++;
				}
				else{
					break;
				}
			}
		if (matchCount == lengthWord){
			flag = 1;
		}
		matchCount = 0;
		if (flag == 1){
			break;
		}
		}
	if (flag == 1){
		line = i;
		break;
	}
	}

	if (flag == 1){
		return line;
	}
	else{
		return -1;
	}

}

void SortList(char **list)
{
	char *temp = NULL;
	
	printf(" \n");

	if (counter == 0){
		printf("     List is empty.\n");
	}
	else if (counter == 1){
		printf("     Your List has only one string.\n");
	}
	else{
		for (int i = 0; i < counter - 1; i++){
			for (int k = i + 1; k < counter; k++){
				if (strcmp(list[i], list[k]) >= 0){
					temp = list[i];
					list[i] = list[k];
					list[k] = temp;
				}
			}
		}
	}

}



void Menu(char **list){
	int choice = 0;

	do{
		printf(" \n");
		printf("     Initial List  - 1        Number of items - 6 \n");
		printf(" \n");
		printf("     Add string    - 2        Sort list       - 7 \n");
		printf(" \n");
		printf("     Remove string - 3        Replace         - 8 \n");
		printf(" \n");
		printf("     First match   - 4        Destroy List    - 9 \n");
		printf(" \n");
		printf("     Show list     - 5             Quit       - 0 \n");
		printf(" \n");
		printf("     Your choice - ");

		scanf("%i", &choice);
		
			switch (choice)
			{
			case 1:
			{
				StringListInit(list);
				break;
			}
			case 2:
			{
				char buffer[128];
				printf(" \n");
				printf("     Enter your string:  ");
				gets(buffer);
				gets(buffer);
				StringListAdd(list, buffer);
				break;
			}
			case 3:
			{
				RemoveString(list);
				break;
			}
			case 4:
			{
				char buffer[128];
				int index = 0;
				printf(" \n");
				printf("     Enter your string:  ");
				gets(buffer);
				gets(buffer);
				index = FirstMatch(list, buffer);
				if (index == -1){
					printf("     There is not any match in that list.");
				}
				else{
					printf("     First exact match is in line number - %i. \n", (index + 1));
					printf("     %i. %s", (index + 1), list[index]);
				}
				printf(" \n\n");
				system("pause");
				break;
			}
			case 5:
			{
				ShowList(list);
				printf(" \n\n");
				system("pause");
				break;
			}
			case 6:
			{
				NumberOfItems();
				printf(" \n\n");
				system("pause");
				break;
			}
			case 7:
			{
				SortList(list);
				break;
			}
			case 8:
			{

			}
			case 9:
			{
				StringListDestroy(list);
				counter = 0;
				initlist = false;
				break;
			}
			case 0:
				break;

			default:

				printf("\n     You entered incorrect value. Please try again.\n\n");
				system("pause");
				break;
			}
		

		system("cls");
	} while (choice != 0);

}

int main(void)
{
	char **list;
	list = (char**)malloc(10*sizeof(char*));

	Menu(list);

	system("pause");
	return 0;
}
