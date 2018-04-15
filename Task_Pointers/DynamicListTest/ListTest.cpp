#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Task_Pointers/HeaderList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicListTest
{		
	TEST_CLASS(ListTest)
	{
	public:
		
		TEST_METHOD(SortTesting)
		{
			char** list = NULL;
			bool sorted = true;

			char* string_one = "Alex";
			char* string_two = "Joy";
			char* string_three = "Alfred";
			char* string_four = "Bob";
			char* string_five = "Jully";

			StringListAdd(&list, string_one);
			StringListAdd(&list, string_two);
			StringListAdd(&list, string_three);
			StringListAdd(&list, string_four);
			StringListAdd(&list, string_five);
			StringListAdd(&list, string_one);
			StringListAdd(&list, string_two);
			StringListAdd(&list, string_three);
			StringListAdd(&list, string_four);
			StringListAdd(&list, string_five);

			StringListQuickSort(list);

			char** temp_list = (char**)list[1];

			while (/*list != NULL &&*/temp_list != NULL)
			{
				if (strcmp(list[0], temp_list[0]) > 0)
					sorted = false;

				list = temp_list;
				temp_list = (char**)temp_list[1];
			}

			Assert::IsTrue(sorted);
		}
	};
}