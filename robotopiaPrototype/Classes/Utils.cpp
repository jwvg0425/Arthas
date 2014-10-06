#include "Utils.h"

USING_NS_CC;

std::map<cocos2d::EventKeyboard::KeyCode, KeyState> KeyStateManager::m_KeyStates;
std::map<cocos2d::EventKeyboard::KeyCode, KeyState> KeyStateManager::m_PrevKeyStates;
std::map<cocos2d::EventKeyboard::KeyCode, KeyState> KeyStateManager::m_FinalKeyStates;

KeyState KeyStateManager::getKeyboardState(cocos2d::EventKeyboard::KeyCode keyCode)
{
	return m_FinalKeyStates[keyCode];
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
		KeyStateManager::m_PrevKeyStates[i] = NONE;
		KeyStateManager::m_KeyStates[i] = NONE;
	}

	return true;
}

void KeyStateSentinel::update(float dTime)
{
	for (auto state : KeyStateManager::m_KeyStates)
	{
		KeyState prevState = KeyStateManager::m_PrevKeyStates[state.first];
		KeyState nowState = KeyStateManager::m_KeyStates[state.first];

		if (prevState == NONE && nowState == NONE)
		{
			KeyStateManager::m_FinalKeyStates[state.first] = NONE;
		}
		else if (prevState == NONE && nowState == PRESS)
		{
			KeyStateManager::m_FinalKeyStates[state.first] = PRESS;
		}
		else if (prevState == PRESS && nowState == NONE)
		{
			KeyStateManager::m_FinalKeyStates[state.first] = RELEASE;
		}
		else if (prevState == PRESS && nowState == PRESS)
		{
			KeyStateManager::m_FinalKeyStates[state.first] = HOLD;
		}

		KeyStateManager::m_PrevKeyStates[state.first] = state.second;
	}
}

void KeyStateSentinel::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	KeyStateManager::m_KeyStates[keyCode] = PRESS;
}

void KeyStateSentinel::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	KeyStateManager::m_KeyStates[keyCode] = NONE;
}
