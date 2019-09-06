#ifndef NODE_H
#define NODE_H

#include <vector>

struct Node {
    unsigned int node_id;
    double g;
    double h;
    double f;
    std::vector<Node*> successors;
    Node* parent;

    Node(int id, double _g, double _h, double _f, Node* _parent)
        :node_id(id), g(_g), h(_h), f(_f), parent(_parent) {
    }
};

#endif