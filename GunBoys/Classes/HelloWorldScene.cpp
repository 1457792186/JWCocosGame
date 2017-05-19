#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"

USING_NS_CC;

//创建场景
Scene* HelloWorld::createScene()
{
    
    //创建一个自释放的场景对象
    auto scene = Scene::create();
    //创建一个自释放的画面层对象
    auto layer = HelloWorld::create();
    //把创建的画面层添加到场景中
    //一个场景可以添加多个画面层
    scene->addChild(layer);
    //返回这个创建的场景
    return scene;
//    return HelloWorld::create();
}

// 场景初始化方法
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // 1. 首先进行父类初始化
    // 1. super init first
    if ( !Scene::init() )
    {
        //如果初始化父类失败返回false
        return false;
    }
    
    //获取整个手机可视屏幕尺寸
    auto visibleSize = Director::getInstance()->getVisibleSize();
    //获取手机可视屏原点的坐标
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 创建一个带图标的关闭按钮
    // 点击后调用menuCloseCallback方法退出游戏
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    // 设置关闭按钮的显示位置
    // 显示在可视屏幕的右下角
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    
    //创建进入下个视图的按钮
    auto nextItem = MenuItemImage::create("match_renew_uncollect", "match_renew_uncollect", CC_CALLBACK_1(HelloWorld::menuNextCallBack, this));
    nextItem->setPosition(Vec2(origin.x + visibleSize.width/2 - nextItem->getContentSize().width/2,origin.y + nextItem->getContentSize().height/2));
    
   // 创建一个可自释放的菜单
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    //创建一个显示"Defend Kiana"文字的Label
    
    auto label = Label::createWithTTF("Defend Kiana", "fonts/Marker Felt.ttf", 24);
    
    // 设置label在屏幕中的显示位置
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // 把label添加到画面层
    this->addChild(label, 1);

    // 创建一个带图片的精灵
    auto sprite = Sprite::create("HelloWorld.png");

    // 设置图片精灵的显示位置
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // 添加图片精灵到画面层
    this->addChild(sprite, 0);
    
    return true;
}

// 退出按钮事件
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //当是wp8或者winrt平台的时候
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    //结束Director
    Director::getInstance()->end();
    
    //当是ios平台的时候退出
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
}

//进入下个视图
void HelloWorld::menuNextCallBack(Ref * sender){
    //新建MainScene自动释放实例
    auto scene = MainScene::createScene();
    //将MainScene替换当前scene
    Director::getInstance()->replaceScene(scene);
}

