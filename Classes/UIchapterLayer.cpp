//
//  UIchapterLayer.cpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/7.
//
//

#include "UIchapterLayer.hpp"
#include "Constant.h"

#include "UIManager.hpp"
USING_NS_CC;

void UIchapterLayer::onCreate()
{
    this->loadCSB();
    this->registerAllCallBacks();
}

void UIchapterLayer::loadCSB()
{
    FileUtils::getInstance()->addSearchPath("Studio");
    m_node = CSLoader::createNode(chapterLayerCSB);
    this->addChild(m_node);
    m_leftbtn = static_cast<ui::Button*>(m_node->getChildByName("charpterLayer")->getChildByName("leftbtn"));
    m_rightbtn = static_cast<ui::Button*>(m_node->getChildByName("charpterLayer")->getChildByName("rightbtn"));
    m_backbtn = static_cast<ui::Button*>(m_node->getChildByName("charpterLayer")->getChildByName("backbtn"));
    m_helpbtn = static_cast<ui::Button*>(m_node->getChildByName("charpterLayer")->getChildByName("helpbtn"));

    m_pageview=static_cast<ui::PageView*>(m_node->getChildByName("charpterLayer")->getChildByName("PageView"));
   
    auto page = m_pageview->getItem(0);
    auto pointbtn=static_cast<ui::Button*>(page->getChildByTag(7));
    
    pointbtn->addClickEventListener(CC_CALLBACK_1(UIchapterLayer::part1CallBack,this));
                                               

    
}
void UIchapterLayer::registerAllCallBacks()
{
    m_leftbtn->addClickEventListener(CC_CALLBACK_1(UIchapterLayer::leftCallBack,this));
    m_rightbtn->addClickEventListener(CC_CALLBACK_1(UIchapterLayer::rightCallBack,this));
    m_pageview->addEventListener(CC_CALLBACK_2(UIchapterLayer::pageviewCallBack,this));
    m_backbtn->addClickEventListener(CC_CALLBACK_1(UIchapterLayer::backCallBack,this));
    m_helpbtn->addClickEventListener(CC_CALLBACK_1(UIchapterLayer::helpCallBack,this));
   }

void UIchapterLayer::leftCallBack(cocos2d::Ref* sender)
{
    pagenum=m_pageview->getCurPageIndex();
    if (pagenum>0&& pagenum<7)
    {
        pagenum--;
        CCLOG("pagenum=%d",pagenum);
        m_pageview->scrollToItem(pagenum);

    }

}
void UIchapterLayer::rightCallBack(cocos2d::Ref* sender)
{
    pagenum=m_pageview->getCurPageIndex();
    if (pagenum>=0&&pagenum<6)
    {
        pagenum++;
        CCLOG("pagenum=%d",pagenum);
        m_pageview->scrollToItem(pagenum);
    }

}
void UIchapterLayer::pageviewCallBack(cocos2d::Ref* sender, ui::PageView::EventType type)
{
    switch (type)
    {
        case ui::PageView::EventType::TURNING:
        {
            m_pageview=static_cast<ui::PageView*>(m_node->getChildByName("charpterLayer")->getChildByName("PageView"));
            pagenum = m_pageview->getCurPageIndex();
            log("page = %ld",m_pageview->getCurPageIndex());
        }
            break;
        default:
            break;
    }

}
void UIchapterLayer::backCallBack(cocos2d::Ref* sender)
{
}
void UIchapterLayer::helpCallBack(cocos2d::Ref* sender)
{
}
void UIchapterLayer::part1CallBack(cocos2d::Ref* sender)
{
    CCLOG("点击");
    auto layer = UIManager::CreateLayer(UIManager::LayerType::SELECT);
    this->addChild(layer);
}

void UIchapterLayer::onActive()
{
    CCLOG("激活 －－> 准备刷新UI");
     schedule(CC_CALLBACK_1(UIchapterLayer::upDate,this),0.01,CC_REPEAT_FOREVER,0,"upDate");
}
void UIchapterLayer::onDestroy()
{
    CCLOG("销毁 －－> 准备保存各种设置");
    unschedule("upDate");
    
}

void UIchapterLayer::upDate(float dt)
{
    if (pagenum == 0)
    {
        m_leftbtn->setVisible(false);
    }
    else if (pagenum == 5)
    {
        m_rightbtn->setVisible(false);
    }
    else
    {
        m_leftbtn->setVisible(true);
        m_rightbtn->setVisible(true);
    }
    //底部的黑白点
    for (int i = 1; i<=6; i++)
    {
        auto btn =static_cast<ui::Button*>(m_node->getChildByName("charpterLayer")->getChildByTag(i));
        if (i == pagenum + 1)
        {
            btn->setEnabled(false);
        }
        else
        {
            btn->setEnabled(true);
        }
    }
}


