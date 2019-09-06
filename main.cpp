#include <iostream>
#include <fstream>
#include "Node.h"

void MakeGridbyFile(std::string path) {
    std::ifstream gridFile(path);
    if(gridFile.is_open()) {
        std::cout << "Success to open " << path << "!" << std::endl;
        std::string line;
        while(line != "EOF") {
            getline(gridFile, line);
            std::cout << line << std::endl;
        }
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
}

int main(int argc, char* args[]) {
    Node node(1, 1.0, 1.0, 1.0, nullptr);
    std::cout << "Hello A*" << std::endl;
    MakeGridbyFile("test.txt");

    return 0;
}