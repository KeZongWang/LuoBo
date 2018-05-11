//
//  MonsterSprite.hpp
//  defendradish
//
//  Created by mac on 16/8/9.
//
//

#ifndef MonsterSprite_hpp
#define MonsterSprite_hpp
enum MonesterID
{
    Monester1=1,
    Monester2=2,
    Monester3=3
};

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "string.h"
using namespace std;
class MonesterSprite:public Sprite
{
public:
virtual bool init(string fileName,MonesterID typeID,Vec2 pos,int HP);
    CC_SYNTHESIZE(MonesterID, typeId, typeID);
    CC_SYNTHESIZE(int, hp, HP);
    void removeMonester();
};
#endif /* MonsterSprite_hpp */
