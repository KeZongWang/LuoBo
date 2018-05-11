//
//  BScene.hpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#ifndef BScene_hpp
#define BScene_hpp

#include <stdio.h>
class BScene:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(BScene);
    void returnTest();
private:
    cocos2d::Layer* layer;
    
};

#endif /* BScene_hpp */
