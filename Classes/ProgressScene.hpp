//
//  ProgressScene.hpp
//  DefendRadish
//
//  Created by mac on 18/5/10.
//
//

#ifndef ProgressScene_hpp
#define ProgressScene_hpp

#include <stdio.h>
class ProgressScene:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(ProgressScene);
    void returnTest();
//    void onEnter();
    void beginScene();
    private:
    cocos2d:: Node* node;
    cocos2d::Size size;
   
    cocos2d::Layer* layer;
    
};

#endif /* ProgressScene_hpp */
