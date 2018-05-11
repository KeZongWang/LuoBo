//
//  SelectScene.cpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/7.
//
//

#include "SceneManage.hpp"
#include "SelectScene.hpp"
#include "ui/CocosGUI.h"
#include "UIManager.hpp"

using namespace cocos2d;
Scene* SelectScene::createScene()
{
    return SelectScene::create();
}
bool SelectScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    this->initUI();
    
    return true;
}
void SelectScene::onEnter()
{
    Scene::onEnter();
    
}
void SelectScene::onExit()
{
   
    Scene::onExit();
}
void SelectScene::initUI()
{
    //创建已创好图层；
    auto layer = UIManager::CreateLayer(UIManager::LayerType::SETLAYER);
    auto button = ui::Button::create();
    button->setTouchEnabled(true);
    button->setTitleText("返回");
    button->setColor(Color3B::RED);
    button->setPosition(Vec2(240,140));
    button->setScale(3);
    button->addClickEventListener([=](Ref* send){
        SceneManage::gotoRadishTestScene();
    });
    layer ->addChild(button);

    this->addChild(layer);
}
