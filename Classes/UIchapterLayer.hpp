//
//  UIchapterLayer.hpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/7.
//
//

#ifndef UIchapterLayer_hpp
#define UIchapterLayer_hpp
#include "CocoStudio.h"
#include "UIBaseLayer.hpp"
#include "ui/CocosGUI.h"
class UIchapterLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(UIchapterLayer);
    virtual void onCreate()override;
    virtual void onActive();
    virtual void onDestroy();
    
    void loadCSB();
    
    void registerAllCallBacks();
    
    void leftCallBack(cocos2d::Ref* sender);
    void rightCallBack(cocos2d::Ref* sender);
    void pageviewCallBack(cocos2d::Ref* sender, cocos2d::ui::PageView::EventType type);
    void backCallBack(cocos2d::Ref* sender);
    void helpCallBack(cocos2d::Ref* sender);
    void part1CallBack(cocos2d::Ref* sender);
    void upDate(float dt);
 
private:
    cocos2d::Node* m_node;
    cocos2d::Node* m_node1;
    cocos2d::ui::Button* m_startbtn;
    cocos2d::ui::Button* m_leftbtn;
    cocos2d::ui::Button* m_rightbtn;
    cocos2d::ui::Button* m_backbtn;
    cocos2d::ui::Button* m_helpbtn;
    cocos2d::ui::PageView* m_pageview;
    int pagenum;
};


#endif /* UIchapterLayer_hpp */
