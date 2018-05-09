//
//  UISelectLayer.hpp
//  DefendRadish
//
//  Created by  Mac1 on 18/5/8.
//
//

#ifndef UISelectLayer_hpp
#define UISelectLayer_hpp

#include "UIBaseLayer.hpp"
#include "ui/CocosGUI.h"
class GameCase;
class UISelectLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(UISelectLayer);
    virtual void onCreate()override;
    virtual void onActive();
    virtual void onDestroy();
    
    void registerAllCallBacks();

    void loadCSB();
    
    void backCallBack(cocos2d::Ref* sender);
    void helpCallBack(cocos2d::Ref* sender);
    
private:
    cocos2d::ui::Button* m_backbtn;
    cocos2d::ui::Button* m_helpbtn;
    cocos2d::Node* m_node;
    std::vector<GameCase*> m_casesVector;
};


#endif /* UISelectLayer_hpp */
