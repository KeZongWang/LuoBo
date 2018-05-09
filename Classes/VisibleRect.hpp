//
//  VisibleRect.hpp
//  CatchFish
//
//  Created by wangsl on 18/4/10.
//
//

#ifndef VisibleRect_hpp
#define VisibleRect_hpp

#include "cocos2d.h"
class VisibleRect
{
public:
    static cocos2d::Rect getVisibleRect();
    
    static cocos2d::Vec2 left();
    static cocos2d::Vec2 right();
    static cocos2d::Vec2 top();
    static cocos2d::Vec2 bottom();
    static cocos2d::Vec2 center();
    static cocos2d::Vec2 leftTop();
    static cocos2d::Vec2 rightTop();
    static cocos2d::Vec2 leftBottom();
    static cocos2d::Vec2 rightBottom();
private:
    static void lazyInit();
    static cocos2d::Rect m_visibleRect;
};
#endif /* VisibleRect_hpp */
