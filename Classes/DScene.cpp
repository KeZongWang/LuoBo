//
//  DScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#include "DScene.hpp"
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
    auto lable = LabelTTF::create("CScene", "CScene", 2);
    lable->setPosition(Vec2(240,180));
    addChild(lable);
    return true;
}