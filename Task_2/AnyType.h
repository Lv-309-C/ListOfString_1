#pragma once
#include<iostream>
#include<string>
#include<exception>
#include<conio.h>

using namespace std;

namespace ISXAnyType
{
	union TypeUnion
	{
		bool	bool_variable;
		char	char_variable;
		int		integer_variable;
		double	double_variable;
	};

	enum class TypeIndex
	{
		UNIDENTIFIED, BOOL, CHAR, INTEGER, DOUBLE
	};

	class AnyType
	{
	public:
		AnyType() {}

		AnyType(bool b_some_value)	{ m_value.bool_variable = b_some_value; m_type_index = TypeIndex::BOOL; }
		AnyType(char ch_some_value)	{ m_value.char_variable = ch_some_value; m_type_index = TypeIndex::CHAR; }
		AnyType(int i_some_value)		{ m_value.integer_variable = i_some_value; m_type_index = TypeIndex::INTEGER; }
		AnyType(double db_some_value) { m_value.double_variable = db_some_value; m_type_index = TypeIndex::DOUBLE; }

		AnyType(const AnyType& other_object) { m_value = other_object.m_value; m_type_index = other_object.m_type_index; }

		~AnyType() {}

		AnyType& operator= (const AnyType& other_object)
		{
			m_value = other_object.m_value;
			m_type_index = other_object.m_type_index;
			return *this;
		}

		void SwapWith(AnyType& first)
		{
			AnyType temp = first;
			first = *this;
			*this = temp;
		}

		string AnyType::GetType()
		{
			switch (m_type_index)
			{
			case TypeIndex::BOOL:		return "bool";
			case TypeIndex::CHAR:		return "char";
			case TypeIndex::INTEGER:	return "integer";
			case TypeIndex::DOUBLE:		return "double";
			default:					return "unidentified type";
			}
		}

		bool AnyType::ToBool() const
		{
			if (TypeIndex::BOOL == m_type_index)
				return m_value.bool_variable;
			else
				throw(bad_cast());
		}

		char AnyType::ToChar() const
		{
			if (TypeIndex::CHAR == m_type_index)
				return m_value.char_variable;
			else
				throw(bad_cast());
		}

		int AnyType::ToInt() const
		{
			if (TypeIndex::INTEGER == m_type_index)
				return m_value.integer_variable;
			else
				throw(bad_cast());
		}

		double AnyType::ToDouble() const
		{
			if (TypeIndex::DOUBLE == m_type_index)
				return m_value.double_variable;
			else
				throw(bad_cast());
		}

	private:
		TypeIndex	m_type_index = TypeIndex::UNIDENTIFIED;
		TypeUnion	m_value = TypeUnion{};
	};


	//template<typename T>
	//TestClass::TestClass(T some_value)
	//{
	//	if (typeid(T) == typeid(bool))
	//		b = some_value;
	//	else if (typeid(T) == typeid(char))
	//		c = some_value;
	//	else if (typeid(T) == typeid(int))
	//		i = some_value;
	//	else if (typeid(T) == typeid(double))
	//		d = some_value;
	//	else
	//		throw(exception("Unknown type"));
	//}
}