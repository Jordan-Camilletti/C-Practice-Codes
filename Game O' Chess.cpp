/*pg 43*/

#include <iostream>

class Piece{//0=king, 1=queen, 2=rook, 3=knight, 4=bishop, 5=pawn
    public:
        int row, column;
        bool isWhite, isTaken;
        std::string type, types[12]={"K","Q","R","N","B","P","k","q","r","n","b","p"};
        
        void setAll(int setTypeNum, int setRow, int setColumn, bool setIsWhite, bool setIsTaken){
            row=setRow-1;
            column=setColumn-1;
            isWhite=setIsWhite;
            isTaken=setIsTaken;
            if(isWhite){
                type=types[setTypeNum];
            }else{
                type=types[setTypeNum+6];
            }
        }
        
        bool canMoveTo(int moveToRow, int moveToColumn){
            if((row==moveToRow&&column==moveToColumn)||moveToRow<0||moveToColumn<0||moveToRow>=8||moveToColumn>=8){
                return false;
            }else if(type=="K"||type=="k"){
                
            }else if(type=="Q"||type=="q"){
                
            }else if(type=="R"||type=="r"){
                
            }else if(type=="N"||type=="n"){
                
            }else if(type=="B"||type=="b"){
                
            }else if(type=="P"){//moves up
                
            }else if(type=="p"){//moves down
                
            }return true;
        }
};

int main(){
    std::string board[8][8]={
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."}
    };
    Piece whiteKing,whiteQueen, whiteRook1, whiteRook2, whiteKnight1, whiteKnight2, whiteBishop1, whiteBisop2, whitePawn1, whitePawn2, whitePawn3, whitePawn4, whitePawn5, whitePawn6;
    whiteKing.setAll(0,8,5,true,false);
    board[whiteKing.row][whiteKing.column]=whiteKing.type;
    for(int row=0;row<8;row++){for(int column=0;column<8;column++){std::cout<<board[row][column];}std::cout<<"\n";}
    //std::cout<<testKing.canMoveTo(3,4);
    return 0;
}
