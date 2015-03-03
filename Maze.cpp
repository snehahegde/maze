#include <iostream>
#include "Maze.h"

Maze::Maze( int roomsPerSide ) {
    std::cout << "Creating a maze with " << roomsPerSide << " roomsPerSide\n";
    roomsPerSide_ = roomsPerSide;
    v = new Vertex[roomsPerSide_];//Created Vertices on the heap
    
}

Maze::~Maze() {
    delete[] v;
}


void Maze::print() {
    std::cout<<"Prints the maze\n";
    for(int i=0;i<roomsPerSide_+1;i++) {
        for(int j=0;j<roomsPerSide_;j++) {
            std::cout<<"+";
            std::cout<<"-";
        }
        std::cout<<"+";
        std::cout<<std::endl;
        if(i<roomsPerSide_) {
        for(int k=0;k<roomsPerSide_+1;k++) {
            std::cout<<"| ";
        }
        }
        std::cout<<std::endl;
    }
}

Maze Maze::traverse_dfs() {
    std::cout<<"traverse using dfs\n";
}

Maze Maze::traverse_bfs() {
    std::cout<<"traverse using bfs\n";
}


