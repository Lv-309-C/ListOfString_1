#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\task_pointers_edited\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Pointers_unit_tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		BEGIN_TEST_METHOD_ATTRIBUTE(StringListInit_pos_test)
			TEST_OWNER(L"Mariia Kopach")
			TEST_PRIORITY(1)
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(StringListInit_pos_test)
		{
			char** list = NULL;

			StringListInit(&list);

			Assert::IsNotNull(list, L"Memory for list should have been allocated.");
		}

		TEST_METHOD(StringListDestroy_pos_test)
		{
			char** list = NULL;

			char str1[] = "This is 1.";
			char str2[] = "I'm the second line.";
			char str3[] = "I'm out! I'm this is";
			char str4[] = "I'm fourth";

			StringListAdd(&list, str1);
			StringListAdd(&list, str2);
			StringListAdd(&list, str3);
			StringListAdd(&list, str4);

			StringListDestroy(&list);

			Assert::IsNull(list, L"List should be deleted and point to NULL.");
		}

		TEST_METHOD(StringListAdd_pos_test)
		{
			char** list = NULL;

			char str1[] = "This is 1.";
			char str2[] = "I'm the second line.";
			char str3[] = "I'm out! I'm this is";
			char str4[] = "I'm fourth";

			StringListAdd(&list, str1);
			StringListAdd(&list, str2);
			StringListAdd(&list, str3);
			StringListAdd(&list, str4);

			int list_size = StringListSize(list);

			Assert::AreEqual(list_size, 4, L"Elements were not added correctly.");
		}
		
		TEST_METHOD(StringListSize_pos_test)
		{
			char** list = NULL;

			char str1[] = "This is 1.";
			char str2[] = "I'm the second line.";
			char str3[] = "I'm out! I'm this is";
			char str4[] = "I'm fourth";

			StringListAdd(&list, str1);
			StringListAdd(&list, str2);
			StringListAdd(&list, str3);
			StringListAdd(&list, str4);

			int list_size = StringListSize(list);

			Assert::AreEqual(list_size, 4, L"List size should be 4.");
		}

		TEST_METHOD(StringListSize_neg_test)
		{
			char** list = NULL;

			char str1[] = "This is 1.";
			char str2[] = "I'm out! I'm this is";

			StringListAdd(&list, str1);
			StringListAdd(&list, str2);

			int list_size = StringListSize(list);

			Assert::AreNotEqual(list_size, 3, L"List size shouldn't be 3.");
		}

		TEST_METHOD(StringListIndexOf_pos_test)
		{
			char** list = NULL;

			char str1[] = "This is 1.";
			char str2[] = "I'm the second line.";
			char str3[] = "I'm out! I'm this is";
			char str4[] = "I'm fourth";

			StringListAdd(&list, str1);
			StringListAdd(&list, str2);
			StringListAdd(&list, str3);
			StringListAdd(&list, str4);

			int result = StringListIndexOf(list, str3);

			Assert::AreEqual(2, result, L"Index should be 2.");
		}

		TEST_METHOD(StringListIndexOf_neg_test)
		{
			char** list = NULL;

			char str1[] = "This is 1.";
			char str2[] = "I'm the second line.";
			char str3[] = "I'm out! I'm this is";
			char str4[] = "I'm fourth";

			StringListAdd(&list, str1);
			StringListAdd(&list, str2);
			StringListAdd(&list, str3);
			StringListAdd(&list, str4);

			int index = StringListIndexOf(list, str3);

			Assert::AreEqual(index, 2, L"Index should be 2.");
		}

		TEST_METHOD(StringListReplaceStrings_pos_test)
		{
			char** list = NULL;

			char str1[] = "I'm the fourth";

			StringListAdd(&list, str1);

			int index = StringListReplaceStrings(list, "I'm the fourth", "qwerty");

			bool flag = false;

			if (strcmp(list[1], "qwerty") != NULL)
				flag = true;

			Assert::IsFalse(flag, L"String was not changed.");
		}

		TEST_METHOD(StringListReplaceInStrings_pos_test)
		{
			char** list = NULL;

			char str1[] = "I'm the second line.";
			char str2[] = "I'm the fourth";

			StringListAdd(&list, str1);
			StringListAdd(&list, str2);

			int index = StringListReplaceInStrings(list, "th", "qwerty");

			bool flag = false;

			if (strstr(list[1], "th"))
				flag = true;

			list = (char**)list[0];

			if (strstr(list[1], "th"))
				flag = true;

			Assert::IsFalse(flag, L"Substring was not changed.");
		}


	};
}