#include "Board.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h>
#include <sstream>
#include <FL/Fl_Button.H>

int main(int argc, char *argv[]) {
    Fl_Window *window = new Fl_Window (800,700,"Tetris"); // outer window
    window->color(bgcolor);

    Board *b = new Board();
    Fl_Box *scorebox = new Fl_Box(tilesize*xmaxtiles+20,50,250,100,"Score: 0\0");
    scorebox->box(FL_UP_BOX);
    scorebox->labelfont(FL_BOLD+FL_ITALIC);
    scorebox->labelsize(36);
    scorebox->labeltype(FL_ENGRAVED_LABEL);
    b->setScoreBox(&scorebox); 
    std::string highScoreLabel = "High Score:";
    Fl_Box *highestScoreBox = new Fl_Box(tilesize*xmaxtiles+20,180,250,100,highScoreLabel.c_str());
    highestScoreBox->box(FL_FLAT_BOX);
    highestScoreBox->labelfont(FL_BOLD);
    highestScoreBox->labelsize(24);
    highestScoreBox->labeltype(FL_ENGRAVED_LABEL);
    int highestScore = readHighestScore();
    std::string highestScoreStr = std::to_string(highestScore);
    highScoreLabel += highestScoreStr;
    highestScoreBox->copy_label(highScoreLabel.c_str());
    b->setHighScoreBox(highestScoreBox, highestScore);

    Fl_Button *easyButton = new Fl_Button(700, 300, 80, 40, "Easy");
    easyButton->color(FL_GREEN);
    easyButton->callback(levelChoice, (void*)b);
    easyButton->value(0); // Default value

    Fl_Button *hardButton = new Fl_Button(700, 350, 80, 40, "Hard");
    hardButton->callback(levelChoice, (void*)b);
    hardButton->color(FL_RED);

    window->end();  
    window->show();
    Fl::add_timeout(timeout, timeractions, b);
    return(Fl::run());  // the process waits from here on for events
}

