//
//  GameScene.hpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

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
#endif /* GameScene_hpp */
