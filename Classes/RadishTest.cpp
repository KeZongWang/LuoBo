//
//  RadishTest.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#include "RadishTest.hpp"
#include "ui/cocosGUI.h"
#include "CocoStudio.h"
#include "Constant.h"
#include "VisibleRect.hpp"
#include "SceneManage.hpp"


using namespace cocos2d;
using namespace ui;
cocos2d::Scene* RadishTest::createScene()
{
    return RadishTest::create();
}


bool RadishTest::init()
{
    if(!Scene::init())
    {
        return false;
        
    }
    FileUtils::getInstance()->addSearchPath("Studio");
    node = CSLoader::createNode(RadishTestCSB);
    this->addChild(node);
    this->SceneTest();
    this-> DirectorScene();
    return true;
}


void RadishTest::SceneTest()
{
    
    
    
    //鸟移动；
    auto Sprite5 = static_cast<Sprite*>(node->getChildByName("daniao"));
    auto moveBy1=MoveBy::create(1, Vec2(0, 40));
    auto moveBy2=MoveBy::create(1, Vec2(0, -40));
    auto sequence=Sequence::create(moveBy1,moveBy2, NULL);
    auto repeat=RepeatForever::create(sequence);
    Sprite5->runAction(repeat);
    //俩叶的旋转；
    auto Sprite3 = static_cast<Sprite*>(node->getChildByName("yezong"));
    auto Sprite6 = static_cast<Sprite*>(node->getChildByName("yeyou"));
    auto scaleBy1=RotateBy::create(1, 15);
    auto scaleBy2=RotateBy::create(1, -15);
    auto delayTime=DelayTime::create(2);
    auto sequence2=Sequence::create(scaleBy1, scaleBy2,delayTime,NULL);
    auto Repeat2=RepeatForever::create(sequence2);
    Sprite3->runAction(Repeat2);
    auto scaleBy3=RotateBy::create(1, 15);
    auto scaleBy4=RotateBy::create(1, -15);
    auto delayTime2=DelayTime::create(2);
    auto sequence3=Sequence::create(delayTime2,scaleBy3,scaleBy4, NULL);
    auto Repeat3=RepeatForever::create(sequence3);
    Sprite6->runAction(Repeat3);
    
    //俩云的移动；
    this->schedule([=](float dt){RadishTest::SayActionTest();},9,kRepeatForever,2, "key");
    removeChild(Sprite1);
    removeChild(Sprite2);
    
    
    
}

void RadishTest::SayActionTest()
{
     FileUtils::getInstance()->addSearchPath("Studio");
    auto ImageView = static_cast<class ImageView*>(node->getChildByName("Image_1"));
    Sprite1 = Sprite::create(RadishTest_SaySprite1);
    Sprite1->setPosition(Vec2(-10,270));
    auto Move1 = MoveBy::create(8, Vec2(600,0));
    Sprite1->runAction(Move1);
    ImageView->addChild(Sprite1);
    Sprite2 = Sprite::create(RadishTest_SaySprite2);
    Sprite2->setPosition(Vec2(-10,300));
    auto Move2 = MoveBy::create(13, Vec2(600,0));
    Sprite2->runAction(Move2);
    ImageView->addChild(Sprite2);
}

void RadishTest::DirectorScene()
{
    auto btn1 = static_cast<ui::Button*>(node->getChildByName("Image_1")->getChildByName("Btnzuo"));
    auto btn2 = static_cast<ui::Button*>(node->getChildByName("Image_1")->getChildByName("Btnzong"));
    auto btn3 = static_cast<ui::Button*>(node->getChildByName("Image_1")->getChildByName("Btnyou"));
    
    btn1->addClickEventListener([=](Ref*Psender)
    {
        CCLOG("btn1");
        
        SceneManage::gotoSelectScene();
    });


    btn2->addClickEventListener([=](Ref*Psender)
    {
        CCLOG("btn2");
        SceneManage::gotoBScene();
        
    });
    
    btn3->addClickEventListener([=](Ref*Psender)
    {
        CCLOG("btn3");
        
        SceneManage::gotoCScene();
    });
    
    auto Btnshe = static_cast<ui::Button*>(node->getChildByName("Image_1")->getChildByName("Btnshe"));
    Btnshe->addClickEventListener([=](Ref*Psender)
    {
        CCLOG("btn3");
        
        SceneManage::gotoDScene();
    });

}




