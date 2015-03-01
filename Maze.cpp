#include <iostream>
#include "Maze.h"

Maze::Maze( int rooms ) {
    std::cout << "Creating a maze with " << rooms << " rooms\n";
    rooms_ = rooms;
}
