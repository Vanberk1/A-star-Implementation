#include "Grid.h"

Grid::Grid() {
    this->nodes = nullptr;
}

void Grid::Initialize(std::string filePath) {
    this->MakeNodes(filePath);
    this->MakeDistanceGrid();
}

void Grid::MakeNodes(std::string filePath) {
    std::string line;
    std::ifstream gridFile;
    gridFile.open(filePath);
    for(int i = 0; i < 4; i++) {
        getline(gridFile, line);
    }
    this->nodesCant = std::atoi(line.substr(line.find(' '), line.length() - 1).c_str());
    std::cout << nodesCant << std::endl;

    this->nodes = new Node[nodesCant];

    if(gridFile.is_open()) {
        std::cout << "Success to open " << filePath << "!" << std::endl;
        bool savingCoordenates = false;
        int nodeIndex = 0;
        while(line != "EOF") {
            if(!savingCoordenates) {
                getline(gridFile, line);
                if(line == "NODE_COORD_SECTION")
                    savingCoordenates = true;
            }
            else {
                getline(gridFile, line);
                if(line != "EOF") {
                    std::stringstream ss;
                    ss << line;
                    std::string aux;
                    int number;
                    bool idReady = false;
                    bool xCoordReady = false;
                    bool yCoordReady = false;

                    while(!ss.eof()) {
                        ss >> aux;
                        if(std::stringstream(aux) >> number) {
                            // std::cout << number << " ";
                            if(!idReady) {
                                this->nodes[nodeIndex].id = number;
                                idReady = true;
                            }
                            else if(!xCoordReady) {
                                this->nodes[nodeIndex].x = number;
                                xCoordReady= true;
                            }
                            else if(!yCoordReady) {
                                this->nodes[nodeIndex].y = number;
                                yCoordReady= true;
                            }
                        }
                        aux = "";
                    }
                    this->nodes[nodeIndex].parent = nullptr;
                    // std::cout << std::endl;
                    nodeIndex++;
                }
            }
        }
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
    gridFile.close();
}

void Grid::MakeDistanceGrid() {
    this->distanceGrid = new float*[size];
    for (int i = 0; i < nodesCant; ++i) {
        this->distanceGrid[i] = new float[nodesCant];
        for(int j = 0; j < nodesCant; j++) {
            this->distanceGrid[i][j] = 0.f;
        }
    }

    for(int i = 0; i < nodesCant; i++) {
        for(int j = i + 1; j < nodesCant; j++) {
            //std::cout << i << " - " << j << std::endl;
            Node aux1 = this->nodes[i];
            Node aux2 = this->nodes[j];
            //std::cout << aux1.id - 1 << " - " << aux2.id - 1 << std::endl;
            float euclideanDistance = sqrt(((aux2.x - aux1.x) * (aux2.x - aux1.x)) + ((aux2.y -aux1.y) * (aux2.y -aux1.y)));
            this->distanceGrid[aux1.id - 1][aux2.id - 1] = euclideanDistance;
            this->distanceGrid[aux2.id - 1][aux1.id - 1] = euclideanDistance;
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            std::cout << this->distanceGrid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Node* Grid::GetMap() const {
    return this->nodes;
}

int Grid::GetSize() const {
    return this->size;
}

int Grid::GetNodesCant() const {
    return this->nodesCant;
}
