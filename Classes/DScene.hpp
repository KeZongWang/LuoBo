//
//  DScene.hpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#ifndef DScene_hpp
#define DScene_hpp

#include <stdio.h>
class DScene:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(DScene);
    void returnTest();
};
#endif /* DScene_hpp */
