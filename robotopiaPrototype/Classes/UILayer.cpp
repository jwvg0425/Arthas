#include "UILayer.h"
#include "Utils.h"
#include "GameLayer.h"

USING_NS_CC;

bool UILayer::init()
{
	Size winSize = Director::getInstance()->getWinSize();
	m_WinWidth = winSize.width;
	m_WinHeight = winSize.height;
	
	auto sprHPContainer = Sprite::create("Container_HP.png");
	sprHPContainer->setScale(0.75);
	sprHPContainer->setAnchorPoint(Point(0, 1));
	sprHPContainer->setPosition(Point(20, m_WinHeight - 20));
	this->addChild(sprHPContainer, 10);
	
	auto sprSTEContainer = Sprite::create("Container_STE.png");
	sprSTEContainer->setScale(0.75);
	sprSTEContainer->setAnchorPoint(Point(0, 1));
	sprSTEContainer->setPosition(Point (20, m_WinHeight - 80));
	this->addChild(sprSTEContainer, 10);

	m_Player = nullptr;

	this->scheduleUpdate();
	return true;
}

void UILayer::update(float dTime)
{
	if (m_Player == nullptr)
	{
		auto gameLayer = ((WorldScene*)this->getParent())->getGameLayer();
		m_Player = gameLayer->getPlayer();
	}
	
	int currentHP = m_Player->getHp();
	int maxHP = m_Player->getMaxHp();
	int currentSTE = m_Player->getSteam();
	int maxSTE = m_Player->getMaxSteam();

	if (KeyStateManager::getKeyState(KC_JUMP) == KS_PRESS)
	{
		currentSTE += 2;
	}
	
	int sizeOfSTEs = m_STEs.size();
	if (maxSTE != sizeOfSTEs)
	{	
		m_STEs.clear();
		for (int i = 0; i < maxSTE - sizeOfSTEs; ++i)
		{
			auto sprSTE = Sprite::create("STE_Block.png");
			sprSTE->setScale(0.8);
			sprSTE->setVisible(false);
			sprSTE->setPosition(Point(37 + (17 * i), m_WinHeight - 103));
			m_STEs.pushBack(sprSTE);
			this->addChild(sprSTE);
		}
	}
	int countSTE = 0;
	for (auto sprSTE : m_STEs)
	{
		if (countSTE < currentSTE)
		{
			sprSTE->setVisible(true);
		}
		else
		{
			sprSTE->setVisible(false);
		}
		countSTE++;
	}

	std::string strCurrentHP = std::to_string(currentHP);
	std::string strMaxHP = std::to_string(maxHP);
	std::string strCurrentSTE = std::to_string(currentSTE);
	std::string strMaxSTE = std::to_string(maxSTE);
	
	std::stringstream sumHP;
	sumHP << strCurrentHP << " / " << strMaxHP;
	std::string hpStatus = sumHP.str();

	std::stringstream sumSTE;
	sumSTE << strCurrentSTE << " / " << strMaxSTE;
	std::string steStatus = sumSTE.str();

	auto hpLabel = Label::createWithSystemFont(hpStatus, "Thonburi", 20);
	hpLabel->setPosition(Point(175, m_WinHeight - 45));
	auto steLabel = Label::createWithSystemFont(steStatus, "Thonburi", 20);
	steLabel->setPosition(Point(175, m_WinHeight - 100));

	this->addChild(hpLabel);
	this->addChild(steLabel);

	
}

