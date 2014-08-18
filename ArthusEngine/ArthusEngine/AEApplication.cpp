#include "AEApplication.h"


AEApplication* AEApplication::m_Instance = nullptr;

AEApplication::AEApplication()
{

}

AEApplication::~AEApplication()
{

}


AEApplication* AEApplication::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new AEApplication();
	}

	return m_Instance;
}

void AEApplication::ReleaseInstance()
{
	if (m_Instance != nullptr)
	{
		delete m_Instance;
		m_Instance = nullptr;
	}
}