//
//  RadishTest.hpp
//  DefendRadish
//
//  Created by mac on 18/5/9.
//
//

#ifndef RadishTest_hpp
#define RadishTest_hpp

#include <stdio.h>
class RadishTest:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(RadishTest);
    void SceneTest();
    void SayActionTest();
    void DirectorScene();
    
private:
    cocos2d:: Node* node;
    cocos2d::Sprite* Sprite1;
    cocos2d::Sprite* Sprite2;
};
#endif /* RadishTest_hpp */
