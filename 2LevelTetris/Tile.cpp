#include "Tile.hpp"
void ts_down (Tile ts[4]){                      //functons to shift co-ordinates
    for (int i=0; i<4; i++) ts[i].y++;
}
void ts_right (Tile ts[4]) {
    for(int i=0;i<4;i++) ts[i].x++;
}
void ts_left (Tile ts[4]) {
    for(int i=0;i<4;i++) ts[i].x--;
}
void ts_copy (Tile in[4], Tile out[4]) {
    for(int i=0;i<4;i++)
     {out[i].x = in[i].x; out[i].y = in[i].y;}
}
void ts_rotate(Tile ts[4], int centerTile, int direction) {       // direction: counter(-1), clock(1)
    if(centerTile==2){
    
    for(int i=0;i<4;i++){
        int tmpx = ts[i].x,tmpy = ts[i].y;
        
        if(direction == -1){
            ts[i].x = ts[centerTile].x - (tmpy - ts[centerTile].y);
            ts[i].y = ts[centerTile].y + (tmpx - ts[centerTile].x);
        }
        
        if(direction == 1){
            ts[i].x = ts[centerTile].x + (tmpy - ts[centerTile].y);
            ts[i].y = ts[centerTile].y - (tmpx - ts[centerTile].x);
        }
    }//for loop ends
    }// if loop ends
}//function ends