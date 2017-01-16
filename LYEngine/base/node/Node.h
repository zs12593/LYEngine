#ifndef LYENGINE_NODE_H
#define LYENGINE_NODE_H

#include <vector>
#include <string>
#include "../renderer/Renderer.h"

namespace ly {

class Node {
public:
    Node();

    ~Node();

    virtual void update(float delta) { }

    virtual void onBackground() { }

    virtual void onForeground() { }

    virtual void addChild(Node *child, int tag = 0, int zOrder = 0);

    virtual void removeChild(Node *child, bool clean = true);

    virtual void removeChildByTag(int tag, bool clean = true);

    void removeAllChildren(bool clean = true);

    virtual Node *getChild(int pos);

    virtual Node *getChildByTag(int tag);

    void setTag(int tag) { this->_tag = tag; }

    int getTag() { return this->_tag; }

    void setZOrder(int zOrder) { this->_zOrder = zOrder; }

    int getZOrder() { return _zOrder; }

    void setParent(Node *parent) { this->_parent = parent; }

    Node *getParent() { return this->_parent; }

    void setName(std::string name) { this->_name = name; }

    std::string getName() { return this->_name; }

    void setUserData(void *userData) { this->_userData = userData; }

    void *getUsreData() { return this->_userData; }

    virtual void renderer(Renderer* renderer);

protected:
    std::vector<Node *> _children;
    int _tag;
    int _zOrder;
    std::string _name;

    Node *_parent;
    void *_userData;
};

}


#endif //LYENGINE_NODE_H
