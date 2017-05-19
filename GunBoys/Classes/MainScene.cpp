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
    
    //载入地图背景
    auto backgroundView = Sprite::create("level_bg_1.png");
    backgroundView->setScale(visibleSize.width/backgroundView->getContentSize().width, visibleSize.height/backgroundView->getContentSize().height);
    backgroundView->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(backgroundView, 0);
    
    //创建一个显示"Defend Kiana"文字的Label
    
    auto label = Label::createWithTTF("Defend Kiana", "fonts/Marker Felt.ttf", 24);
    //设置白色
    label->setColor(Color3B::WHITE);
    // 设置label在屏幕中的显示位置
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    // 把label添加到画面层
    this->addChild(label, 1);
    
//    固定大小
    Size playerSize = Size(60, 60);
    //创建女主角
    auto player = Sprite::create("kiana_X.png");
    player->setScale(playerSize.width/player->getContentSize().width, playerSize.height/player->getContentSize().height);
    player->setPosition(Vec2(visibleSize.width + origin.x - player->getContentSize().width/2 - 5*visibleSize.width/667,
                             origin.y + player->getContentSize().height/2));
    this->addChild(player,1);
    
//    创建对手
    auto empty = Sprite::create("DeRuiSha.png");
    empty->setScale(playerSize.width/empty->getContentSize().width, playerSize.height/empty->getContentSize().height);
    empty->setPosition(Vec2(10 + origin.x, 300 + origin.y));
    this->addChild(empty,3);
    
    return true;
}
