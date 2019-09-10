#include <iostream>
#include <string>
#include "Grid.h"

int main(int argc, char* args[]) {
    //Node node(1, 1.0, 1.0, 1.0, nullptr);
    std::cout << "Hello A*" << std::endl;
    Grid* grid = new Grid();
    grid->Initialize("test.txt");

    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         std::cout << grid[j * size + i].id << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}