#include "HelloWorldScene.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("The Life", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    
    Ant *ant = new Ant(1);
    
    ant->setPosition(Point(ant->getContentSize().width / 2, 0));
    this->addChild(ant);
    
    
    auto size = Director::getInstance()->getVisibleSize();
    
    float nestHeight = size.height;
    float scale = size.width/(float)1242;
    
    auto *pScrollView = ScrollView::create(size);
    pScrollView->setBounceable(false);
    this->addChild(pScrollView);
    
    auto *topSprite = Sprite::create("01_bg-taiwan/bg_home_1.png");
    topSprite->setScale(scale, scale);
    auto topSize = topSprite->getBoundingBox().size;
    
    for(int i=0; i<5; i++) {
        ostringstream oss;
        oss << "01_bg-taiwan/bg_home_" << i+1 << ".png";
        string bgHomeName = oss.str();
        
        auto *sprite = Sprite::create(bgHomeName);
        sprite->setScale(scale, scale);
        sprite->setPosition(Vec2(sprite->getBoundingBox().size.width/2, nestHeight-sprite->getBoundingBox().size.height/2)+Vec2(sprite->getBoundingBox().size.width*i, 0));
        pScrollView->addChild(sprite);
    }
    
    auto *bottomSprite = Sprite::create("01_bg-taiwan/bg_dirt.png");
    bottomSprite->setScale(scale, scale);
    auto bottomSize = bottomSprite->getBoundingBox().size;
    
    for(int i=0; i<5; i++) {
        string bgDirtName = "01_bg-taiwan/bg_dirt.png";
        
        auto *sprite = Sprite::create(bgDirtName);
        sprite->setScale(scale, scale);
        sprite->setPosition(Vec2(sprite->getBoundingBox().size.width/2, nestHeight-topSize.height-sprite->getBoundingBox().size.height/2)+Vec2(sprite->getBoundingBox().size.width*i, 0));
        pScrollView->addChild(sprite);
    }
    //this->addChild(node);
    //スクロールビューに入れるスプライトを用意
    auto *pSprite = Sprite::create("01_bg-taiwan/bg_home_1.png");
    pSprite->setScale(scale, scale);
    //node->setContentSize(Size(pSprite->getBoundingBox().size.width*5, pSprite->getBoundingBox().size.height));
    //pScrollView->setAnchorPoint(Vec2(0.0, 0.0));
    //pScrollView->addChild(node);
    //pScrollView->setContainer(node);
    pScrollView->setContentSize(Size(pSprite->getBoundingBox().size.width*5, nestHeight));
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
