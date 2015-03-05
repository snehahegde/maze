#include <iostream>
#include "Vertex.h"
#include <list>


Vertex::Vertex() {
    discovered = false;
    for(int i=0;i<=3;i++) {
        adjVertices_[i]=-1;
    }
    id_ = -1;
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
               
void Vertex::addNeighbors(Vertex * v) {
    std::cout << "Adding " << v->id_ << " to " << id_ << std::endl;
    neighbors_.push_back(v);
}

void Vertex::print() {
    // std::cout << "Printing " << id_ << std::endl;
    // for(auto i=neighbors_.begin();i!=neighbors_.end();i++) {
    //     std::cout << (*i)->id_ << " ";
    // }
    std::cout << std::endl;

    std::cout << "Printing connected neighbors" << id_ << std::endl;
    for(auto i=connectedNeighbors_.begin();i!=connectedNeighbors_.end();i++) {
        std::cout << (*i)->id_ << " ";
    }
    std::cout << std::endl;
}

std::list<Vertex * > Vertex::getUndiscoveredNeighbors() {
   std::list <Vertex * > undiscoveredList;
   for(auto i=neighbors_.begin();i!=neighbors_.end();i++) {
       if((*i)->connectedNeighbors_.size() == 0) {
           undiscoveredList.push_back(*i);
       }
   }    
   return undiscoveredList;
}

void Vertex::connectNeighbor(Vertex * v) {
    connectedNeighbors_.push_back(v);
}

std::list<Vertex *> Vertex::getConnectedNeighbors() {
    return connectedNeighbors_;
}


