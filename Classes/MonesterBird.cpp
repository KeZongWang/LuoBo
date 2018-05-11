//
//  MonesterBird.cpp
//  defendradish
//
//  Created by mac on 16/8/9.
//
//

#include "MonesterBird.hpp"
MonesterBird* MonesterBird::create(Vec2 pos)
{
    MonesterBird *monesterBird=new MonesterBird();
    if (monesterBird&&monesterBird->init(pos)) {
        monesterBird->autorelease();
        return monesterBird;
    }
    CC_SAFE_DELETE(monesterBird);
    return nullptr;
}
bool MonesterBird::init(Vec2 pos)
{
    if (!Sprite::init())
    {
        return false;
    }
    spriteFrameCache1 = SpriteFrameCache::getInstance();
    spriteFrameCache1->addSpriteFramesWithFile("monsters.plist", "monsters.png");
    isDied = false;
    isTouch = false;
    doAnimation();
    Hp =birdHP;
    this->setPosition(pos);
    return true;
}
void MonesterBird::doAnimation()
{
    Vector<AnimationFrame*> animationFrameVector;
    for (int i = 1; i <= 3; i++)
    {
        std::string str = StringUtils::format("PetFly1%d_01.png",i);
        auto sprFrame = spriteFrameCache1->getSpriteFrameByName(str);
        auto aniFrame = AnimationFrame::create(sprFrame, 0.3, ValueMap());
        animationFrameVector.pushBack(aniFrame);
    }
    auto animation = Animation::create(animationFrameVector,0.5,1);
    auto animate = Animate::create(animation);
    auto repeat = RepeatForever::create(animate);
    this->runAction(repeat);
}
int MonesterBird::getAddgold()
{
    return addGold;
}
int MonesterBird::getHp()
{
    return Hp;
}
void MonesterBird::setHp(int hp)
{
    this->Hp = hp;
}

//怪物显示的血条
void MonesterBird::loadingBar()
{
    auto loading=LoadingBar::create("hpBar.png");
    if(this->getHp()>0)
    {
        loading->setScale(0.25,0.3);
        loading->setPercent(this->getHp()*5);
        loading->setPosition(Vec2(this->getContentSize().width/2,this->getContentSize().height+5));
        this->addChild(loading);
        auto delaytime=DelayTime::create(0.4);
        auto callFuncn=CallFuncN::create([=](Node*D)
         {
             D->removeFromParentAndCleanup(true);
         });
        auto sequence=Sequence::create(delaytime,callFuncn, NULL);
        loading->runAction(sequence);
    }
}

// 路径
void MonesterBird::way(TMXObjectGroup* m_wayLayer)
{
    auto point1Info=m_wayLayer->getObject("point1");
    auto point2Info=m_wayLayer->getObject("point2");
    auto point3Info=m_wayLayer->getObject("point3");
    auto point4Info=m_wayLayer->getObject("point4");
    auto point5Info=m_wayLayer->getObject("point5");
    auto point6Info=m_wayLayer->getObject("point6");
    auto finishInfo=m_wayLayer->getObject("finish");
    
    auto move1=MoveTo::create(2,Vec2(point1Info["x"].asFloat(),point1Info["y"].asFloat()));
    auto move2=MoveTo::create(2,Vec2(point2Info["x"].asFloat(),point2Info["y"].asFloat()));
    auto move3=MoveTo::create(1.5,Vec2(point3Info["x"].asFloat(),point3Info["y"].asFloat()));
    auto move4=MoveTo::create(2,Vec2(point4Info["x"].asFloat(),point4Info["y"].asFloat()));
    auto move5=MoveTo::create(1.5,Vec2(point5Info["x"].asFloat(),point5Info["y"].asFloat()));
    auto move6=MoveTo::create(2,Vec2(point6Info["x"].asFloat(),point6Info["y"].asFloat()));
    auto move7=MoveTo::create(2,Vec2(finishInfo["x"].asFloat(),finishInfo["y"].asFloat()));
    
    auto remove=RemoveSelf::create();
    auto seq=Sequence::create(move1,move2,move3,move4,move5,move6,move7,remove,NULL);
    this->runAction(seq);

}









