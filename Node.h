#ifndef NODE_H
#define NODE_H

#include <vector>

struct Node {
    unsigned int id;
    double g;
    double h;
    double f;
    int x;
    int y;
    std::vector<Node*> successors;
    Node* parent;

    // Node(int _id, double _g, double _h, double _f, Node* _parent)
    //     :id(_id), g(_g), h(_h), f(_f), parent(_parent) {
    // }
};

#endif