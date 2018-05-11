//
//  Sprite1Child.hpp
//  defendradish
//
//  Created by mac on 16/8/9.
//
//

#ifndef Sprite1Child_hpp
#define Sprite1Child_hpp
#include "BasePrite.hpp"
#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class Sprite1Child:public BasePrite
{
public:
    static Sprite1Child*create(Vec2 pos);
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
    int buygold = 120;
    int up1gold = 200;
    int up2gold = 280;
    int delete1 = 80;
    int delete2 = 100;
    int delete3 = 150;
    
};
#endif /* Sprite1Child_hpp */
















