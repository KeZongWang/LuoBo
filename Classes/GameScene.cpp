//
//  GameScene.cpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/9.
//
//

#include "GameScene.hpp"
#include "SceneManager.hpp"
#include "ui/CocosGUI.h"
#include "UIManager.hpp"
USING_NS_CC;
Scene* GameScene::createScene()
{
    return GameScene::create();
}
bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto layer = UIManager::CreateLayer(UIManager::LayerType::GAME1);
    this->addChild(layer);
    
    return true;
}