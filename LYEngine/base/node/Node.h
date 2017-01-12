#ifndef LYENGINE_NODE_H
#define LYENGINE_NODE_H

namespace ly {

class Node {
public:
    virtual void update(float delta) { }

    virtual void onBackground() { }

    virtual void onForeground() { }
};

class InputEventNode : public Node {
public:
    virtual bool onKeyDown(int keyCode) { return false; };

    virtual void onKeyUp(int keyCode) { };

    virtual bool onTouchDown(float x, float y) { return false; }

    virtual void onTouchUp(float x, float y) { }

    virtual void onTouchMove(float x, float y) { }

    virtual void ontTouchCancel() { }
};

}


#endif //LYENGINE_NODE_H
