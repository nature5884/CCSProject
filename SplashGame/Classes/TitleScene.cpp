//��������������������������������������������������������
//��.cpp�t�@�C���̏ꍇ
//�����ɂ̓N���X�̖��O������B
//�� ��jTitleScene.h���C���N���[�h���Ă���ꍇ
//��     TitleScene::createScene(){ �E�E�E�E�E
//�����ɂ̓C���N���[�h�������w�b�_�[�t�@�C���̖��O������
//�� ��jTitleScene.h��ǂݍ��݂�����
//��     #include "TitleScene.h";
//��������������������������������������������������������
#include "TitleScene.h";

USING_NS_CC;

Scene* TitleScene::createScene() {
	auto scene = Scene::create();
	auto layer = TitleScene::create();
	scene->addChild(layer);
	return scene;
}

bool TitleScene::init() {
	// ���C���[�̏����������܂������Ȃ���΃V�[�������������Ȃ�
	if (!Layer::init()) { return false; }
	// �����̏�����
	srand((unsigned)time(NULL));
	//����������������������������������������������������������������������������������
	//�����X�i�[�o�^
	//�������Ń^�b�`����Ȃǂ̃��X�i�[��o�^����
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TitleScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TitleScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//����������������������������������������������������������
	//����ʃT�C�Y�ƌ��_���W���擾
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	//������������������������������������
	//��Update�����s
	//�����ꂪ�Ȃ���Update�����s����Ȃ�

	// MenuItem��Label����쐬
	auto label2 = Label::create("StartButton", "fonts/arial.ttf", 36);
	//label2->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height/2.0));
	auto startButton = MenuItemLabel::create(
		label2,
		[this](Ref* ref)
	{
		auto scene = TitleScene::createScene();
		auto transition = TransitionFade::create(0.5, scene);
		Director::getInstance()->pushScene(transition);
	}
	);
	label2->setScale(2.0);

	

	// �摜����Sprite�I�u�W�F�N�g���쐬
	auto bgSprite = Sprite::create("background.png");

	// �\�����W���ʒu���Z�b�g(��ʃT�C�Y��640x1024�̏ꍇ�����ɕ\�������)
	bgSprite->setPosition(Vec2(640 / 2.0, 1024 / 2.0));

	// �X�v���C�g���V�[���֓o�^ 
	this->addChild(bgSprite);

	// �摜����Sprite�I�u�W�F�N�g���쐬
	auto bgSpritea = Sprite::create("title.png");

	// �\�����W���ʒu���Z�b�g(��ʃT�C�Y��640x1024�̏ꍇ�����ɕ\�������)
	bgSpritea->setPosition(Vec2(visibleSize.width/2.0 , visibleSize.height-300));
	
	// �X�v���C�g���V�[���֓o�^ 
	this->addChild(bgSpritea);

	this->scheduleUpdate();



	/*// �X�^�[�g�{�^���uTouch Start�v���^�b�`���ꂽ��G��\��
	auto startLabel = Label::create("Touch Start", "fonts/arial.ttf", 36);
	MenuItemLabel* startButton = MenuItemLabel::create(
		startLabel,
		[this](Ref* sender)
	{
		static_cast<MenuItemLabel*>(sender)->setVisible(false);
		//	startFirst();
	}
	);
	startButton->setScale(2.0f);*/





	// MenuItem��Menu�ɓo�^
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Vec2(300, 300));
	// Menu���V�[���ɓo�^�i�`��j
	this->addChild(menu);
	CCLOG("%i", menu->getPosition().x);




	return true;
}

void TitleScene::update(float dt) {

}

//����������������������������������������������������������������������������������������
//���^�b�`�������̏���
bool TitleScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {
	return true;
}
//����������������������������������������������������������������������������������������
//���^�b�`���̏���
void TitleScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}
//����������������������������������������������������������������������������������������
//���^�b�`�𗣂����Ƃ��̏���
void TitleScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}