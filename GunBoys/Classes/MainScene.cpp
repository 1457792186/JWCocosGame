//
//  MainScene.cpp
//  GunBoys
//
//  Created by apple on 17/5/18.
//
//

#include <stdio.h>
#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene=Scene::create();
    auto layer=MainScene::create();
    scene->addChild(layer);
    return scene;
}
bool MainScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    //获取整个手机可视屏幕尺寸
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //获取手机可视屏原点的坐标
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //创建一个显示"MyScene"文字的Label
    
    auto label = Label::createWithTTF("MyScene", "fonts/Marker Felt.ttf", 24);
    //设置白色
    label->setColor(Color3B::WHITE);
    // 设置label在屏幕中的显示位置
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    // 把label添加到画面层
    this->addChild(label, 1);
    return true;
}
