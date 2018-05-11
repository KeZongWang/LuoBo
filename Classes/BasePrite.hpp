//
//  BasePrite.hpp
//  defendradish
//
//  Created by mac on 16/8/9.
//
//

#ifndef BasePrite_hpp
#define BasePrite_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "string.h"
using namespace std;
USING_NS_CC;
class BasePrite:public Sprite
{
public:
    virtual bool init(std::string fileName,Vec2 pos);

    void removeDid();
    bool isBullet;
    virtual void fireAnimation() = 0;
    virtual void upLevel() = 0;
    virtual void setLevel(int _level) = 0;
    virtual int getLevel() = 0;
    virtual int bulltAttack() = 0;
    virtual Sprite* creatBullet(Vec2 pos) = 0;
    virtual int getBuygold() = 0;
    virtual int getupgold() = 0;
    virtual int getdeletegold() = 0;
private:
    int level;
    int attack = 2;
};
#endif /* BasePrite_hpp */












