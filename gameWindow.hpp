#pragma once

#include <iostream>
#include <SDL2/SDL.h>


class gameWindow {

public:
    gameWindow(const char *window_title, int window_width, int window_height);
    void render();
    void cleanUp();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    

};
