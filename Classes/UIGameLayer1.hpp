//
//  UIGameLayer1.hpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/9.
//
//

#ifndef UIGameLayer1_hpp
#define UIGameLayer1_hpp
#include "UIBaseLayer.hpp"
#include "ui/CocosGUI.h"
#include "Carrot.hpp"
#include "MonesterBird.hpp"
#include "Sprite1Child.hpp"
#include "Sprite2Child.hpp"
class UIGameLayer1:public UIBaseLayer
{
public:
    CREATE_FUNC(UIGameLayer1);
    virtual void onCreate()override;
    virtual void onActive()override;
    virtual void onDestroy()override;
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;

    void loadCSB();
    void createmonster();
    void EatEvent();
    void finish();
    void removebtn();
    void addconnect(Vec2 point);
    void judeadd(Vec2 point);
    void direction(BasePrite* m_connect,Vec2 point1,Vec2 point2);
    void shitmonester();
    void pengzhuang();

private:
    cocos2d::Node* m_node;
    cocos2d::TMXTiledMap* m_map;
    cocos2d::TMXLayer* m_collideLayer;
    cocos2d::Sprite* m_yun;
    cocos2d::Sprite* m_qiu1;
    cocos2d::Sprite* m_qiu2;
    Carrot* m_luobo;
    MonesterBird* m_monster;
    cocos2d::TMXObjectGroup* m_wayLayer;
    cocos2d::Vector<MonesterBird*> m_monesterVector;
    cocos2d::ui::Button* m_Pingzibtn;
    cocos2d::ui::Button* m_Shitbtn;
    cocos2d::ui::Button* m_Chabtn;
    Sprite2Child* m_pingzi;
    Sprite1Child* m_shit;
    cocos2d::Vector<Sprite2Child*> m_pingziVector;
    cocos2d::Vector<Sprite1Child*> m_shitVector;
    cocos2d::Vector<Sprite*> m_bulletVector;
};

#endif /* UIGameLayer1_hpp */
