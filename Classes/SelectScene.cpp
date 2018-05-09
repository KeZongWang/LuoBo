//
//  SelectScene.cpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/7.
//
//

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
    auto layer = UIManager::CreateLayer(UIManager::LayerType::SETLAYER);
    this->addChild(layer);
}
