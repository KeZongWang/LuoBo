//
//  AScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#include "AScene.hpp"
using namespace cocos2d;
cocos2d::Scene* AScene::createScene()
{
    auto scene=Scene::create();
    auto layer=AScene::create();
    scene->addChild(layer);
    return scene;
}

bool AScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    auto lable = LabelTTF::create("AScene", "AScene", 2);
    lable->setPosition(Vec2(240,180));
    addChild(lable);
    return true;
}