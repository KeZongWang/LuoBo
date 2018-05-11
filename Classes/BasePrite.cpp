//
//  BasePrite.cpp
//  defendradish
//
//  Created by mac on 16/8/9.
//
//

#include "BasePrite.hpp"
bool BasePrite::init(string fileName, Vec2 pos)
{
    if (!Sprite::initWithFile(fileName)) {
        return false;
    }
    this->setPosition(pos);

    return true;
}
void BasePrite::removeDid()
{
    this->removeFromParentAndCleanup(true);
}






