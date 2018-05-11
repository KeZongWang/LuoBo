//
//  UIManager.hpp
//  Birds
//
//  Created by wangsl on 18/4/25.
//
//

#ifndef UIManager_hpp
#define UIManager_hpp
#include "UIBaseLayer.hpp"

class UIManager
{
public:
    enum LayerType{
        SETLAYER,
        SELECT,
<<<<<<< HEAD
        UIMENU,
        UIHEART,
        
=======
        GAME1,
>>>>>>> 9c677dd07513d7bbe0175274ae934001a39f46e4
    };
    static UIBaseLayer*CreateLayer(LayerType type);
    static void DestroyLayer();//成员变量图层存在，删除图层，并置空
    static UIBaseLayer* m_activeLayer;//成员变量
    
    
    
    
};

#endif /* UIManager_hpp */
