#include "Utils.h"

USING_NS_CC;

std::map<cocos2d::EventKeyboard::KeyCode, KeyState> KeyStateManager::m_KeyStates;
std::map<cocos2d::EventKeyboard::KeyCode, KeyState> KeyStateManager::m_PrevKeyStates;
std::map<cocos2d::EventKeyboard::KeyCode, KeyState> KeyStateManager::m_FinalKeyStates;

KeyState KeyStateManager::getKeyState(KeyCode keyCode)
{
	return m_FinalKeyStates[(EventKeyboard::KeyCode)keyCode];
}

void KeyStateManager::receiveKeyboardData(cocos2d::Layer* layer)
{
	auto sentinel = KeyStateSentinel::create();

	layer->addChild(sentinel);
}

bool KeyStateSentinel::init()
{
	if (!Node::init())
	{
		return false;
	}

	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(KeyStateSentinel::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(KeyStateSentinel::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);


	for (EventKeyboard::KeyCode i = EventKeyboard::KeyCode::KEY_NONE; i < EventKeyboard::KeyCode::KEY_PLAY; i = (EventKeyboard::KeyCode)((int)i + 1))
	{
		KeyStateManager::m_PrevKeyStates[i] = KS_NONE;
		KeyStateManager::m_KeyStates[i] = KS_NONE;
	}

	this->scheduleUpdate();

	return true;
}

void KeyStateSentinel::update(float dTime)
{
	for (auto state : KeyStateManager::m_KeyStates)
	{
		KeyState prevState = KeyStateManager::m_PrevKeyStates[state.first];
		KeyState nowState = KeyStateManager::m_KeyStates[state.first];

		if (prevState == KS_NONE && nowState == KS_NONE)
		{
			KeyStateManager::m_FinalKeyStates[state.first] = KS_NONE;
		}
		else if (prevState == KS_NONE && nowState == KS_PRESS)
		{
			KeyStateManager::m_FinalKeyStates[state.first] = KS_PRESS;
		}
		else if (prevState == KS_PRESS && nowState == KS_NONE)
		{
			KeyStateManager::m_FinalKeyStates[state.first] = KS_RELEASE;
		}
		else if (prevState == KS_PRESS && nowState == KS_PRESS)
		{
			KeyStateManager::m_FinalKeyStates[state.first] = KS_HOLD;
		}

		KeyStateManager::m_PrevKeyStates[state.first] = state.second;
	}
}

void KeyStateSentinel::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	KeyStateManager::m_KeyStates[keyCode] = KS_PRESS;
}

void KeyStateSentinel::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	KeyStateManager::m_KeyStates[keyCode] = KS_NONE;
}

cocos2d::Animation* UtilFunctions::createAnimation(const char* animationName, int startIdx, size_t frameNum, float delay)
{
	auto animation = Animation::create();
	animation->setDelayPerUnit(delay);

	for (size_t i = 0; i < frameNum; ++i)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format("%s%d.png", animationName, i + startIdx));
		animation->addSpriteFrame(frame);
	}
	return animation;

}
