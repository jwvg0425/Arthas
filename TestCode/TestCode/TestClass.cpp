#include "TestClass.h"

TestClass::TestClass()
{
}

TestClass::TestClass( std::string str )
{
	m_Str = str;
}


TestClass::~TestClass()
{
}

void TestClass::CustomRender()
{
	printf_s( "%s\n" , m_Str.c_str() );
}

void TestClass::CustomClear()
{
	for( auto& child : m_ChildList )
	{
		delete child;
		child = nullptr;
	}

	m_ChildList.clear();
}

void TestClass::CustomUpdate()
{
	m_Str = m_Str + 'a';
}
