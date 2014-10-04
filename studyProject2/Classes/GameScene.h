#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Character.h"
#define PLAYER_TAG 1
#define EFFECT_MANAGER_TAG 2

class GameScene : public cocos2d::LayerColor
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	void update(float delta);
	void addCharacter(Character* character);
	void addCharacter(Character* character, int zOrder, int tag);
	bool removeCharacter(Character* character);
   
	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
	
private:

	cocos2d::Vector<Character*> m_Characters;
	float mobSpawnTime;
	float mobSpawnDelay;

};

struct CollisionData
{
	Character* character1, *character2;

	CollisionData(Character* char1, Character* char2){ character1 = char1; character2 = char2; }
};


#endif // __HELLOWORLD_SCENE_H__

