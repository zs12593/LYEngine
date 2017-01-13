#ifndef LYENGINE_INPUTEVENTNODE_H
#define LYENGINE_INPUTEVENTNODE_H

#include "Node.h"
#include "../event/Event.h"

namespace ly {

class InputEventNode : public Node {
public:
    InputEventNode() {
        _keyIntercept = false;
        _touchIntercept = false;
    }

    virtual bool handleKeyEvent(KeyEvent *keyEvent);

    virtual bool handleTouchEvent(TouchEvent *touchEvent);

    virtual void onKeyDown(int keyCode) { };

    virtual void onKeyUp(int keyCode) { };

    virtual void onTouchDown(float x, float y) { }

    virtual void onTouchPointerDown(int id, float x, float y){}

    virtual void onTouchUp(float x, float y) { }

    virtual void onTouchMove(float x, float y) { }

    virtual void ontTouchCancel() { }

    void setKeyIntercept(bool keyIntercept) { this->_keyIntercept = keyIntercept; }

    bool isKeyIntercept() { return this->_keyIntercept; }

    void setTouchIntercept(bool touchIntercept) { this->_touchIntercept = touchIntercept; }

    bool isTouchIntercept() { return this->_touchIntercept; }

private:
    bool _keyIntercept;
    bool _touchIntercept;
};

}


#endif //LYENGINE_INPUTEVENTNODE_H
