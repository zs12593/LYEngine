#include "Node.h"
#include "../log/Log.h"

namespace ly {

Node::Node() {
    _tag = 0;
    _zOrder = 0;
    _parent = nullptr;
    _userData = nullptr;
}

Node::~Node() {
    removeAllChildren();
}

void Node::addChild(Node *child, int tag, int zOrder) {
    if (child->_parent) {
        Log::e("child already added other Node by name: %s", child->_parent->_name.c_str());
    } else {
        child->_tag = tag;
        child->_zOrder = zOrder;
        child->_parent = this;

        for (auto iter = _children.begin(); iter != _children.end(); iter++) {
            if ((*iter)->_zOrder <= child->_zOrder) {
                _children.insert(iter, child);
                return;
            }
        }
        _children.push_back(child);
    }
}

void Node::removeChild(Node *child, bool clean) {
    std::vector<Node *>::iterator iter;
    for (iter = _children.begin(); iter != _children.end(); iter++) {
        if ((*iter) == child) {
            _children.erase(iter);
            (*iter)->_parent = nullptr;
            if (clean)
                delete (*iter);
            break;
        }
    }
}

void Node::removeChildByTag(int tag, bool clean) {
    std::vector<Node *>::iterator iter;
    for (iter = _children.begin(); iter != _children.end(); iter++) {
        if ((*iter)->_tag == tag) {
            _children.erase(iter);
            (*iter)->_parent = nullptr;
            if (clean)
                delete (*iter);
            break;
        }
    }
}

void Node::removeAllChildren(bool clean) {
    if (clean) {
        std::vector<Node *>::iterator iter;
        for (iter = _children.begin(); iter != _children.end(); iter++)
            delete (*iter);
    }
    _children.clear();
}

Node *Node::getChild(int pos) {
    if (pos < _children.size())
        return _children[pos];
    return nullptr;
}

Node *Node::getChildByTag(int tag) {
    std::vector<Node *>::iterator iter;
    for (iter = _children.begin(); iter != _children.end(); iter++) {
        if ((*iter)->_tag == tag)
            return (*iter);
    }
    return nullptr;
}

void Node::renderer(Renderer *renderer) {
    for (auto iter = _children.end(); iter != _children.begin(); iter--) {
        (*iter)->renderer(renderer);
    }
}

}



