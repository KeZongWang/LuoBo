//
//  ProgressScene.cpp
//  DefendRadish
//
//  Created by mac on 18/5/10.
//
//

#include "ProgressScene.hpp"
#include "SceneManage.hpp"
#include "Constant.h"
#include "CocoStudio.h"
#include "ui/cocosGUI.h"
#include "SceneManage.hpp"
using namespace cocos2d;
cocos2d::Scene* ProgressScene::createScene()
{
    
    return ProgressScene::create();
}

bool ProgressScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    size = Director::getInstance()->getVisibleSize();
    layer =Layer::create();
    this->addChild(layer);
    this->beginScene();
//    this->returnTest();
    return true;
}


/*
//    FileUtils::getInstance()->addSearchPath("Studio");
//    node = CSLoader::createNode(ProgressSceneCSB);
//    this->addChild(node);
   //    this->onEnter();
//void ProgressScene::onEnter()
//{
//    auto ImageView = static_cast<ui::ImageView*>(node->getChildByName("Image_2"));
//    auto  sprite1 =static_cast<Sprite*>(ImageView->getChildByName("Sprite_1"));
//    auto Sizesprite1 = sprite1->getContentSize();
//    
//    auto  sprite6 =static_cast<Sprite*>(ImageView->getChildByName("Sprite_2"));
//    auto _rotate=RotateBy::create(4, -360*4);
//    sprite6 ->runAction(_rotate);
    
//    auto NumOne = Sprite::create("countdown_03.png");
//    auto Numtwe = Sprite::create("countdown_02.png");
//    auto NumThree = Sprite::create("countdown_01.png");
//    auto NumGo = Sprite::create("countdown_13.png");
   
  
    
    
    
//}
*/

void ProgressScene::beginScene()
{
    
    
    
    auto backdrop = Sprite::create("Studio/BG1-hd.pvr.png");
    backdrop->setPosition(Vec2(size.width/2, size.height/2));
    layer->addChild(backdrop);
    auto countdown = Sprite::create("countdown_11.png");
    countdown->setPosition(Vec2(size.width/2, size.height/2));
    countdown->setScale(1.2);
    layer->addChild(countdown);
    auto countdown1 = Sprite::create("countdown_12.png");

    countdown1->setPosition(Vec2(size.width/2, size.height/2));
    countdown1->setAnchorPoint(Vec2(1,0.6));
    layer->addChild(countdown1);
    auto _rotate=RotateBy::create(4, -360*4);
    countdown1->runAction(_rotate);
    
    
    
    auto NumOne=Sprite::create("countdown_01.png");
    NumOne->setTag(11);
    layer->addChild(NumOne);
    NumOne->setPosition(Vec2(size.width/2,size.height/2 ));
    auto blink=Blink::create(1, 1);
    auto callFunc=CallFunc::create([=]()
    {
       layer->removeChildByTag(11);
       auto NumTwe=Sprite::create("countdown_02.png");
       layer->addChild(NumTwe);
       NumTwe->setTag(22);
       NumTwe->setPosition(Vec2(size.width/2,size.height/2 ));
       auto blink2=Blink::create(1, 1);
       auto callFunc2=CallFunc::create([=]()
           {
               layer->removeChildByTag(22);
               auto NumThree=Sprite::create("countdown_03.png");
               layer->addChild(NumThree);
               NumThree->setTag(33);
               NumThree->setPosition(Vec2(size.width/2,size.height/2 ));
               auto blink3=Blink::create(1, 1);
               auto callFunc3=CallFunc::create([=]()
               {
                 layer->removeChildByTag(33);
                 auto NumGo=Sprite::create("countdown_13.png");
                 layer->addChild(NumGo);
                 NumGo->setTag(44);
                 NumGo->setPosition(Vec2(size.width/2,size.height/2 ));
                 auto blink4=Blink::create(1, 1);
                 auto callFunc4=CallFunc::create([=]()
                 {
//                   layer->removeFromParentAndCleanup(true);
                   layer->removeChildByTag(44);
                     SceneManage::gotoGameScene();

                 });
                auto sequence4=Sequence::create(blink4,callFunc4, NULL);
               NumGo->runAction(sequence4);
             });
            auto sequence3=Sequence::create(blink3,callFunc3, NULL);
            NumThree->runAction(sequence3);
     });
     auto sequence2=Sequence::create(blink2,callFunc2, NULL);
     NumTwe->runAction(sequence2);
  });
  auto sequence=Sequence::create(blink,callFunc, NULL);
  NumOne->runAction(sequence);
    

    
    
}

void ProgressScene::returnTest()
{
    
    auto button = ui::Button::create();
    button->setTouchEnabled(true);
    button->setTitleText("返回");
    button->setColor(Color3B::RED);
    button->setPosition(Vec2(240,140));
    button->setScale(3);
    button->addClickEventListener([=](Ref* send){
        SceneManage::gotoRadishTestScene();
    });
    layer->addChild(button);
    
    
}
