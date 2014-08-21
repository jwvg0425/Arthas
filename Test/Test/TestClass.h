#pragma once

class TestClass
	:AEObject
{
public:
	TestClass();
	TestClass( std::string str );
	~TestClass();

	void CustomRender();
	void CustomClear();
	void CustomUpdate();

private:
	std::string m_Str;
};

