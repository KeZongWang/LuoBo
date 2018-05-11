//
//  SceneManage.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//
#include "RadishTest.hpp"
#include "BScene.hpp"
#include "CScene.hpp"
#include "SceneManage.hpp"
#include "SelectScene.hpp"
#include "DScene.hpp"
#include "GameScene.hpp"
#include "ProgressScene.hpp"


using namespace cocos2d;


void SceneManage::gotoProgressScene()
{
    auto scene1= ProgressScene::createScene();
    Director::getInstance()->replaceScene(scene1);

}
void SceneManage::gotoSelectScene()
{
    auto scene1= SelectScene::createScene();
    Director::getInstance()->replaceScene(scene1);

}

void SceneManage::gotoBScene()
{
    auto scene1= BScene::createScene();
    Director::getInstance()->replaceScene(scene1);
    
}

void SceneManage::gotoCScene()
{
    auto scene1= CScene::createScene();
    Director::getInstance()->replaceScene(scene1);
    
}

void SceneManage::gotoRadishTestScene()
{
    auto scene= RadishTest::createScene();
    Director::getInstance()->replaceScene(scene);
}

void SceneManage::gotoDScene()
{
    auto scene= DScene::createScene();
    Director::getInstance()->replaceScene(scene);
}

void SceneManage::gotoGameScene()
{
    auto scene= GameScene::createScene();
    Director::getInstance()->replaceScene(scene);
}





