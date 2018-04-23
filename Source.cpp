#include <cstdlib>
#include <string.h>
#include <iostream>

#include "Header.h"

using namespace std;

int main() {

	char** list = NULL;

	char str1[] = "This is 1.";
	char str2[] = "I'm the second line.";
	char str3[] = "I'm out! I'm this is";
	char str4[] = "I'm fourth";

	StringListAdd(&list, str1);
	StringListAdd(&list, str2);
	StringListAdd(&list, str3);
	StringListAdd(&list, str4);

	system("pause");
	return 0;
}
