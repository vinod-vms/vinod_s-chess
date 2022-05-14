#include <iostream>
#include <SDL2/SDL.h>
#include "gameWindow.hpp"

gameWindow::gameWindow(const char* p_title, int p_w, int p_h):window(NULL), renderer(NULL)
{

window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
if (window == NULL) std::cout << "Window failed to init: " << SDL_GetError() << std::endl;

renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

}
void gameWindow::render(){


//SDL_Rect dstrect = { 200, 50, 160, 120};
int pos_x = 120;
int pos_y = 25;
    SDL_Rect rect;
     SDL_RenderClear(renderer);

    
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
void gameWindow::cleanUp(){
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
}
