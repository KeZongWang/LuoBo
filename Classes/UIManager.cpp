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
<<<<<<< HEAD
#include "UIMenu.hpp"
#include "UIHeart.hpp"
=======
#include "UIGameLayer1.hpp"
>>>>>>> 9c677dd07513d7bbe0175274ae934001a39f46e4
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
<<<<<<< HEAD
        case UIMENU:
        {
            m_activeLayer = UIMenu::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        case UIHEART:
        {
            m_activeLayer = UIHear::create();
=======
        case GAME1:
        {
            m_activeLayer = UIGameLayer1::create();
>>>>>>> 9c677dd07513d7bbe0175274ae934001a39f46e4
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