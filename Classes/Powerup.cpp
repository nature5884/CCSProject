//■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■.cppファイルの場合
//■○にはクラスの名前が入る。
//■ 例）TitleScene.hをインクルードしている場合
//■     TitleScene::createScene(){ ・・・・・
//■□にはインクルードしたいヘッダーファイルの名前が入る
//■ 例）TitleScene.hを読み込みたい時
//■     #include "TitleScene.h";
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■
#include "Powerup.h";

USING_NS_CC;

Scene* Powerup::createScene() {
	auto scene = Scene::create();
	auto layer = Powerup::create();
	scene->addChild(layer);
	return scene;
}

bool Powerup::init() {
	// レイヤーの初期化がうまくいかなければシーンも初期化しない
	if (!Layer::init()) { return false; }
	// 乱数の初期化
	srand((unsigned)time(NULL));
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//■リスナー登録
	//■ここでタッチ判定などのリスナーを登録する
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Powerup::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Powerup::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Powerup::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//■画面サイズと原点座標を取得
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	//■■■■■■■■■■■■■■■■■■
	//■Updateを実行
	//■これがないとUpdateが実行されない
	this->scheduleUpdate();

	return true;
}

void Powerup::update(float dt) {

}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチした時の処理
bool Powerup::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {
	return true;
}
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチ中の処理
void Powerup::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチを離したときの処理
void Powerup::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}