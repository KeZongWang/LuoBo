//
//  UISelectLayer.cpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/8.
//
//

#include "UISelectLayer.hpp"
#include "CocoStudio.h"
#include "UIManager.hpp"
#include "Constant.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
void UISelectLayer::onCreate()
{
    
    this->loadCSB();
    
}

void UISelectLayer::loadCSB()
{
    FileUtils::getInstance()->addSearchPath("Studio");
    m_node = CSLoader::createNode(SelectLayerCSB);
    this->addChild(m_node);
    m_backbtn = static_cast<ui::Button*>(m_node->getChildByName("backbtn"));
    m_helpbtn = static_cast<ui::Button*>(m_node->getChildByName("helpbtn"));
    this->registerAllCallBacks();
}

void UISelectLayer::registerAllCallBacks()
{
    CCLOG("进入");
    m_backbtn->addClickEventListener(CC_CALLBACK_1(UISelectLayer::backCallBack,this));
    m_helpbtn->addClickEventListener(CC_CALLBACK_1(UISelectLayer::helpCallBack,this));
}

void UISelectLayer::backCallBack(cocos2d::Ref* sender)
{
    CCLOG("点击");
    auto layer = UIManager::CreateLayer(UIManager::LayerType::SETLAYER);
    this->addChild(layer);
}
void UISelectLayer::helpCallBack(cocos2d::Ref* sender)
{
}
void UISelectLayer::onActive()
{
    this->loadCSB();
    CCLOG("激活 －－> 准备刷新UI");
}
void UISelectLayer::onDestroy()
{
    CCLOG("销毁 －－> 准备保存各种设置");
    
}
