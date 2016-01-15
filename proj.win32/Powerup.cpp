//��������������������������������������������������������
//��.cpp�t�@�C���̏ꍇ
//�����ɂ̓N���X�̖��O������B
//�� ��jTitleScene.h���C���N���[�h���Ă���ꍇ
//��     TitleScene::createScene(){ �E�E�E�E�E
//�����ɂ̓C���N���[�h�������w�b�_�[�t�@�C���̖��O������
//�� ��jTitleScene.h��ǂݍ��݂�����
//��     #include "TitleScene.h";
//��������������������������������������������������������
#include "Powerup.h";

USING_NS_CC;

Scene* Powerup::createScene() {
	auto scene = Scene::create();
	auto layer = Powerup::create();
	scene->addChild(layer);
	return scene;
}

bool Powerup::init() {
	// ���C���[�̏����������܂������Ȃ���΃V�[�������������Ȃ�
	if (!Layer::init()) { return false; }
	// �����̏�����
	srand((unsigned)time(NULL));
	//����������������������������������������������������������������������������������
	//�����X�i�[�o�^
	//�������Ń^�b�`����Ȃǂ̃��X�i�[��o�^����
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Powerup::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Powerup::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Powerup::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//����������������������������������������������������������
	//����ʃT�C�Y�ƌ��_���W���擾
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	//������������������������������������
	//��Update�����s
	//�����ꂪ�Ȃ���Update�����s����Ȃ�
	this->scheduleUpdate();

	return true;
}

void Powerup::update(float dt) {

}

//����������������������������������������������������������������������������������������
//���^�b�`�������̏���
bool Powerup::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {
	return true;
}
//����������������������������������������������������������������������������������������
//���^�b�`���̏���
void Powerup::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}
//����������������������������������������������������������������������������������������
//���^�b�`�𗣂����Ƃ��̏���
void Powerup::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}