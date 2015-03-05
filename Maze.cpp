#include <iostream>
#include "Maze.h"
#include <stack>
#include <stdlib.h>

bool dfs(Vertex * source,Vertex * destination) {
    std::cout << "Visitng " << source->getId() << std::endl;
    if(source != destination) {
        source->discovered = true;
        auto connectedNeighborList = source->getConnectedNeighbors();
        for(auto it=connectedNeighborList.begin();
                it!=connectedNeighborList.end();it++) {
            if((*it)->discovered != true) {
                if( dfs(*it,destination) ) {
                    return true;
                }
            }
        }
        return false;
    }
    std::cout << "Found destination\n";
    return true;
}

Maze::Maze( int roomsPerSide ) {
    std::cout << "Creating a maze with " << roomsPerSide << " roomsPerSide\n";
    roomsPerSide_ = roomsPerSide;
    v = new Vertex*[roomsPerSide_];//Created Vertices on the heap
    for(int i=0;i<roomsPerSide_;i++) {
        v[i] = new Vertex[roomsPerSide_];
        for(int j=0; j<roomsPerSide_; j++ ) {
            v[i][j].setId( i*roomsPerSide_ + j );
        }
   }
        
    for(int i=0;i<roomsPerSide;i++) {
        for(int j=0;j<roomsPerSide;j++) {
            if(i!=0) {
                Vertex * top = &v[i-1][j];
                v[i][j].addNeighbors(top);
            }
            if(j!=roomsPerSide-1) {
                Vertex * right = &v[i][j+1];
                v[i][j].addNeighbors(right);
            }
            if(i!=roomsPerSide-1) {
                Vertex * bottom = &v[i+1][j];
                v[i][j].addNeighbors(bottom);
            }
            if(j!=0) {
                Vertex * left = &v[i][j-1];
                v[i][j].addNeighbors(left);
            }

            //v[i][j].addNeighbors(top);
            //v[i][j].addNeighbors(right);
            //v[i][j].addNeighbors(bottom);
            //v[i][j].addNeighbors(left);

        }
    }
    CreateMaze(&v[0][0],roomsPerSide*roomsPerSide);
}
Maze::~Maze() {
    for( int i=0; i<roomsPerSide_; i++ ) {
        delete[] v[i];
    }
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
   std::cout<<"prints the neighbors\n";
   for (int i=0;i<roomsPerSide_;i++) {
       for(int j=0;j<roomsPerSide_;j++) {
           v[i][j].print();
       }
   }
}

Maze Maze::traverse_dfs() {

    std::cout<<"traverse using dfs\n";
    dfs(&v[0][0],&v[roomsPerSide_-1][roomsPerSide_-1]);

    return Maze(0);
}

Maze Maze::traverse_bfs() {
    std::cout<<"traverse using bfs\n";
}



void Maze::CreateMaze (Vertex * source,int totalCells) {
    Vertex * currentCell = source;
    int visitedCells = 1;
    std::stack <Vertex *> stack;
    std::list <Vertex *> neighboringCells;
    while (visitedCells<totalCells) {

        neighboringCells = currentCell->getUndiscoveredNeighbors();
        if(neighboringCells.size()) {
        int randomIndex = rand() % neighboringCells.size();//returns random index of the cell in the neighboringCells list
        auto it = std::next(neighboringCells.begin(),randomIndex);
        Vertex* randomVertex = *it;
        currentCell->connectNeighbor(randomVertex);
        randomVertex->connectNeighbor(currentCell);
        stack.push(currentCell);
        currentCell = randomVertex;
        visitedCells += 1;
        }
        else {
            currentCell = stack.top();
            stack.pop();
        }

        //NeighboringCells = GetNeighboringCells(CurrentCell);
    }
        
}


