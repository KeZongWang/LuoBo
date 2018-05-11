//
//  Carrot.hpp
//  CarrotFantasy
//
//  Created by MAC on 16/8/11.
//
//

#ifndef Carrot_hpp
#define Carrot_hpp

#include <iostream>
using namespace std;
#include "cocos2d.h"
USING_NS_CC;
class Carrot:public Sprite
{
    
public:
    static Carrot*create(Vec2 pos);  //传入位置
    virtual bool init(Vec2 pos);
    int getHp();                     //获得血量
    void setHp(int hp);              //设置血量
    void doAction();                 //执行动画
    void changspriteFrame(int i);
    void changeShap1();              //根据血量改变图片
    
private:
    int Hp;
    SpriteFrameCache* spriteFrameCache1;
    
    
};

#endif /* Carrot_hpp */


























