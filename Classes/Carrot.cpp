//
//  Carrot.cpp
//  CarrotFantasy
//
//  Created by MAC on 16/8/11.
//
//

#include "Carrot.hpp"
Carrot* Carrot::create(Vec2 pos)
{
    auto sprite = new Carrot();
    if (sprite && sprite->init(pos))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}
bool Carrot::init(Vec2 pos)
{
    if (!Sprite::init())
    {
        return false;
    }
    spriteFrameCache1 = SpriteFrameCache::getInstance();
    spriteFrameCache1->addSpriteFramesWithFile("Chapter/Items01-hd.plist", "Chapter/Items01-hd.png");
    auto spriteFrame = spriteFrameCache1->getSpriteFrameByName("hlb10.png");
    this->setSpriteFrame(spriteFrame);
    this->setScale(0.6);
    this->setAnchorPoint(Vec2(0.4, 0.2));
    this->Hp = 10;
    this->setPosition(pos);
    return true;
}
int Carrot::getHp()
{
    return Hp;
}
void Carrot::setHp(int hp)
{
    this->Hp = hp;
}
void Carrot::doAction()
{
    //精灵帧缓存
    Vector<AnimationFrame*> animationFrameVector;
    for (int i = 0; i <= 8; i++)
    {
        std::string str = StringUtils::format("hlb1%d.png",i);
        auto sprFrame = spriteFrameCache1->getSpriteFrameByName(str);
        auto aniFrame = AnimationFrame::create(sprFrame, 0.1, ValueMap());
        animationFrameVector.pushBack(aniFrame);
    }
    auto sprFrame = spriteFrameCache1->getSpriteFrameByName("hlb10.png");
    auto aniFrame = AnimationFrame::create(sprFrame, 0.1, ValueMap());
    animationFrameVector.pushBack(aniFrame);
    auto animation = Animation::create(animationFrameVector,0.5,1);
    auto animate = Animate::create(animation);
    this->runAction(animate);
}

void Carrot::changspriteFrame(int i)
{
    std::string str = StringUtils::format("hlb%d.png",i);
    auto spriteFrame2 = spriteFrameCache1->getSpriteFrameByName(str);
    this->setSpriteFrame(spriteFrame2);
}
void Carrot::changeShap1()
{
    
    if (Hp>=9 && Hp<10)
    {
        changspriteFrame(9);
    }else if (Hp>=7)
    {
        changspriteFrame(6);
    }else if (Hp>=5)
    {
        changspriteFrame(4);
    }else if (Hp>=3)
    {
        changspriteFrame(3);
    }else if (Hp>=1)
    {
        changspriteFrame(2);
    }else
    {
        changspriteFrame(1);
    }
    
}









