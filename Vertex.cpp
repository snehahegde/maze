#include <iostream>
#include "Vertex.h"
#include <list>


Vertex::Vertex() {
    for(int i=0;i<=3;i++) {
        adjVertices_[i]=-1;
    }
}

std::list<int> Vertex::get_adjVertices() {
    std::list<int> adjVerticesIdList;
    for(int i=0;i<4;i++) {
        if(adjVertices_[i] != -1) {
            adjVerticesIdList.push_back(adjVertices_[i]);
        }
    }        
    return adjVerticesIdList;     
}
               


