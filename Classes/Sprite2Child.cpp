//
//  Sprite2Child.cpp
//  CarrotFantasy
//
//  Created by MAC on 16/8/12.
//
//

#include "Sprite2Child.hpp"
Sprite2Child* Sprite2Child::create(Vec2 pos)
{
    Sprite2Child *sprite1Child=new Sprite2Child();
    if (sprite1Child&&sprite1Child->init(pos)) {
        sprite1Child->autorelease();
        return sprite1Child;
    }
    CC_SAFE_DELETE(sprite1Child);
    return nullptr;
}
bool Sprite2Child::init(Vec2 pos)
{
    if (!BasePrite::init("Bottle11.png", pos)) {
        return false;
    }
    spriteFrameCache1 = SpriteFrameCache::getInstance();
    spriteFrameCache1->addSpriteFramesWithFile("pingzi.plist", "pingzi.png");
    this->level = 1;

    isBullet=false;
    return true;
}
void Sprite2Child::fireAnimation()
{
    Vector<AnimationFrame*> animationFrameVector;
    for (int i = 1; i <= 2; i++)
    {
        std::string str = StringUtils::format("Bottle%d%d.png",level,i);
        auto sprFrame = spriteFrameCache1->getSpriteFrameByName(str);
        auto aniFrame = AnimationFrame::create(sprFrame, 0.5, ValueMap());
        animationFrameVector.pushBack(aniFrame);
    }
    auto animation = Animation::create(animationFrameVector,0.5,1);
    auto animate = Animate::create(animation);
    this->runAction(animate);
}
void Sprite2Child::upLevel()
{
    char str[50];
    sprintf(str, "Bottle%d1.png",level);
    auto spriteframe = spriteFrameCache1->getSpriteFrameByName(str);
    this->setSpriteFrame(spriteframe);
}
void Sprite2Child::setLevel(int _level)
{
    if (_level>=3)
    {
        _level = 3;
    }
    this->level = _level;
}
int Sprite2Child::getLevel()
{
    return this->level;
}
Sprite* Sprite2Child::creatBullet(Vec2 pos)
{
    auto bullet = Sprite::create();
    char str[50];
    sprintf(str, "PBottle%d1.png",level);
    auto spriteframe = spriteFrameCache1->getSpriteFrameByName(str);
    bullet->setSpriteFrame(spriteframe);
    bullet->setPosition(pos);
    fireAnimation();
    return bullet;
}
int Sprite2Child::bulltAttack()
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
int Sprite2Child::getBuygold()
{
    return buygold;
}
int Sprite2Child::getupgold()
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

int Sprite2Child::getdeletegold()
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





































