#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameWindow.hpp"
#include <vector>



int main(int argc, char** argv){

if (SDL_Init(SDL_INIT_VIDEO) > 0) std::cout << "Error! Unable to initialize SDL2\n";
if (!IMG_Init(IMG_INIT_PNG)){
     std::cout << "Problem with Image initialization " <<SDL_GetError() << std::endl;  
           }

gameWindow win("Vinod's Chess'_v_1.0", 800, 600);
win.render();
win.renderFromFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
bool gameRunning = true;
SDL_Event event;

while(gameRunning){
while(SDL_PollEvent(&event)){
if (event.type == SDL_QUIT) gameRunning = false;
}
}

win.cleanUp();
SDL_Quit();

return 0;
}


