//
//  AScene.hpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#ifndef AScene_hpp
#define AScene_hpp

#include <stdio.h>
class AScene:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(AScene);
    
};

#endif /* AScene_hpp */
