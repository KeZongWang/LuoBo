//
//  UIHeart.hpp
//  DefendRadish
//
//  Created by mac on 18/5/11.
//
//

#ifndef UIHeart_hpp
#define UIHeart_hpp
#include "UIBaseLayer.hpp"
#include "ui/cocosGUI.h"

#include <stdio.h>
class UIHear:public UIBaseLayer
{
public:
    
    CREATE_FUNC(UIHear);
    void onActive();
    void onDestroy();
    void onCreate();
    void loadCSB();
    void registerAllCallBacks();
    void ReturnCallBack(cocos2d::Ref* sender);
    cocos2d::ui::Button* Return;
    
};
#endif /* UIHeart_hpp */
