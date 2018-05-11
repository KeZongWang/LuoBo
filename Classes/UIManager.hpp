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
        GAME1,
    };
    static UIBaseLayer*CreateLayer(LayerType type);
    static void DestroyLayer();
    static UIBaseLayer* m_activeLayer;
    
    
    
    
};

#endif /* UIManager_hpp */
