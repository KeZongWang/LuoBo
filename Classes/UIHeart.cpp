//
//  UIHeart.cpp
//  DefendRadish
//
//  Created by mac on 18/5/11.
//
//

#include "UIHeart.hpp"
#include "SceneManage.hpp"

#include "CocoStudio.h"
#include "Constant.h"
#include "GameScene.hpp"
#include "UIManager.hpp"
using namespace cocos2d;
void UIHear::onCreate()
{
    this->loadCSB();
    this-> registerAllCallBacks();
}

void UIHear::loadCSB()
{
    //    layer = Layer::create();
    FileUtils::getInstance()->addSearchPath("Studio");
    auto Layercsb5 = CSLoader::createNode("Studio/Layer5.csb");
    CCLOG("111");
    this->addChild(Layercsb5);
    Return = static_cast<ui::Button* >(Layercsb5->getChildByName("Layout5")->getChildByName("Image_5") ->getChildByName("Button_5"));
}

void UIHear::registerAllCallBacks()//给button设置回调函数；
{
   Return->addClickEventListener(CC_CALLBACK_1(UIHear::ReturnCallBack,this));
}
//各button的回调
void UIHear::ReturnCallBack(cocos2d::Ref* sender)
{
    UIManager::DestroyLayer();
    
}






void UIHear::onActive()
{
    CCLOG("激活 －－> 准备刷新UI");
}

void UIHear::onDestroy()
{
    CCLOG("销毁 －－> 准备保存各种设置");
}
