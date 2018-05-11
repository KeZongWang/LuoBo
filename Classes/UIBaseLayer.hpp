//
//  UIBaseLayer.hpp
//  Birds
//
//  Created by wangsl on 18/4/25.
//
//

#ifndef UIBaseLayer_hpp
#define UIBaseLayer_hpp

#include "cocos2d.h"
//图层的父类；
class UIBaseLayer:public cocos2d::Layer
{
public:
    CREATE_FUNC(UIBaseLayer);
    virtual bool init()override;
    virtual void onEnter()override;
    virtual void onExit()override;
    
    
    virtual void onCreate(){};
    virtual void onActive(){};
    virtual void onDestroy(){};
};

#endif /* UIBaseLayer_hpp */
