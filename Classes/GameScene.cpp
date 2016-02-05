//■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■.cppファイルの場合
//■○にはクラスの名前が入る。
//■ 例）TitleScene.hをインクルードしている場合
//■     TitleScene::createScene(){ ・・・・・
//■□にはインクルードしたいヘッダーファイルの名前が入る
//■ 例）TitleScene.hを読み込みたい時
//■     #include "TitleScene.h";
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■
#include "GameScene.h";

USING_NS_CC;

Scene* GameScene::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init() {
	// レイヤーの初期化がうまくいかなければシーンも初期化しない
	if (!Layer::init()) { return false; }
	// 乱数の初期化
	srand((unsigned)time(NULL));
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//■リスナー登録
	//■ここでタッチ判定などのリスナーを登録する
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//■画面サイズと原点座標を取得
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	//■■■■■■■■■■■■■■■■■■
	//■Updateを実行
	//■これがないとUpdateが実行されない
	this->scheduleUpdate();

	//----------------------------------------------------
	// 画像からSpriteオブジェクトを作成
	auto gz = Sprite::create("gz.png");
	//gz->setScale(0.1f, 0.1f);

	// 表示座標を位置をセット(画面サイズが640x1024の場合中央に表示される)
	gz->setPosition(Vec2(140 / 2, 1870 / 2));


	// スプライトをシーンへ登録 
	this->addChild(gz);

//--------------------------------------------------------
	//左ボタン
	//画面サイズを取得 
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

	// MenuItemをMenuに登録
	auto menu = Menu::create(startButton, NULL);
	//pMenuを画面中央に配置
	this->addChild(menu);
	menu->setPosition(Vec2(240 / 2, 300 / 2));
	
	
	
	//--------------------------------------------------------
	//右ボタン
	// MenuItemを作成
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

	// MenuItemをMenuに登録
	auto m = Menu::create(Button, NULL);

	// Menuをシーンに登録（描画）
	this->addChild(m);
	m->setPosition(Vec2(580 / 2, 300 / 2));




	//--------------------------------------------------------
	//boostボタン
	// MenuItemを作成
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

	// MenuItemをMenuに登録
	auto i = Menu::create(boostButton, NULL);

	// Menuをシーンに登録（描画）
	this->addChild(i);
	i->setPosition(Vec2(980 / 2, 300 / 2));

	

	return true;
}

void GameScene::update(float dt) {

}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチした時の処理
bool GameScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {
	
	return true;
}
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチ中の処理
void GameScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチを離したときの処理
void GameScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}