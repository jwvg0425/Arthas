#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Bullet.h"
#include "Monster.h"

class GameScene : public cocos2d::LayerColor
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	void addBullet(Bullet* bullet);

	void update(float delta);
	void bulletUpdate(float delta);
	void monsterUpdate(float delta);
	
	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

private:
	cocos2d::Vector<Bullet*> bullets;
	cocos2d::Vector<Monster*> monsters;

};

#endif // __HELLOWORLD_SCENE_H__
