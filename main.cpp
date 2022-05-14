#include <iostream>
#include <SDL2/SDL.h>
#include "gameWindow.hpp"



int main(int argc, char** argv){

if (SDL_Init(SDL_INIT_VIDEO) > 0) std::cout << "Error! Unable to initialize SDL2\n";

gameWindow win("Vinod's Chess'_v_1.0", 800, 600);
win.render();
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

