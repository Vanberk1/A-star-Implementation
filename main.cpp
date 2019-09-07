#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

void MakeGridbyFile(std::string path) {
    std::string line;
    std::ifstream gridFile;
    gridFile.open(path);
    for(int i = 0; i < 4; i++) {
        getline(gridFile, line);
    }
    int nodesCant = std::atoi(line.substr(line.find(' '), line.length() - 1).c_str());
    std::cout << nodesCant << std::endl;

    int grid[nodesCant][nodesCant];

    if(gridFile.is_open()) {
        std::cout << "Success to open " << path << "!" << std::endl;
        bool savingCoordenates = false;
        while(line != "EOF") {
            if(!savingCoordenates) {
                getline(gridFile, line);
                if(line == "NODE_COORD_SECTION")
                    savingCoordenates = true;
            }
            else {
                getline(gridFile, line);
                if(line != "EOF") {
                    
                }
            }
        }
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
    gridFile.close();
}

int main(int argc, char* args[]) {
    Node node(1, 1.0, 1.0, 1.0, nullptr);
    std::cout << "Hello A*" << std::endl;
    MakeGridbyFile("test.txt");

    return 0;
}