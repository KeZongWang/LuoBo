//
//  GameScene.hpp
//  DefendRadish
//
<<<<<<< HEAD
//  Created by mac on 18/5/9.
=======
//  Created by  Mac1 on 18/5/9.
>>>>>>> 9c677dd07513d7bbe0175274ae934001a39f46e4
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

<<<<<<< HEAD
#include <stdio.h>
#include "ui/cocosGUI.h"
#include "UIBaseLayer.hpp"
class GameScene:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(GameScene);
    void onEnter()override;
    void SpriteMoveTest();
    void ParsseMap();
    void radishTest();
    void ButtonTest();
    void  CallBackButton1(Ref* send);
private:
    cocos2d::SpriteFrameCache* spriteFrameCache1;

    cocos2d::Sprite* sprite;
    cocos2d::TMXTiledMap* _tileMap;
    cocos2d::Layer* layer;
    cocos2d::Size size;


    
    
    
    
    
    
    
    
};
=======
#include "cocos2d.h"

class GameScene:public cocos2d::Scene
{
public:
    static Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(GameScene);
    
};



>>>>>>> 9c677dd07513d7bbe0175274ae934001a39f46e4
#endif /* GameScene_hpp */
