//
//  CScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//
#include "ui/cocosGUI.h"
#include "CScene.hpp"
#include "SceneManage.hpp"
using namespace cocos2d;
cocos2d::Scene* CScene::createScene()
{
    auto scene=Scene::create();
    auto layer=CScene::create();
    scene->addChild(layer);
    return scene;
}

bool CScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    this->returnTest();
    return true;
}

void CScene::returnTest()
{
    
    auto button = ui::Button::create();
    button->setTouchEnabled(true);
    button->setTitleText("返回");
    button->setColor(Color3B::RED);
    button->setPosition(Vec2(240,140));
    button->setScale(3);
    button->addClickEventListener([=](Ref* send){
        SceneManage::gotoRadishTestScene();
    });
    this->addChild(button);
    
    
}
