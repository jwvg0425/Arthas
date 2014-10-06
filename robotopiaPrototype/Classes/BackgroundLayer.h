#include "cocos2d.h"
#include "Utils.h"

class BackgroundLayer : public cocos2d::Layer
{
public:
	OVERRIDE bool		init();
	cocos2d::Sprite*	getFrontSprite(){return m_FrontSprite;}
	CREATE_FUNC( BackgroundLayer );

private:
	cocos2d::Sprite* m_FrontSprite;
	cocos2d::Sprite* m_BackSprite;
};