//
//  DScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#include "DScene.hpp"
#include "ui/cocosGUI.h"
#include "SceneManage.hpp"
using namespace cocos2d;
cocos2d::Scene* DScene::createScene()
{
    auto scene=Scene::create();
    auto layer=DScene::create();
    scene->addChild(layer);
    return scene;
}

bool DScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    this->returnTest();
    return true;
}

void DScene::returnTest()
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







