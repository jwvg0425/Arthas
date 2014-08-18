#pragma once

class AEApplication
{
public:
	static AEApplication* GetInstance();
	static void ReleaseInstance();

private:
	AEApplication();
	~AEApplication();

private:
	static AEApplication* m_Instance;
};

