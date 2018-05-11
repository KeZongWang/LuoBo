//
//  UIMenu.cpp
//  DefendRadish
//
//  Created by mac on 18/5/11.
//
//

#include "UIMenu.hpp"
#include "SceneManage.hpp"

#include "CocoStudio.h"
#include "Constant.h"
#include "GameScene.hpp"
#include "UIManager.hpp"

using namespace cocos2d;



void UIMenu::onCreate()
{
    this->loadCSB();
    this->registerAllCallBacks();
}

void UIMenu::loadCSB()
{
//    layer = Layer::create();
    FileUtils::getInstance()->addSearchPath("Studio");
    auto Layercsb = CSLoader::createNode("Studio/Layer3.csb");
    CCLOG("111");
    this->addChild(Layercsb);
    auto layout = static_cast<ui::Layout*>(Layercsb->getChildByName("Layout"));
    layout->setTouchEnabled(true);
    layout->setSwallowTouches(true);
    
    auto Image_3 = static_cast<ui::ImageView*>(Layercsb->getChildByName("Image_3"));
    Btncontinue = static_cast<ui::Button* >(Image_3 ->getChildByName("continue"));
    Btnbegin = static_cast<ui::Button* >(Image_3->getChildByName("begin"));
    
    Btnchoose = static_cast<ui::Button* >(Image_3->getChildByName("choose"));
}

void UIMenu::registerAllCallBacks()//给button设置回调函数；
{
    Btncontinue->addClickEventListener(CC_CALLBACK_1(UIMenu::BtncontinueCallBack,this));
    Btnbegin->addClickEventListener(CC_CALLBACK_1(UIMenu::BtnbeginCallBack,this));
    
   Btnchoose->addClickEventListener(CC_CALLBACK_1(UIMenu::BtnchooseCallBack,this));
}
//各button的回调
void UIMenu::BtncontinueCallBack(cocos2d::Ref* sender)
{
     UIManager::DestroyLayer();
     Director::getInstance()->resume();//继续；
}

void UIMenu::BtnbeginCallBack(cocos2d::Ref* sender)
{
//     UIManager::DestroyLayer();
     Director::getInstance()->resume();//继续；
     SceneManage::gotoGameScene();

}

void UIMenu::BtnchooseCallBack(cocos2d::Ref* sender)
{
     UIManager::DestroyLayer();
     Director::getInstance()->resume();//继续；
     SceneManage::gotoRadishTestScene();

}





void UIMenu::onActive()
{
    CCLOG("激活 －－> 准备刷新UI");
}

void UIMenu::onDestroy()
{
    CCLOG("销毁 －－> 准备保存各种设置");
}







