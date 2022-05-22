#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameWindow.hpp"
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


//SDL_Rect dstrect = { 200, 50, 160, 120};
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
//expanding the fen string to indicate the position of the pieces
std::string position_string = "";
int num_of_spaces = 0;

for(int i =0; i<edited_fen.length(); i++){
std::stringstream ss;

if(isdigit(edited_fen[i])){
ss << edited_fen[i];
ss >> num_of_spaces;
}
else{
position_string+= edited_fen[i];
}

for(int i= 0; i < num_of_spaces; i++){
position_string += 's';

}

num_of_spaces = 0;
}

// Convert from position_string to fenArray (to be implemented)
std::vector <std::string> fenArray = {"rpssssPR","npssssPN","bpssssPB","qpssssPQ","kpssssPK","bpssssPB","npssssPN","rpssssPR " };


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

