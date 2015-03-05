#include <list>

class Vertex {
    // It holds the adjacent vertices
    // Each vertex has at most 4 vertices adjacent to it
    // 0=top,1=right,2=bottom,3=left
    // For each adjacent vertex,we store the vertex number to which this vertex
    // is connected to,else -1
    int adjVertices_[4];

    int id_;

    std::list<Vertex*> neighbors_;
    std::list<Vertex*> connectedNeighbors_;

    public: 
        Vertex();//Each cell has atmost 4 cells adjust to it

        void setId( int id ) { id_ = id; }
        int getId() { return id_; }

        std::list<int> get_adjVertices();

        std::list<Vertex*> getConnectedNeighbors();

        void addNeighbors(Vertex*);

        void print();

        std::list<Vertex *> getUndiscoveredNeighbors();

        void connectNeighbor(Vertex *);

        bool discovered;
};
