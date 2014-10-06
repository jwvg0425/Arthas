#pragma once
#include "cocos2d.h"

class WorldScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();  
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	CREATE_FUNC( WorldScene );
};

