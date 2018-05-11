//
//  UISetLayer.cpp
//  DefendRadish
//
//  Created by mac on 18/5/11.
//
//

#include "UISetLayer.hpp"
#include "UIManager.hpp"

void UISetLayer:: okCallBack(cocos2d::Ref* sender)
{
    UIManager::DestroyLayer();
}