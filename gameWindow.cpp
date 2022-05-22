#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameWindow.hpp"
#include <sstream>
#include <vector>

gameWindow::gameWindow(const char* p_title, int p_w, int p_h):window(NULL), renderer(NULL)
{

window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
if (window == NULL) std::cout << "Window failed to init: " << SDL_GetError() << std::endl;

renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);


}
void gameWindow::render(){
SDL_SetRenderDrawColor(renderer, 144, 238, 144, 0);


// Clear the entire screen to our selected color.
SDL_RenderClear(renderer);


int pos_x = 120;
int pos_y = 25;
SDL_Rect rect;
    

    
    for (int i=1;i<9; i++){
    for (int j=1; j<9; j++) {
     
    rect.x = pos_x;
    rect.y = pos_y;
    rect.w = 70;
    rect.h = 70;

if(((i+2)%2 != 0) && ((j+2)%2 !=0) || ((i+2)%2 == 0) && ((j+2)%2 ==0)  ) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
     SDL_RenderFillRect(renderer, &rect);
     
         } 
     
else {
    SDL_SetRenderDrawColor(renderer, 255, 255,255, 255);
     SDL_RenderDrawRect(renderer, &rect);
    
     } 
   

    pos_x+= 0;
    pos_y+= 70;
   
    
    }
    pos_x+=70;
    pos_y = 25;

    }

     SDL_RenderPresent(renderer);
 
}
void gameWindow::renderFromFEN(std::string fen){
// for extracting the first part of the FEN
std::string edited_fen = "";

for (int i=0; i<fen.length(); i++){

if(fen[i] == ' '){ break;}
else { edited_fen += fen[i];
}
}
for(int i=0; i<edited_fen.length(); i++){
std::cout << edited_fen[i];
}

//expanding the fen string to indicate the position of the pieces
std::string position_string = "";
int num_of_spaces = 0;

for(int i =0; i<edited_fen.length(); i++){
std::stringstream ss;

if(!(isdigit(edited_fen[i]))) position_string+= edited_fen[i];

if(isdigit(edited_fen[i])){
ss << edited_fen[i];
ss >> num_of_spaces;
for(num_of_spaces; num_of_spaces>0; --num_of_spaces){
position_string += 's';

}
}
}
for(int i=0; i<position_string.length(); i++){
std::cout << position_string[i];
}
// Convert from position_string to fenArray (to be implemented)


char arr1[8],arr2[8],arr3[8],arr4[8],arr5[8],arr6[8],arr7[8],arr8[8];
arr1[0] = position_string[0];
arr1[1] = position_string[1];
arr1[2] = position_string[2];
arr1[3] = position_string[3];
arr1[4] = position_string[4];
arr1[5] = position_string[5];
arr1[6] = position_string[6];
arr1[7] = position_string[7];
arr2[0] = position_string[9];
arr2[1] = position_string[10];
arr2[2] = position_string[11];
arr2[3] = position_string[12];
arr2[4] = position_string[13];
arr2[5] = position_string[14];
arr2[6] = position_string[15];
arr2[7] = position_string[16];
arr3[0] = position_string[18];
arr3[1] = position_string[19];
arr3[2] = position_string[20];
arr3[3] = position_string[21];
arr3[4] = position_string[22];
arr3[5] = position_string[23];
arr3[6] = position_string[24];
arr3[7] = position_string[25];
arr4[0] = position_string[27];
arr4[1] = position_string[28];
arr4[2] = position_string[29];
arr4[3] = position_string[30];
arr4[4] = position_string[31];
arr4[5] = position_string[32];
arr4[6] = position_string[33];
arr4[7] = position_string[34];
arr5[0] = position_string[36];
arr5[1] = position_string[37];
arr5[2] = position_string[38];
arr5[3] = position_string[39];
arr5[4] = position_string[40];
arr5[5] = position_string[41];
arr5[6] = position_string[42];
arr5[7] = position_string[43];
arr6[0] = position_string[45];
arr6[1] = position_string[46];
arr6[2] = position_string[47];
arr6[3] = position_string[48];
arr6[4] = position_string[49];
arr6[5] = position_string[50];
arr6[6] = position_string[51];
arr6[7] = position_string[52];
arr7[0] = position_string[54];
arr7[1] = position_string[55];
arr7[2] = position_string[56];
arr7[3] = position_string[57];
arr7[4] = position_string[58];
arr7[5] = position_string[59];
arr7[6] = position_string[60];
arr7[7] = position_string[61];
arr8[0] = position_string[63];
arr8[1] = position_string[64];
arr8[2] = position_string[65];
arr8[3] = position_string[66];
arr8[4] = position_string[67];
arr8[5] = position_string[68];
arr8[6] = position_string[69];
arr8[7] = position_string[70];


char *fenArr[8] = {arr1,arr2,arr3,arr4,arr5,arr6,arr7,arr8};
char fenArray[8][8]={{0}};

for(int k=0; k<8; ++k){
for(int l=0; l<8; ++l){

fenArray[l][k]=fenArr[k][l];

}}

for(int i=0; i<8; i++){
for(int j=0; j<8; j++){

  std::cout <<  fenArray[i][j];
}
}


int pos_x = 120;
int pos_y = 25;

SDL_Rect rect;

//Images

white_king = IMG_Load("./textures/white_king.png");
white_queen = IMG_Load("./textures/white_queen.png");
white_rook = IMG_Load("./textures/white_rook.png");
white_bishop = IMG_Load("./textures/white_bishop.png");
white_knight = IMG_Load("./textures/white_knight.png");
white_pawn = IMG_Load("./textures/white_pawn.png");

black_king = IMG_Load("./textures/black_king.png");
black_queen = IMG_Load("./textures/black_queen.png");
black_rook = IMG_Load("./textures/black_rook.png");
black_bishop = IMG_Load("./textures/black_bishop.png");
black_knight = IMG_Load("./textures/black_knight.png");
black_pawn = IMG_Load("./textures/black_pawn.png");

//Textures

white_king_tex = SDL_CreateTextureFromSurface(renderer, white_king);
white_queen_tex = SDL_CreateTextureFromSurface(renderer, white_queen);
white_rook_tex = SDL_CreateTextureFromSurface(renderer, white_rook);
white_bishop_tex = SDL_CreateTextureFromSurface(renderer, white_bishop);
white_knight_tex = SDL_CreateTextureFromSurface(renderer, white_knight);
white_pawn_tex = SDL_CreateTextureFromSurface(renderer, white_pawn);

black_king_tex = SDL_CreateTextureFromSurface(renderer, black_king);
black_queen_tex = SDL_CreateTextureFromSurface(renderer, black_queen);
black_rook_tex = SDL_CreateTextureFromSurface(renderer, black_rook);
black_bishop_tex = SDL_CreateTextureFromSurface(renderer, black_bishop);
black_knight_tex = SDL_CreateTextureFromSurface(renderer, black_knight);
black_pawn_tex = SDL_CreateTextureFromSurface(renderer, black_pawn);



//SDL_RenderClear(renderer);

    
    for (int i=0;i<8; i++){
    for (int j=0; j<8; j++) {

   
     
    rect.x = pos_x + 15;
    rect.y = pos_y + 15;
    rect.w = 40;
    rect.h = 40;

char s = fenArray[i][j];

switch(s){

case 'r':
SDL_RenderCopy(renderer, black_rook_tex, NULL, &rect);
break;

case 'b':
SDL_RenderCopy(renderer, black_bishop_tex, NULL, &rect);
break;
case 'n':
SDL_RenderCopy(renderer, black_knight_tex, NULL, &rect);
break;

case 'q':
SDL_RenderCopy(renderer, black_queen_tex, NULL, &rect);
break;

case 'k':
SDL_RenderCopy(renderer, black_king_tex, NULL, &rect);
break;
case 'p':
SDL_RenderCopy(renderer, black_pawn_tex, NULL, &rect);
break;
case 's':
break;
case 'P':
SDL_RenderCopy(renderer, white_pawn_tex, NULL, &rect);
break;
case 'R':
SDL_RenderCopy(renderer, white_rook_tex, NULL, &rect);
break;
case 'N':
SDL_RenderCopy(renderer, white_knight_tex, NULL, &rect);
break;
case 'B':
SDL_RenderCopy(renderer, white_bishop_tex, NULL, &rect);
break;
case 'Q':
SDL_RenderCopy(renderer, white_queen_tex, NULL, &rect);
break;
case 'K':
SDL_RenderCopy(renderer, white_king_tex, NULL, &rect);
break;

}


   

    pos_x+= 0;
    pos_y+= 70;
   
    
    }
    pos_x+=70;
    pos_y = 25;

    }

     SDL_RenderPresent(renderer);
 


}
void gameWindow::cleanUp(){

SDL_DestroyTexture(white_king_tex);
SDL_DestroyTexture(white_queen_tex);
SDL_DestroyTexture(white_rook_tex);
SDL_DestroyTexture(white_bishop_tex);
SDL_DestroyTexture(white_knight_tex);
SDL_DestroyTexture(white_pawn_tex);

SDL_DestroyTexture(black_king_tex);
SDL_DestroyTexture(black_queen_tex);
SDL_DestroyTexture(black_rook_tex);
SDL_DestroyTexture(black_bishop_tex);
SDL_DestroyTexture(black_knight_tex);
SDL_DestroyTexture(black_pawn_tex);


SDL_FreeSurface(white_king);
SDL_FreeSurface(white_queen);
SDL_FreeSurface(white_rook);
SDL_FreeSurface(white_bishop);
SDL_FreeSurface(white_knight);
SDL_FreeSurface(white_pawn);

SDL_FreeSurface(black_king);
SDL_FreeSurface(black_queen);
SDL_FreeSurface(black_rook);
SDL_FreeSurface(black_bishop);
SDL_FreeSurface(black_knight);
SDL_FreeSurface(black_pawn);

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
}
