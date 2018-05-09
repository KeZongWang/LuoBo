//
//  SceneManager.cpp
//  CatchFish
//
//  Created by wangsl on 18/4/10.
//
//

#include "SceneManager.hpp"
#include "../Scenes/StartScene.hpp"
USING_NS_CC;
void SceneMannger::goToStartScene()
{
    auto startscene = StartScene::createScene();
    Director::getInstance()->replaceScene(startscene);
}
void SceneMannger::goToGameScene()
{
    /*
    auto gamescene = GameScene::createScene();
    auto scene = TransitionRotoZoom::create(1,gamescene);
    Director::getInstance()->replaceScene(scene);
    */
    
}