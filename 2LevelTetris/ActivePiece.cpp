#include "ActivePiece.hpp"
ActivePiece::ActivePiece(Board *container) {
int r = rand()%7;
int c = (int) (xmaxtiles/2); //xcenter
b = container;

switch(r) {
        case 0:
        
            tileSet[0].x=c-2; tileSet[0].y=0; // horizontal 
            tileSet[1].x=c-1; tileSet[1].y=0;
            tileSet[2].x=c; tileSet[2].y=0;
            tileSet[3].x=c+1; tileSet[3].y=0;
            midpointTile = 2;
            break;
            
        case 1:
        
            tileSet[0].x=c; tileSet[0].y=0; // Inverted T
            tileSet[1].x=c-1; tileSet[1].y=1;
            tileSet[2].x=c; tileSet[2].y=1;
            tileSet[3].x=c+1; tileSet[3].y=1;
            midpointTile = 2;
            break;  

        case 2:
        
            tileSet[0].x=c-1; tileSet[0].y=0; // a "four" shaped fig
            tileSet[1].x=c-1; tileSet[1].y=1;
            tileSet[2].x=c; tileSet[2].y=1;
            tileSet[3].x=c; tileSet[3].y=2;
            midpointTile = 2;
            break;
            
        case 3:
        
            tileSet[0].x=c; tileSet[0].y=0; // L shaped 
            tileSet[1].x=c; tileSet[1].y=1;
            tileSet[2].x=c; tileSet[2].y=2;
            tileSet[3].x=c+1; tileSet[3].y=2;
            midpointTile = 2;
            break;  

        case 4:
        
            tileSet[0].x=c+1; tileSet[0].y=0; // mirror image of seven
            tileSet[1].x=c; tileSet[1].y=0;
            tileSet[2].x=c; tileSet[2].y=1;
            tileSet[3].x=c; tileSet[3].y=2;
            midpointTile = 2;
            break;
            
        case 5:
        
            tileSet[0].x=c+1; tileSet[0].y=0; // mirror image of four
            tileSet[1].x=c+1; tileSet[1].y=1;
            tileSet[2].x=c; tileSet[2].y=1;
            tileSet[3].x=c; tileSet[3].y=2;
            midpointTile = 2;
            break;  

        case 6:
        
            tileSet[0].x=c-1; tileSet[0].y=0; // square
            tileSet[1].x=c; tileSet[1].y=0;
            tileSet[2].x=c; tileSet[2].y=1;
            tileSet[3].x=c-1; tileSet[3].y=1;
            midpointTile = -1;
            break;
        }       //switch ends
        
        color = 100 + rand()%50;
        if(color == bgcolor){color = color + 170;}

}//function ends


bool ActivePiece::moveRight () {            //functions to update the co-ordinate array according to keypress
            Tile proposedSet[4];
            ts_copy(tileSet, proposedSet);
            ts_right(proposedSet);
            
            if (b->isFree(proposedSet)) {
                
                ts_copy(proposedSet, tileSet);
                return true;
            }
            
            else return false;
}

bool ActivePiece::moveLeft () {
            Tile proposedSet[4];
            ts_copy(tileSet, proposedSet);
            ts_left(proposedSet);
            
            if (b->isFree(proposedSet)) {
                
                ts_copy(proposedSet, tileSet);
                return true;
            }
            
            else return false;
}

bool ActivePiece::moveDown () {
            Tile proposedSet[4];
            ts_copy(tileSet, proposedSet);
            ts_down(proposedSet);
            
            if (b->isFree(proposedSet)) {
                
                ts_copy(proposedSet, tileSet);
                return true;
            }
            
            else return false;
}

bool ActivePiece::rotate (int direction) {
            Tile proposedSet[4];
            ts_copy(tileSet, proposedSet);
            ts_rotate(proposedSet,midpointTile,direction);
            
            if (b->isFree(proposedSet)) {
                
                ts_copy(proposedSet, tileSet);
                return true;
            }
            
            else return false;
}
