// --
// sdl game
// --
// sdl installs 
// header: /usr/local/include/SDL2
// source: /usr/local/lib/libSDL2.so
// build: gcc sdl_game.c -o build/sdl_game -I /usr/local/include/SDL2 -D_REENTRANT -L /usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2

#include <stdio.h>
#include <SDL.h>
#include "renderer.h"

int main(void)
{
  char w_name[] = "Hello SDL Game";
  printf("window: %s\n", w_name);

  // init SDL
  int init_state = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  printf("\ninit_state: %i\n", init_state);

  // create a window
  SDL_Window* window = SDL_CreateWindow(w_name, 0, 0, 640, 480, 0);

  // get renderer
  SDL_Renderer* renderer = new_renderer(window);

  // draw
  SDL_SetRenderDrawColor(renderer, 200, 200, 0, 0);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  // wait
  SDL_Delay(2000);

  // destroy
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}