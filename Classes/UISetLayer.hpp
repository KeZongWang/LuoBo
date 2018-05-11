//
//  UISetLayer.hpp
//  DefendRadish
//
//  Created by mac on 18/5/11.
//
//

#ifndef UISetLayer_hpp
#define UISetLayer_hpp

#include <stdio.h>
#include "UIBaseLayer.hpp"
class UISetLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(UISetLayer);
    void okCallBack(cocos2d::Ref* sender);
};
#endif /* UISetLayer_hpp */
