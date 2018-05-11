//
//  UIMenu.hpp
//  DefendRadish
//
//  Created by mac on 18/5/11.
//
//

#ifndef UIMenu_hpp
#define UIMenu_hpp

#include <stdio.h>
#include "UIBaseLayer.hpp"
#include "ui/cocosGUI.h"
class UIMenu:public UIBaseLayer
{
public:

    CREATE_FUNC(UIMenu);
    void onActive();
    void onDestroy();
    void onCreate();
    void loadCSB();
    void BtncontinueCallBack(cocos2d::Ref* sender);
    void BtnbeginCallBack(cocos2d::Ref* sender);
     void BtnchooseCallBack(cocos2d::Ref* sender);
    void registerAllCallBacks();//给button设置回调函数；

private:
    cocos2d::Layer* layer;
    cocos2d::ui::Button* Btncontinue;
    cocos2d::ui::Button* Btnbegin;
    cocos2d::ui::Button* Btnchoose;
};
#endif /* UIMenu_hpp */
