
//
//  MainScene.h
//  GunBoys
//
//  Created by apple on 17/5/18.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
};

#endif /* MainScene_h */
