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
	void reserveRemoving(Character* character);
   
	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
	
private:
	cocos2d::Vector<Character*> m_Characters;
	cocos2d::Vector<Character*> m_RemovingReservedCharacters;
	float batSpawnTime;
	float batSpawnDelay;
	float ghostSpawnTime;
	float ghostSpawnDelay;

};

#endif // __HELLOWORLD_SCENE_H__

