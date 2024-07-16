#ifndef TILE_H 
#define TILE_H 1
struct Tile {
    // x and y position of a given tile on board matrix
    int x; int y;
};

void ts_down (Tile ts[4]);
void ts_right (Tile ts[4]);
void ts_left (Tile ts[4]);
void ts_copy (Tile in[4], Tile out[4]);
void ts_rotate(Tile ts[4], int centerTile, int direction);
#endif