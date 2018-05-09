//
//  SceneManage.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#include "BScene.hpp"
#include "CScene.hpp"
#include "SceneManage.hpp"
#include "SelectScene.hpp"

using namespace cocos2d;
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












