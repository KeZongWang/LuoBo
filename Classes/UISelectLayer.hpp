//
//  UISelectLayer.hpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/8.
//
//

#ifndef UISelectLayer_hpp
#define UISelectLayer_hpp

#include "UIBaseLayer.hpp"
#include "ui/CocosGUI.h"
class UISelectLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(UISelectLayer);
    virtual void onCreate()override;
    virtual void onActive()override;
    virtual void onDestroy()override;
    
    void registerAllCallBacks();

    void loadCSB();
    
    void backCallBack(cocos2d::Ref* sender);
    void helpCallBack(cocos2d::Ref* sender);
    void partCallBack(cocos2d::Ref* sender);
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
    
    void changeOpacity();
private:
    cocos2d::ui::Button* m_backbtn;
    cocos2d::ui::Button* m_helpbtn;
    cocos2d::ui::Button* m_startbtn;
    cocos2d::Node* m_node;
    cocos2d::Node* m_movenode;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 m_startpoint;
    cocos2d::Vec2 m_endpoint;
};


#endif /* UISelectLayer_hpp */
