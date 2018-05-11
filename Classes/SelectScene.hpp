//
//  SelectScene.hpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/7.
//
//

#ifndef SelectScene_hpp
#define SelectScene_hpp
#include "UIchapterLayer.hpp"
#include "cocos2d.h"
class SelectScene:public cocos2d::Scene
{
public:
    static Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(SelectScene);
    virtual void onEnter()override;
    virtual void onExit()override;
    void returnTest();
private:
    void initUI();
   
    
    
};

#endif /* SelectScene_hpp */
