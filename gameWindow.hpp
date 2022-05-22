#pragma once

#include <iostream>
#include <SDL2/SDL.h>


class gameWindow {

public:
    gameWindow(const char *window_title, int window_width, int window_height);
    void render();
    void renderFromFEN(std::string fen);
    void cleanUp();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *black_king,*black_queen,*black_rook,*black_bishop, *black_knight, *black_pawn, *white_king, *white_queen,
    *white_rook, *white_bishop, *white_knight, *white_pawn;
    SDL_Texture *black_king_tex,*black_queen_tex,*black_rook_tex,*black_bishop_tex, *black_knight_tex, *black_pawn_tex, *white_king_tex, *white_queen_tex,
    *white_rook_tex, *white_bishop_tex, *white_knight_tex, *white_pawn_tex;

    

};

