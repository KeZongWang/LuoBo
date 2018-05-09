//
//  CScene.hpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#ifndef CScene_hpp
#define CScene_hpp

#include <stdio.h>
class CScene:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(CScene);
    
};
#endif /* CScene_hpp */
