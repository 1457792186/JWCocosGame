#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    //.m文件中定义方法需要在.h头文件中进行定义
    static cocos2d::Scene* createScene();

    virtual bool init();//初始化
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);//退出程序
    void menuNextCallBack(cocos2d::Ref * sender);//进入下个场景
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
