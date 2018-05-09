//
//  CScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#include "CScene.hpp"
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
    auto lable = LabelTTF::create("CScene", "CScene", 2);
    lable->setPosition(Vec2(240,180));
    addChild(lable);
    return true;
}