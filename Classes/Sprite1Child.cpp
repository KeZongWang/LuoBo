//
//  Sprite1Child.cpp
//  defendradish
//
//  Created by mac on 16/8/9.
//
//

#include "Sprite1Child.hpp"
Sprite1Child* Sprite1Child::create(Vec2 pos)
{
    Sprite1Child *sprite1Child=new Sprite1Child();
    if (sprite1Child&&sprite1Child->init(pos)) {
        sprite1Child->autorelease();
        return sprite1Child;
    }
    CC_SAFE_DELETE(sprite1Child);
    return nullptr;
}
bool Sprite1Child::init(Vec2 pos)
{
    if (!BasePrite::init("Shit11.png", pos)) {
        return false;
    }
    spriteFrameCache1 = SpriteFrameCache::getInstance();
    spriteFrameCache1->addSpriteFramesWithFile("shit.plist", "shit.png");
    this->level = 1;
    isBullet=false;
    return true;
}
void Sprite1Child::fireAnimation()
{
    Vector<AnimationFrame*> animationFrameVector;
    for (int i = 1; i <= 3; i++)
    {
        std::string str = StringUtils::format("Shit%d%d.png",level,i);
        auto sprFrame = spriteFrameCache1->getSpriteFrameByName(str);
        auto aniFrame = AnimationFrame::create(sprFrame, 0.5, ValueMap());
        animationFrameVector.pushBack(aniFrame);
    }
    auto animation = Animation::create(animationFrameVector,0.5,1);
    auto animate = Animate::create(animation);
    this->runAction(animate);
}
void Sprite1Child::upLevel()
{
    char str[50];
    sprintf(str, "Shit%d1.png",level);
    auto spriteframe = spriteFrameCache1->getSpriteFrameByName(str);
    this->setSpriteFrame(spriteframe);
}
void Sprite1Child::setLevel(int _level)
{
    if (_level>=3)
    {
        _level = 3;
    }
    this->level = _level;
}
int Sprite1Child::getLevel()
{
    return this->level;
}
Sprite* Sprite1Child::creatBullet(Vec2 pos)
{
    auto bullet = Sprite::create();
    char str[50];
    sprintf(str, "PShit%d1.png",level);
    auto spriteframe = spriteFrameCache1->getSpriteFrameByName(str);
    bullet->setSpriteFrame(spriteframe);
    bullet->setPosition(pos);
    fireAnimation();
    return bullet;
}
int Sprite1Child::bulltAttack()
{
    if (level == 1)
    {
        attack = 2;
    }
    if (level == 2)
    {
        attack = 4;
    }
    if (level == 3)
    {
        attack = 6;
    }
    return attack;
}
int Sprite1Child::getBuygold()
{
    return buygold;
}
int Sprite1Child::getupgold()
{
    int upgold;
    if (level == 1)
    {
        upgold = up1gold;
    }
    if (level == 2)
    {
        upgold = up2gold;
    }
    
    return upgold;
}

int Sprite1Child::getdeletegold()
{
    int deletenum;
    if (level == 1)
    {
        deletenum = delete1;
    }
    if (level == 2)
    {
        deletenum = delete2;
    }
    if (level == 3)
    {
        deletenum = delete3;
    }
    return deletenum;
}






