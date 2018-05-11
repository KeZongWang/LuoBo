//
//  GameScene.hpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/9.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "cocos2d.h"

class GameScene:public cocos2d::Scene
{
public:
    static Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(GameScene);
    
};



#endif /* GameScene_hpp */
