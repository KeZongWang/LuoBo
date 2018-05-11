//
//  SceneManager.cpp
//  CatchFish
//
//  Created by wangsl on 18/4/10.
//
//

#include "SceneManager.hpp"

#include "GameScene.hpp"
#include "SelectScene.hpp"
USING_NS_CC;

void SceneMannger::goToSelectScene()
{
    auto startscene = SelectScene::createScene();
    Director::getInstance()->replaceScene(startscene);
}
void SceneMannger::goToGameScene()
{
    auto gamescene = GameScene::createScene();
    Director::getInstance()->replaceScene(gamescene);
}