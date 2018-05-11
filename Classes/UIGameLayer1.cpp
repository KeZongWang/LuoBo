//
//  UIGameLayer1.cpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/9.
//
//

#include "UIGameLayer1.hpp"
#include "CocoStudio.h"
#include "UIManager.hpp"
#include "Constant.h"
#include "math.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
void UIGameLayer1::onCreate()
{
    this->loadCSB();
    this->EatEvent();
}
void UIGameLayer1::loadCSB()
{
    FileUtils::getInstance()->addSearchPath("Studio");
    m_node = CSLoader::createNode(GameLayer1CSB);
    this->addChild(m_node);
    m_map=TMXTiledMap::create(GameTmx1);
    this->addChild(m_map);
    
    m_collideLayer = m_map->getLayer("addconnet");
    m_collideLayer->setVisible(false);
    
    //组成层
    auto partLayer=m_map->getObjectGroup("part");
    //云对象
    auto yunInfo=partLayer->getObject("Yun");
    m_yun=Sprite::create(Yun);
    m_yun->setPosition(yunInfo["x"].asFloat(),yunInfo["y"].asFloat());
    m_map->addChild(m_yun,2);
    
    //球1对象
    auto qiu1Info=partLayer->getObject("qiu1");
    m_qiu1=Sprite::create(Qiu1);
    m_qiu1->setPosition(qiu1Info["x"].asFloat(),qiu1Info["y"].asFloat());
    m_map->addChild(m_qiu1,2);
    
    //球2对象
    auto qiu2Info=partLayer->getObject("qiu2");
    m_qiu2=Sprite::create(Qiu2);
    m_qiu2->setPosition(qiu2Info["x"].asFloat(),qiu2Info["y"].asFloat());
    m_map->addChild(m_qiu2,2);
    
    m_wayLayer=m_map->getObjectGroup("way");
    auto finishInfo=m_wayLayer->getObject("finish");
    
    //萝卜
    m_luobo=Carrot::create(Vec2(finishInfo["x"].asFloat(),finishInfo["y"].asFloat()));
    this->addChild(m_luobo,2);
}

void UIGameLayer1::createmonster()   // 添加怪兽
{
    this->schedule([=](float dt)
       {
           auto exitInfo=m_wayLayer->getObject("exit");
           m_monster=MonesterBird::create(Vec2(exitInfo["x"].asFloat(),exitInfo["y"].asFloat()));
           this->addChild(m_monster);
           m_monesterVector.pushBack(m_monster);
           
           
           m_monster->way(m_wayLayer);// 路径
           
        },0.5,9,0,"move");
}

void UIGameLayer1::EatEvent()   // 自定义吃事件
{
    auto listener=EventListenerCustom::create("eat",[=](EventCustom* event)
      {
          int hp=m_luobo->getHp();
          hp--;
          CCLOG("hp=%d",hp);
          m_luobo->setHp(hp);
          m_luobo->changeShap1();
      });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);
}
void UIGameLayer1::finish()  // 判断是否走到最后
{
    auto iter_monter=m_monesterVector.begin();
    for (;iter_monter<m_monesterVector.end();iter_monter++)
    {
        // 走完全程掉自定义
        auto finishInfo=m_wayLayer->getObject("finish");
        auto post=(*iter_monter)->getPosition();
        if (post.x==finishInfo["x"].asFloat()&&post.y==finishInfo["y"].asFloat())
        {
            auto event=new EventCustom("eat");
            // 分发事件
            Director::getInstance()->getEventDispatcher()->dispatchEvent(event);
            iter_monter=m_monesterVector.erase(iter_monter);
            iter_monter--;
            continue;
        }

    }
}

void UIGameLayer1::pengzhuang()
{
    auto iter_monter=m_monesterVector.begin();
    for (;iter_monter<m_monesterVector.end();iter_monter++)
    {
        
        auto rect=(*iter_monter)->getBoundingBox();
        auto iter_bullet=m_bulletVector.begin();
        for (;iter_bullet<m_bulletVector.end();iter_bullet++)
        {
            auto postbullet=(*iter_bullet)->getPosition();
            if (rect.containsPoint(postbullet))
            {
                iter_bullet=m_bulletVector.erase(iter_bullet);
                iter_bullet--;
                
                (*iter_monter)->loadingBar(); //添加
                auto hp=(*iter_monter)->getHp();
                hp-=3;
                CCLOG("hp=%d",hp);
                (*iter_monter)->setHp(hp);
                if (hp<0)
                {
                    auto remove=RemoveSelf::create();
                    (*iter_monter)->runAction(remove);
                    
                    iter_monter=m_monesterVector.erase(iter_monter);
                    iter_monter--;
                }
                break;
            }
        }
    }

}
void UIGameLayer1::shitmonester()  // 射击怪兽和转向
{
    auto iter_pingzi=m_pingziVector.begin();
    for (;iter_pingzi<m_pingziVector.end();iter_pingzi++)
    {
        auto postconnect=(*iter_pingzi)->getPosition();
        
        auto iter_monter=m_monesterVector.begin();
        for (;iter_monter<m_monesterVector.end();iter_monter++)
        {
            auto post=(*iter_monter)->getPosition();
            float dx=post.x-postconnect.x;
            float dy=post.y-postconnect.y;
            float distance=sqrt(dx*dx+dy*dy);
            if (distance<100)
            {
                float radians = atanf((postconnect.x-post.x)/(postconnect.y-post.y));//返回弧度制
                if (postconnect.y-post.y>0)
                {
                    radians += 3.1415926;  // 加180度
                }
                radians = CC_RADIANS_TO_DEGREES(radians);
                //角度转弧度
                (*iter_pingzi)->setRotation(radians);
                
                direction((*iter_pingzi),postconnect,post);
                break;
            }
        }
        
        auto iter_shite=m_shitVector.begin();
        for (;iter_shite<m_shitVector.end();iter_shite++)
        {
            auto postconnect=(*iter_shite)->getPosition();
            
            auto iter_monter=m_monesterVector.begin();
            for (;iter_monter<m_monesterVector.end();iter_monter++)
            {
                auto post=(*iter_monter)->getPosition();
                float dx=post.x-postconnect.x;
                float dy=post.y-postconnect.y;
                float distance=sqrt(dx*dx+dy*dy);
                if (distance<100)
                {
                    direction((*iter_shite),postconnect,post);
                    break;
                }
            }
        }
    }
}
void UIGameLayer1::direction(BasePrite* connect,Vec2 point1, Vec2 point2)
{
    auto bullet=connect->creatBullet(point1);
    this->addChild(bullet);
    m_bulletVector.pushBack(bullet);
    
    auto move = MoveTo::create(0.05,point2);
    auto remove = RemoveSelf::create();
    bullet->runAction(Sequence::create(move,remove,NULL));
}

void UIGameLayer1::removebtn()
{
    m_Pingzibtn->removeFromParent();
    m_Pingzibtn=nullptr;
    m_Shitbtn->removeFromParent();
    m_Shitbtn=nullptr;
    m_Chabtn->removeFromParent();
    m_Chabtn=nullptr;
}
bool UIGameLayer1::onTouchBegan(Touch *touch, Event *unused_event)
{
    auto point=touch->getLocation();
    auto rect=m_luobo->getBoundingBox();
    if (rect.containsPoint(point)&&m_luobo->getHp()==10)
    {
        m_luobo->doAction();
    }
    
//    if (m_pingziVector.size()>0||m_shitVector.size()>0)
//    {
//        auto iter_pingzi=m_pingziVector.begin();
//        for (;iter_pingzi<m_pingziVector.end();iter_pingzi++)
//        {
//            auto iter_shit=m_shitVector.begin();
//            for (;iter_shit<m_shitVector.end();iter_shit++)
//            {
//                auto rect1=(*iter_shit)->getBoundingBox();
//                auto rect=(*iter_pingzi)->getBoundingBox();
//                if (rect.containsPoint(point))
//                {
//                
//                }
//                else if(rect1.containsPoint(point))
//                {
//    
//                }
//                else
//                {
//                    this->judeadd(point);
//                }
//            }
//        }
//    }
//    else
//    {
        this->judeadd(point);
//    }
    
    return true;
}

void UIGameLayer1::judeadd(Vec2 point) //获取瓦片
{
    int tileX = point.x/32;
    int tileY = (320-point.y)/32;
    auto gid= m_collideLayer->getTileGIDAt(Vec2(tileX,tileY));
    auto propertys = m_map->getPropertiesForGID(gid);
    if (!propertys.isNull())
    {
        bool stop = propertys.asValueMap()["can"].asBool();
        if (stop)
        {
            this->addconnect(point);
        }
    }
}

void UIGameLayer1::addconnect(Vec2 point)
{
    if (m_Pingzibtn&&m_Shitbtn)
    {
        this->removebtn();
    }
    m_Pingzibtn=ui::Button::create(PingziBtn);
    m_Shitbtn=ui::Button::create(ShitBtn);
    m_Chabtn=ui::Button::create(ChaBtn);
    m_Pingzibtn->setPosition(Vec2(point.x-40,point.y));
    m_Shitbtn->setPosition(Vec2(point.x,point.y));
    m_Chabtn->setPosition(Vec2(point.x+40,point.y));
    this->addChild(m_Pingzibtn);
    this->addChild(m_Shitbtn);
    this->addChild(m_Chabtn);
    
    m_Shitbtn->addClickEventListener([=](cocos2d::Ref* sender)
     {
         CCLOG("点击");
         m_shit=Sprite1Child::create(point);
         this->addChild(m_shit,2);
         m_shitVector.pushBack(m_shit);
         this->removebtn();
     });
    
    m_Pingzibtn->addClickEventListener([=](cocos2d::Ref* sender)
       {
           CCLOG("点击");
           m_pingzi=Sprite2Child::create(point);
           this->addChild(m_pingzi,2);
           m_pingziVector.pushBack(m_pingzi);
           this->removebtn();
       });
    
    m_Chabtn->addClickEventListener([=](cocos2d::Ref* sender)
    {
        this->removebtn();
    });


}

void UIGameLayer1::onActive()
{
    CCLOG("激活 －－> 准备刷新UI");
    this->schedule([=](float dt)
       {
           this->createmonster();
       },20,10,2,"cteate");
    
    this->schedule([=](float dt)
       {
          this->finish();
          this->pengzhuang();
           
       },1/60,CC_REPEAT_FOREVER,0,"diao");
    
    this->schedule([=](float dt)
       {
           this->shitmonester();
           
       },0.4,CC_REPEAT_FOREVER,0,"shit");
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(UIGameLayer1::onTouchBegan,this);
    touchListener->setSwallowTouches(true);
    //事件监听的注册
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

}
void UIGameLayer1::onDestroy()
{
    CCLOG("销毁 －－> 准备保存各种设置");
    
}
