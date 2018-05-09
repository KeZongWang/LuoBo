//
//  BScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#include "BScene.hpp"
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
    auto lable = LabelTTF::create("BScene", "BScene", 2);
    lable->setPosition(Vec2(240,180));
    addChild(lable);
    return true;
}