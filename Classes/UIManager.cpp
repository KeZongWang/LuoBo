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
#include "UIMenu.hpp"
#include "UIHeart.hpp"
#define BACKGROUNDZORDER 10
#define SETLAYERZORDER 20
//管理图层；

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
        case UIMENU:
        {
            m_activeLayer = UIMenu::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        case UIHEART:
        {
            m_activeLayer = UIHear::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        default:
            break;
    }
    return m_activeLayer;
}
void UIManager::DestroyLayer()//成员变量图层存在，删除图层，并置空

{
    if (m_activeLayer)
    {
        m_activeLayer->removeFromParent();
        m_activeLayer = nullptr;
    }
}