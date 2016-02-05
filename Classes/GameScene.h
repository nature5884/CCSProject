//■■■■■■■■■■■■■■■■■■■■■■
//■.hファイルの場合
//■○にはファイル名を大文字にしたものが入る
//■ 例）ファイル名がGameScene.hのとき
//■     #ifndef _GAMESCENE_H_
//■     #define _GAMESCENE_H_
//■□にはファイル名が入る
//■ 例）ファイル名がGameScene.hのとき
//■     class GameScene : publi・・・・・
//■     CREATE_FUNC(GameScene);
//■■■■■■■■■■■■■■■■■■■■■■
#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "cocos2d.h"
using namespace std;

USING_NS_CC;

class GameScene : public cocos2d::Layer{
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Vec2 touch;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void update(float dt);
	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	virtual void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	virtual void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

	void pushBtn(Ref *ref);

	CREATE_FUNC(GameScene);
};

#endif
