#include "InputEventNode.h"

namespace ly {

bool InputEventNode::handleKeyEvent(KeyEvent *keyEvent) {
    if (!_keyIntercept) {
        std::vector<Node *>::iterator iter;
        for (iter = _children.begin(); iter != _children.end(); iter++) {
            InputEventNode *child = dynamic_cast<InputEventNode *>(*iter);
            if (child && child->handleKeyEvent(keyEvent))
                break;
        }
    }
    switch (keyEvent->action) {
        case InputEvent::KeyDown:
            onKeyDown(keyEvent->keyCode);
            break;
        case InputEvent::KeyUp:
            onKeyUp(keyEvent->keyCode);
            break;
        default:
            break;
    }
    return _keyIntercept;
}

bool InputEventNode::handleTouchEvent(TouchEvent *touchEvent) {
    if (!_touchIntercept) {
        std::vector<Node *>::iterator iter;
        for (iter = _children.begin(); iter != _children.end(); iter++) {
            InputEventNode *child = dynamic_cast<InputEventNode *>(*iter);
            if (child && child->handleTouchEvent(touchEvent))
                break;
        }
    }
    // TODO
    // 一直往子节点传,到最后,如果触点在子节点自身,则调用on时间并返回true,
    // 如果触点不在自身,则返回父节点继续处理,同理
    // 如果强制拦截则直接返回true

    switch (touchEvent->action) {
        case InputEvent::TouchDown:
            break;
        case InputEvent::TouchMove:
            break;
        case InputEvent::TouchUp:
            break;
        case InputEvent::TouchCancel:
            break;
        default:
            break;
    }
    return _touchIntercept;
}

}
