//■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■.cppファイルの場合
//■○にはクラスの名前が入る。
//■ 例）TitleScene.hをインクルードしている場合
//■     TitleScene::createScene(){ ・・・・・
//■□にはインクルードしたいヘッダーファイルの名前が入る
//■ 例）TitleScene.hを読み込みたい時
//■     #include "TitleScene.h";
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■
#include "TitleScene.h";

USING_NS_CC;

Scene* TitleScene::createScene() {
	auto scene = Scene::create();
	auto layer = TitleScene::create();
	scene->addChild(layer);
	return scene;
}

bool TitleScene::init() {
	// レイヤーの初期化がうまくいかなければシーンも初期化しない
	if (!Layer::init()) { return false; }
	// 乱数の初期化
	srand((unsigned)time(NULL));
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//■リスナー登録
	//■ここでタッチ判定などのリスナーを登録する
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TitleScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TitleScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//■画面サイズと原点座標を取得
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	//■■■■■■■■■■■■■■■■■■
	//■Updateを実行
	//■これがないとUpdateが実行されない

	// MenuItemをLabelから作成
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

	

	// 画像からSpriteオブジェクトを作成
	auto bgSprite = Sprite::create("background.png");

	// 表示座標を位置をセット(画面サイズが640x1024の場合中央に表示される)
	bgSprite->setPosition(Vec2(640 / 2.0, 1024 / 2.0));

	// スプライトをシーンへ登録 
	this->addChild(bgSprite);

	// 画像からSpriteオブジェクトを作成
	auto bgSpritea = Sprite::create("title.png");

	// 表示座標を位置をセット(画面サイズが640x1024の場合中央に表示される)
	bgSpritea->setPosition(Vec2(visibleSize.width/2.0 , visibleSize.height-300));
	
	// スプライトをシーンへ登録 
	this->addChild(bgSpritea);

	this->scheduleUpdate();



	/*// スタートボタン「Touch Start」がタッチされたら敵を表示
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





	// MenuItemをMenuに登録
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Vec2(300, 300));
	// Menuをシーンに登録（描画）
	this->addChild(menu);
	CCLOG("%i", menu->getPosition().x);




	return true;
}

void TitleScene::update(float dt) {

}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチした時の処理
bool TitleScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {
	return true;
}
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチ中の処理
void TitleScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//■タッチを離したときの処理
void TitleScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {

}