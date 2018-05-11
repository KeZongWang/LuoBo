//
//  GameScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//
#include "SceneManage.hpp"
#include "ui/cocosGUI.h"
#include "CocoStudio.h"
#include "Constant.h"
#include "GameScene.hpp"
#include "UIManager.hpp"
#include "UIMenu.hpp"



using namespace cocos2d;
cocos2d::Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    layer = Layer::create();
    addChild(layer,1);
    size = Director::getInstance()->getVisibleSize();
    this->onEnter();
    return true;
    
}

void GameScene::onEnter()
{
    Scene::onEnter();
    sprite = Sprite::create("Background/BG1-hd.pvr.png");
    sprite->setPosition(Vec2(size.width/2,size.height/2));
    sprite->setAnchorPoint(Point(0.5,0.5));
    layer->addChild(sprite);
    
    
    _tileMap = TMXTiledMap::create("untitled.tmx");
    _tileMap->setPosition(Vec2(size.width/2+20,size.height/2-50));
    _tileMap->setAnchorPoint(Point(0.5,0.5));
    layer->addChild(_tileMap);
     this-> ParsseMap();
    
    auto sprite1 = Sprite::create("cloud01.png");
    sprite1->setPosition(Vec2(size.width/2-110,size.height/2+50));
    layer->addChild(sprite1);
    
    auto sprite2 = Sprite::create("cloud02.png");
    sprite2->setPosition(Vec2(size.width/2,size.height/2+50));
    layer->addChild(sprite2);
    
    auto sprite3 = Sprite::create("cloud03.png");
    sprite3->setPosition(Vec2(size.width/2+110,size.height/2+50));
    layer->addChild(sprite3);
    
    auto button = ui::Button::create();
    button->setTouchEnabled(true);
    button->setTitleText("返回");
    button->setColor(Color3B::RED);
    button->setPosition(Vec2(size.width/2-200,size.height/2+120));
    button->setScale(3);
    button->addClickEventListener([=](Ref* send){
        SceneManage::gotoRadishTestScene();
    });
    layer->addChild(button);
    
    
    
    auto button1 = ui::Button::create();
    button1->setPosition(Vec2(size.width/2+200,size.height/2+120));
    button1->loadTextures("menu01.png", "menu02.png");
    button1->addClickEventListener(CC_CALLBACK_1(GameScene::CallBackButton1,this));
    layer->addChild(button1);

    
}
 void  GameScene::CallBackButton1(Ref* send)
{
     Director::getInstance()->pause();//让动作停止；
    auto layer1 = UIManager::CreateLayer(UIManager::LayerType::UIMENU);
    this->addChild(layer1,2);
}


void GameScene::SpriteMoveTest()
{
    
    
}

void GameScene::ParsseMap()
{
    
    this->schedule([=](float dt){
    auto heroLayer = _tileMap->getObjectGroup("GameScene1");
    
    auto heroInfo1 = heroLayer->getObject("place1");
    Vec2 p1 (heroInfo1["x"].asFloat(),heroInfo1["y"].asFloat());
    
    auto heroInfo2 = heroLayer->getObject("place2");
    Vec2 p2 (heroInfo2["x"].asFloat(),heroInfo2["y"].asFloat());
    
    auto heroInfo3 = heroLayer->getObject("place3");
    Vec2 p3 (heroInfo3["x"].asFloat(),heroInfo3["y"].asFloat());
    
    auto heroInfo4 = heroLayer->getObject("place4");
    Vec2 p4 (heroInfo4["x"].asFloat(),heroInfo4["y"].asFloat());
    
    auto heroInfo5 = heroLayer->getObject("place5");
    Vec2 p5 (heroInfo5["x"].asFloat(),heroInfo5["y"].asFloat());

    
    auto heroInfo6 = heroLayer->getObject("place6");
    Vec2 p6 (heroInfo6["x"].asFloat(),heroInfo6["y"].asFloat());

    
    auto heroInfo7 = heroLayer->getObject("place7");
    Vec2 p7 (heroInfo7["x"].asFloat(),heroInfo7["y"].asFloat());
    
    auto heroInfo8 = heroLayer->getObject("place8");
    Vec2 p8 (heroInfo8["x"].asFloat(),heroInfo8["y"].asFloat());
    
    auto monster = Sprite::create("bird.png");
    monster->setPosition(p1);
    _tileMap ->addChild(monster);
    auto monsterMoveTo = MoveTo::create(3,p2);
    auto monsterMoveTo1 = MoveTo::create(3,p3);
    auto monsterMoveTo2 = MoveTo::create(1.5,p4);
    auto monsterMoveTo3 = MoveTo::create(3,p5);
    auto monsterMoveTo4 = MoveTo::create(1.5,p6);
    auto monsterMoveTo5 = MoveTo::create(3,p7);
    auto monsterMoveTo6 = MoveTo::create(3,p8);
    auto callFunc = CallFunc::create([=]()
    {
        _tileMap->removeChild(monster);
    });
    auto sqt = Sequence::create(monsterMoveTo ,monsterMoveTo1,monsterMoveTo2,monsterMoveTo3,monsterMoveTo4,monsterMoveTo5,monsterMoveTo6,callFunc, NULL);
   
        auto callFunc1 = CallFunc::create([=](){
            this->radishTest();

        });
        monster->runAction(callFunc1);
      monster->runAction(sqt);
    },0.8,9,0,"move");
}


void GameScene::radishTest()
{
//    1. 将图片加到精灵帧缓存
    spriteFrameCache1 = SpriteFrameCache::getInstance();
    spriteFrameCache1->addSpriteFramesWithFile("Chapter/Items01-hd.plist");
//2. 创建动画帧容器，循环过程中取精灵帧，并且精灵帧制作动画帧，然后放到容器里；
    Vector<AnimationFrame*> animationFrameVector;
    for (int i = 0; i<=8; ++i)
    {
        char str[20];
        sprintf(str, "hlb1%d.png",i);
        auto sprFrame = spriteFrameCache1->getSpriteFrameByName(str);
        auto aniFrame = AnimationFrame::create(sprFrame, 0.1, ValueMap());
       animationFrameVector.pushBack(aniFrame);
    }
//3. 使用动画帧创造动画片；
    auto animation = Animation::create( animationFrameVector,1.0f,CC_REPEAT_FOREVER);
//4. 使用动画片创建可执行的动作
    auto animate = Animate::create(animation);
    this->runAction(animate);
    
//    spriteFrameCache1 = SpriteFrameCache::getInstance();
//    spriteFrameCache1->addSpriteFramesWithFile("Chapter/Items01-hd.plist", "Chapter/Items01-hd.png");
//    //精灵帧缓存
//    Vector<AnimationFrame*> animationFrameVector;
//    for (int i = 0; i <= 8; i++)
//    {
//        std::string str = StringUtils::format("hlb1%d.png",i);
//        auto sprFrame = spriteFrameCache1->getSpriteFrameByName(str);
//        auto aniFrame = AnimationFrame::create(sprFrame, 0.1, ValueMap());
//        animationFrameVector.pushBack(aniFrame);
//    }
//    auto sprFrame = spriteFrameCache1->getSpriteFrameByName("hlb10.png");
//    auto aniFrame = AnimationFrame::create(sprFrame, 0.1, ValueMap());
//    animationFrameVector.pushBack(aniFrame);
//    auto animation = Animation::create(animationFrameVector,0.5,1);
//    auto animate = Animate::create(animation);
//    this->runAction(animate);

}





