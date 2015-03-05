#include <iostream>
#include <stdlib.h>

#include "Maze.h"

int
main( int argc, char* argv[] ) {

    if( argc != 2 ) {
        std::cout << "Usage: " << argv[0] << " <rooms>\n";
        return 1;
    }

    int rooms = atoi( argv[1] );
    Maze m(rooms);
    m.print();


    Maze dfs = m.traverse_dfs();
    //dfs.print();

    //Maze bfs = m.traverse_bfs();
    //bfs.print();
}
