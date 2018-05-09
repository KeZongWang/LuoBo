//
//  BScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//
#include "SceneManage.hpp"
#include "BScene.hpp"
#include "ui/cocosGUI.h"
#include "SceneManage.hpp"
using namespace cocos2d;
cocos2d::Scene* BScene::createScene()
{
    auto scene=Scene::create();
    auto layer=BScene::create();
    scene->addChild(layer);
    return scene;
}

bool BScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    this->returnTest();

    return true;
}

void BScene::returnTest()
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






