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
}

void UISelectLayer::selectCallBack(cocos2d::Ref* sender)
{
}

void UISelectLayer::returnCallBack(cocos2d::Ref* sender)
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
