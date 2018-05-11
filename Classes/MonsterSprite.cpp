//
//  MonsterSprite.cpp
//  defendradish
//
//  Created by mac on 16/8/9.
//
//

#include "MonsterSprite.hpp"
bool MonesterSprite::init(string fileName, MonesterID typeID, Vec2 pos,int HP)
{
    if (!Sprite::initWithFile(fileName)) {
        return false;
    }
    this->setPosition(pos);
    typeId=typeID;
    hp=HP;
    return true;
}
void MonesterSprite::removeMonester()
{
    this->removeFromParentAndCleanup(true);
}


































