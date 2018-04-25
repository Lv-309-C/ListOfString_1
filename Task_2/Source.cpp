#include"AnyType.h"

using namespace ISXAnyType;

int main()
try {
	AnyType test1 = 5;
	AnyType test2 = 'f';
	AnyType test3(test2);
	AnyType test4;

	test1 = test4 = test2;

	test3 = 5.5;

	test1.SwapWith(test3);

	double d_var = test1.ToDouble();
	char c_var = test2.ToChar();

	cout << test1.GetType() << endl;

	test2 = 4.9;

	int some = test2.ToDouble();

	_getch();
	return 0;
}
catch (const exception& message)
{
	cerr << "Error: " << message.what();
	_getch();
	return -1;
}
catch (...)
{
	cerr << "Unknown error";
	_getch();
	return -2;
}