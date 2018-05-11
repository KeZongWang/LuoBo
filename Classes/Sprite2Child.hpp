//
//  Sprite2Child.hpp
//  CarrotFantasy
//
//  Created by MAC on 16/8/12.
//
//

#ifndef Sprite2Child_hpp
#define Sprite2Child_hpp

#include "BasePrite.hpp"
#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
class Sprite2Child:public BasePrite
{
public:
    static Sprite2Child*create(Vec2 pos);
    virtual bool init(Vec2 pos);
    bool isBullet;
    void fireAnimation();
    void upLevel();
    void setLevel(int _level);
    int getLevel();
    Sprite* creatBullet(Vec2 pos);
    int bulltAttack();
    int getBuygold();
    int getupgold();
    
    int getdeletegold();
  
private:
    SpriteFrameCache* spriteFrameCache1;
    int level;
    int attack = 2;
    int buygold = 100;
    int up1gold = 180;
    int up2gold = 250;
    int delete1 = 80;
    int delete2 = 100;
    int delete3 = 150;
};
#endif /* Sprite2Child_hpp */









