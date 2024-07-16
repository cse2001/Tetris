#include "Board.hpp"
using namespace std;

// Function to read the highest score from a file
int readHighestScore() {
    std::ifstream infile("highest_score.txt");
    int highestScore = 0;
    if (infile.is_open()) {
        infile >> highestScore;
        infile.close();
    }
    return highestScore;
}

// Function to write the highest score to a file
void writeHighestScore(int score) {
    std::ofstream outfile("highest_score.txt");
    if (outfile.is_open()) {
        outfile << score;
        outfile.close();
    }
}
Board::Board(): Fl_Widget (0,0,800,700,"Tetris"), highScoreLabel("High Score:")
{       //constructor of board
             
             p=new ActivePiece(this);
             q=new ActivePiece(this);
             for(int i=0;i<xmaxtiles;i++){                     //default grid created
                    for(int j=0;j<ymaxtiles;j++) {occup[i][j] = bgcolor;}
            }
}


void Board::transferTiles(){               //updates the occup array i.e changes the color of grid
        
        for(int i=0;i<4;i++){
            if(occup[p->tileSet[i].x][p->tileSet[i].y]!=bgcolor){cout<<"SORRY :( ...GAME OVER!!!"<<endl; exit(0);}
            occup[p->tileSet[i].x][p->tileSet[i].y]=p->color;
        }
}       
        
        
bool Board::rowDone(int r){             //checks whether the row is completely filled or not
    
         for (int i=0;i<xmaxtiles;i++){
         if(occup[i][r]== bgcolor){return false;}
        }
        
    return true;
}

void Board::deleteRow(int r){            //deletes the row and refreshes color array
    int row = r;
    for(int j=r;j>0;j--){
         for (int i=0;i<xmaxtiles;i++){
          occup[i][j]=occup[i][j-1];
     }
         
     }
     for (int i=0;i<xmaxtiles;i++){
          occup[i][0]=bgcolor;}
 
}       
        
bool Board::isFree(Tile ts[4]){            //checks for availability and restrictions on the piece
            
    for(int i=0;i<4;i++){if(ts[i].x>=xmaxtiles||ts[i].x<0){return false;}
        if(ts[i].y>=ymaxtiles||ts[i].y<0){return false;}
        if(occup[ts[i].x][ts[i].y]!=bgcolor){return false;}
    }
    return true;
}

void Board::setScoreBox(Fl_Box** sb)        //for the scorebox
{
    scoreBox = *sb ;
    score=0;
    scoreLabel = (char*) malloc(sizeof(char)*10);
}
void Board::setHighScoreBox(Fl_Box* hsb, int highScore){
    highScoreBox = hsb;
    highestScore = highScore;
}
void Board::draw () {                    // drawing function
    fl_color(80);
    for(int i=0;i<4;i++){
        fl_line(0,ymaxtiles*tilesize+i*0.25,xmaxtiles*tilesize,ymaxtiles*tilesize+i*0.25);
    }
    
    for(int i=0;i<4;i++){
        fl_line(xmaxtiles*tilesize+i*0.25,0,xmaxtiles*tilesize+i*0.25,ymaxtiles*tilesize);
    }
    
    for(int j=0;j<ymaxtiles;j++){
        if(rowDone(j)){score=score+10;deleteRow(j);} //checks for any completed row 
    }
    
        for (int i=0; i<xmaxtiles;i++){
        for (int j=0; j<ymaxtiles;j++)
            {fl_draw_box(FL_BORDER_BOX,i*tilesize,j*tilesize,// draws the occupied color array
                tilesize,tilesize,occup[i][j]);
            }
        }
        for(int i=0;i<4;i++){
            if(down){fl_draw_box(FL_BORDER_BOX,p->tileSet[i].x*tilesize,p->tileSet[i].y*tilesize,tilesize,tilesize,p->color);}
            

            }   
    }

void timeractions(void *b) {            //timeout function
    ((Board *)b)->periodic ();
}

int Board::periodic() {
    
        down = p->moveDown();
    
    if(!down){transferTiles();
        p=q;
        for(int i=0;i<4;i++){
        fl_draw_box(FL_FLAT_BOX,(q->tileSet[i].x+xmaxtiles/2+3)*tilesize,(q->tileSet[i].y+ymaxtiles/2+3)*tilesize,tilesize,tilesize,bgcolor);
        }
        q=new ActivePiece(this);
        }
    
    redraw();
    Fl::repeat_timeout (timeout,timeractions,this);
    return 0;
    
}

int Board::handle(int e) {
    if (e == FL_KEYDOWN || e == FL_KEYUP) {
        switch (Fl::event_key()) {
            case FL_Left:
                p->moveLeft();
                redraw();
                break;
            case FL_Up:
                p->rotate(-1);
                redraw();
                break;
            case FL_Right:
                p->moveRight();
                redraw();
                break;
            case FL_Down:
                p->rotate(1);
                redraw();
                break;
            case ' ':
                while(p->moveDown()) {
                    p->moveDown();
                    redraw();
                }
                break;
        }
        stringstream strs;
        strs << score;
        string temp_str = strs.str();
        strcpy(scoreLabel,"Score: ");
        strcat(scoreLabel,(char*) temp_str.c_str() );
        scoreBox->label(scoreLabel);
        if (score > highestScore) {
            highestScore = score;
            writeHighestScore(highestScore);
        // Update the displayed highest score
            std::string highestScoreStr = std::to_string(highestScore);
            highestScoreStr = highScoreLabel +  highestScoreStr;
            highScoreBox->copy_label(highestScoreStr.c_str());
        }

    }
    return 0;
}
void levelChoice(Fl_Widget* widget, void* data) {
    Board* board = (Board*)data;
    Fl_Button* button = (Fl_Button*)widget;
    if (strcmp(button->label(), "Easy") == 0) {
        timeout = easyTimeout;
    } else if (strcmp(button->label(), "Hard") == 0) {
        timeout = hardTimeout;
    }
    Fl::remove_timeout(timeractions, board);
    Fl::add_timeout(timeout, timeractions, board);
}