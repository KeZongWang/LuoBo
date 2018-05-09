//
//  UIBaseLayer.cpp
//  Birds
//
//  Created by wangsl on 18/4/25.
//
//

#include "UIBaseLayer.hpp"
bool UIBaseLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    this->onCreate();
    return true;
}
void UIBaseLayer::onEnter()
{
    Layer::onEnter();
    this->onActive();
}
void UIBaseLayer::onExit()
{
    this->onDestroy();
    Layer::onExit();
}