//��������������������������������������������
//��.h�t�@�C���̏ꍇ
//�����ɂ̓t�@�C������啶���ɂ������̂�����
//�� ��j�t�@�C������GameScene.h�̂Ƃ�
//��     #ifndef _GAMESCENE_H_
//��     #define _GAMESCENE_H_
//�����ɂ̓t�@�C����������
//�� ��j�t�@�C������GameScene.h�̂Ƃ�
//��     class GameScene : publi�E�E�E�E�E
//��     CREATE_FUNC(GameScene);
//��������������������������������������������
#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_

#include "cocos2d.h"
using namespace std;

USING_NS_CC;

class TitleScene : public cocos2d::Layer{
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

	CREATE_FUNC(TitleScene);
};

#endif
