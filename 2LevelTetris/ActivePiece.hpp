#ifndef ACTIVE_PIECE_H
#define ACTIVE_PIECE_H 1
#include "Board.hpp"
#include "Tile.hpp"
class Board;
class ActivePiece {//active piece class
    
friend class Board;
Tile tileSet[4];
int color;
int midpointTile;
Board *b; // container board

public:

ActivePiece(Board *container);//constructor of Active piece
bool moveDown ();
bool moveLeft ();
bool moveRight ();
bool rotate(int direction);

};
#endif