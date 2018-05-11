//
//  MonesterBird.hpp
//  defendradish
//
//  Created by mac on 16/8/9.
//
//

#ifndef MonesterBird_hpp
#define MonesterBird_hpp

#include <stdio.h>
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
#define birdHP 10
USING_NS_CC;
enum MonesterID
{
    Monester1=1,
    Monester2=2,
    Monester3=3
};
class MonesterBird:public cocos2d::Sprite
{
public:
    static MonesterBird*create(Vec2 pos);
    virtual bool init(Vec2 pos);
    void doAnimation();
    bool isDied;
    bool isTouch;//是否选中
    int getAddgold();
    int getHp();       //获得血量
    void setHp(int hp);  //设置血量
    void loadingBar();//血条
    void way(TMXObjectGroup* m_wayLayer);
private:
    SpriteFrameCache* spriteFrameCache1;
    int addGold = 20;
    int Hp;
};
#endif /* MonesterBird_hpp */







