#ifndef BOARD_H
#define BOARD_H 1
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <FL/Fl_Button.H>
#include "ActivePiece.hpp"
#include "Tile.hpp"
static const int tilesize = 30; //constants required
static const int xmaxtiles= 14;
static const int ymaxtiles= 20;
static const int bgcolor= 0;
static double timeout = 0.3; // Adjusted based on the level
static const double easyTimeout = 0.5;
static const double hardTimeout = 0.1;
void levelChoice(Fl_Widget*, void*);
void timeractions(void *);
class ActivePiece;
int readHighestScore();
class Board : public Fl_Widget {
    
int occup[xmaxtiles][ymaxtiles];// shows color different than bgcolor if occupied

ActivePiece *p,*q;

int score, highestScore; // score variable,incremented by 10 for a complete row
char* scoreLabel; // label used to display the score
Fl_Box *scoreBox, *highScoreBox;// private member of class for scorebox
std::string highScoreLabel;
public:

    Board();
    
    bool active; //status of active piece
    bool down;  //if moving down is permissible or not
    int periodic();
    void setScoreBox(Fl_Box** sb); //to set scorebox pointer to class member
    void setHighScoreBox(Fl_Box* hsb, int highestScore);
    bool isFree(Tile ts[4]); // before moving down
    bool touchdown(Tile ts[4]) ; // check for touchdown
    void transferTiles();// updation of occup array
    void deleteRow(int row);
    bool rowDone(int row);
    void draw();
    int handle(int e);// keypress events
};  

#endif