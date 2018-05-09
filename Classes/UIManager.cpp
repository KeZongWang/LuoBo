//
//  UIManager.cpp
//  Birds
//
//  Created by wangsl on 18/4/25.
//
//

#include "UIManager.hpp"
#include "UIchapterLayer.hpp"
#include "UISelectLayer.hpp"
#define BACKGROUNDZORDER 10
#define SETLAYERZORDER 20

UIBaseLayer* UIManager::m_activeLayer = nullptr;
UIBaseLayer* UIManager::CreateLayer(UIManager::LayerType type)
{
    m_activeLayer = nullptr;
    switch (type) {
        case SETLAYER:
        {
            m_activeLayer = UIchapterLayer::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        case SELECT:
        {
            m_activeLayer = UISelectLayer::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        default:
            break;
    }
    return m_activeLayer;
}
void UIManager::DestroyLayer()
{
    if (m_activeLayer)
    {
        m_activeLayer->removeFromParent();
        m_activeLayer = nullptr;
    }
}