#include "WorldScene.h"

USING_NS_CC;

Scene* WorldScene::createScene()
{
    auto scene = Scene::create();
    
	auto layer = WorldScene::create();

    scene->addChild(layer);

    return scene;
}

bool WorldScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    return true;
}

