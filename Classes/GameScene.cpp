//��������������������������������������������������������
//��.cpp�t�@�C���̏ꍇ
//�����ɂ̓N���X�̖��O������B
//�� ��jTitleScene.h���C���N���[�h���Ă���ꍇ
//��     TitleScene::createScene(){ �E�E�E�E�E
//�����ɂ̓C���N���[�h�������w�b�_�[�t�@�C���̖��O������
//�� ��jTitleScene.h��ǂݍ��݂�����
//��     #include "TitleScene.h";
//��������������������������������������������������������
#include "GameScene.h";

USING_NS_CC;

Scene* GameScene::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init() {
	// ���C���[�̏����������܂������Ȃ���΃V�[�������������Ȃ�
	if (!Layer::init()) { return false; }
	// �����̏�����
	srand((unsigned)time(NULL));
	//����������������������������������������������������������������������������������
	//�����X�i�[�o�^
	//�������Ń^�b�`����Ȃǂ̃��X�i�[��o�^����
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//����������������������������������������������������������
	//����ʃT�C�Y�ƌ��_���W���擾
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	//������������������������������������
	//��Update�����s
	//�����ꂪ�Ȃ���Update�����s����Ȃ�
	this->scheduleUpdate();

	//----------------------------------------------------
	// �摜����Sprite�I�u�W�F�N�g���쐬
	auto gz = Sprite::create("gz.png");
	//gz->setScale(0.1f, 0.1f);

	// �\�����W���ʒu���Z�b�g(��ʃT�C�Y��640x1024�̏ꍇ�����ɕ\�������)
	gz->setPosition(Vec2(140 / 2, 1870 / 2));


	// �X�v���C�g���V�[���֓o�^ 
	this->addChild(gz);

//--------------------------------------------------------
	//���{�^��
	//��ʃT�C�Y���擾 
	auto startButton = MenuItemImage::create(
		"left.png",
		"left2.png",
		[](Ref* ref)
		

	{
		//auto scene = GameScene::createScene();
		//auto transition = TransitionFade::create(0.5, scene);
		//	Director::getInstance()->pushScene(transition);
		CCLOG("Left");


	}
	);

	// MenuItem��Menu�ɓo�^
	auto menu = Menu::create(startButton, NULL);
	//pMenu����ʒ����ɔz�u
	this->addChild(menu);
	menu->setPosition(Vec2(240 / 2, 300 / 2));
	
	
	
	//--------------------------------------------------------
	//�E�{�^��
	// MenuItem���쐬
	auto Button = MenuItemImage::create(
		"right.png",
		"right2.png",
		[](Ref* ref)
	{
		//auto scene = GameScene::createScene();
		//auto transition = TransitionFade::create(0.5, scene);
	    //Director::getInstance()->pushScene(transition);
		CCLOG("right");

	}
	);

	// MenuItem��Menu�ɓo�^
	auto m = Menu::create(Button, NULL);

	// Menu���V�[���ɓo�^�i�`��j
	this->addChild(m);
	m->setPosition(Vec2(580 / 2, 300 / 2));




	//--------------------------------------------------------
	//boost�{�^��
	// MenuItem���쐬
	auto boostButton = MenuItemImage::create(
		"boost.png",
		"boost2.png",
		[](Ref* ref)
	{
		//auto scene = GameScene::createScene();
		//auto transition = TransitionFade::create(0.5, scene);
		//	Director::getInstance()->pushScene(transition);
		CCLOG("Boost");

	}
	);

	// MenuItem��Menu�ɓo�^
	auto i = Menu::create(boostButton, NULL);

	// Menu���V�[���ɓo�^�i�`��j
	this->addChild(i);
	i->setPosition(Vec2(980 / 2, 300 / 2));

	

	return true;
}

void GameScene::update(float dt) {

}

//����������������������������������������������������������������������������������������
//���^�b�`�������̏���
bool GameScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {
	
	return true;
}
//����������������������������������������������������������������������������������������
//���^�b�`���̏���
void GameScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}
//����������������������������������������������������������������������������������������
//���^�b�`�𗣂����Ƃ��̏���
void GameScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}