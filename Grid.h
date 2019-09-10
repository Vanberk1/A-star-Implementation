#ifndef GRID_H
#define GRID_H

#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
#include "Node.h"

class Grid {
private:
    int nodesCant;
    int size;
    Node* nodes;
    float** distanceGrid;

public:
    Grid();
    void Initialize(std::string filePath);
    void MakeNodes(std::string filePath);
    void MakeDistanceGrid();
    Node* GetMap() const;
    int GetSize() const;
    int GetNodesCant() const;
};

#endif