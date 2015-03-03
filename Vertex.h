#include <list>

class Vertex {
    // It holds the adjacent vertices
    // Each vertex has at most 4 vertices adjacent to it
    // 0=top,1=right,2=bottom,3=left
    // For each adjacent vertex,we store the vertex number to which this vertex
    // is connected to,else -1
    int adjVertices_[4];

    public: 
        Vertex();//Each cell has atmost 4 cells adjust to it

        std::list<int> get_adjVertices();

};
