#include "Vertex.h"

class Maze {

    public:
        Maze( int rooms );
        ~Maze();
        void print();
        Maze traverse_dfs();
        Maze traverse_bfs();


    private:
        int roomsPerSide_;
        Vertex * v;
};

