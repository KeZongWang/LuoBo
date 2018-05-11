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
#include "SceneManager.hpp"
USING_NS_CC;
void UISelectLayer::onCreate()
{
    
    this->loadCSB();
    this->registerAllCallBacks();
    
}

void UISelectLayer::loadCSB()
{
    FileUtils::getInstance()->addSearchPath("Studio");
    m_node = CSLoader::createNode(SelectLayerCSB);
    this->addChild(m_node);
    
    m_backbtn = static_cast<ui::Button*>(m_node->getChildByName("backbtn"));
    m_helpbtn = static_cast<ui::Button*>(m_node->getChildByName("helpbtn"));
    m_startbtn=static_cast<ui::Button*>(m_node->getChildByName("startbtn"));

    m_movenode=static_cast<Node*>(m_node->getChildByName("Movenode"));
    
    this->changeOpacity();
    
    visibleSize = Director::getInstance()->getVisibleSize();
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
void UISelectLayer::partCallBack(cocos2d::Ref* sender)
{
    SceneMannger::goToGameScene();
}

bool UISelectLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
    m_startpoint=touch->getLocation();
    return true;
}

void UISelectLayer::onTouchMoved(Touch *touch, Event *unused_event)
{
    auto point=touch->getPreviousLocation();
    auto point1=touch->getLocation();
    auto m=point1.x-point.x;
    auto post=m_movenode->getPosition();
    m_movenode->setPosition(Vec2(post.x+m,post.y));
}
void UISelectLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
    m_endpoint=touch->getLocation();
    auto m=m_startpoint.x-m_endpoint.x;
    if ( m_endpoint.x < visibleSize.width/2)
    {
        auto post=m_movenode->getPosition();
        CCLOG("postl=%f",post.x);
        if(post.x>-420)
        {
            m_movenode->setPosition(Vec2(post.x-220+m,post.y));
        }
        if(post.x<=-420)
        {
            m_movenode->setPosition(Vec2(-420,160));
        }
    }
    else
    {
        auto post=m_movenode->getPosition();
        CCLOG("postr=%f",post.x);
        if(post.x<240)
        {
            m_movenode->setPosition(Vec2(post.x+220+m,post.y));
        }
        if (post.x>=240)
        {
            m_movenode->setPosition(Vec2(240,160));
        }
    }
    this->changeOpacity();
}

void UISelectLayer::changeOpacity() // 改变按钮背景
{
    for (int i=1;i<5;i++)
    {
        auto btn=static_cast<ui::Button*>(m_movenode->getChildByTag(i));
        auto post=btn->getPosition();
        post=m_movenode->convertToWorldSpace(post);
        CCLOG("post.x=%f",post.x);
        if (post.x<=235||post.x>=245)
        {
            btn->setOpacity(100);
        }
        else
        {
            btn->setOpacity(255);
        }
        
        btn->addClickEventListener(CC_CALLBACK_1(UISelectLayer::partCallBack,this));
    }

}
void UISelectLayer::onActive()
{
    CCLOG("激活 －－> 准备刷新UI");
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(UISelectLayer::onTouchBegan,this);
    touchListener->onTouchMoved = CC_CALLBACK_2(UISelectLayer::onTouchMoved,this);
    touchListener->onTouchEnded = CC_CALLBACK_2(UISelectLayer::onTouchEnded, this);
    touchListener->setSwallowTouches(true);
    //事件监听的注册
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
}
void UISelectLayer::onDestroy()
{
    CCLOG("销毁 －－> 准备保存各种设置");
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    
}
