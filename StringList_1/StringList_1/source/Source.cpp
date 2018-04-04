
#include <cstdlib> // <stdlib>
#include <string.h>

#include <stdio.h>

/*
	It appears warning (scanf is unsafe). it will just take away
	if you declare a macros _CRT_SECURE_NO_WARNINGS
	https://stackoverflow.com/questions/16883037/remove-secure-warnings-crt-secure-no-warnings-from-projects-by-default-in-vis
*/

/*  So, I've decided to implement it based on char*** 
*   as in the interface functions. The thing is, firstly
*   we create and init array 1x1x1, for adding call StringListAdd()
*   it asks about a string in a user, then reallocate appropriate
*   space according to the size (I guess, we sequentially do it)
*   and add it as height. Then we sequentially add rows and colums  
*   if privious space is exhausted (we need to check it) just like simple vector.
*   But the problem is that it isn't looked as linked list, I guess.
*/  

// I gess, It's bad ! 
size_t rows = 1;
size_t colums = 1;
size_t height = 1;

void StringListInit(char***& str) {

	// Create list 1x1x1

	str = (char***)malloc(rows * sizeof(char**));

	for (int i = 0; i < rows; ++i) {
		str[i] = (char**)malloc(colums * sizeof(char*));
		for (int j = 0; j < colums; ++j)
			str[i][j] = (char*)malloc(height * sizeof(char));
	}
}

void StringListAdd(char***& str, FILE* stream = stdin) { 

	printf(" \n (%d Rows x %d Colums) Enter length of string ", rows, colums);
	scanf("%d", &height);

	printf(" \n Enter string ");

	// realloc to add 1 row if it needs
	// if( condition for rows )
	// then allocate plus 1 row or more

	// realloc to add 1 colum if it needs
	// if( condition for colums )
	// then allocate plus 1 colum or more

	// reallocate height dimention
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < colums; ++j) {
			str[i][j] = (char*)realloc(str, height * sizeof(char));
		}

	// remove '\n' character 
	getchar();		

	// problem ! It puts in first colums
	// need to iterate to the next element 
	fgets(str[rows - 1][colums - 1], height, stream); 

	// return height;	// length of string
}

void StringListDestroy(char*** list) {

	// I am not sure if it works propely
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < colums; ++j)
			free(list[i][j]);
		free(list[i]);
	}
	//free(list);

}

void ShowList(char*** list) {
	for (int i = 0; i<rows; ++i)
		for (int j = 0; j<colums; ++j)
			printf(" \n list[%d][%d] - %s",i,j,list[i][j]);
}

int main() {

	char*** list = nullptr;

	StringListInit(list);
	
	// Every time call it add element and iterate to the next elem
	// with dimention changing
	StringListAdd(list); 
	 
	ShowList(list);

	StringListDestroy(list);

	printf("\n");
	system("pause");
	return 0;
}
