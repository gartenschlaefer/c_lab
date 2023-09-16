// --
// sdl game
// --
// sdl installs 
// header: /usr/local/include/SDL2
// source: /usr/local/lib/libSDL2.so
// build: gcc sdl_game.c -o build/sdl_game -I /usr/local/include/SDL2 -D_REENTRANT -L /usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2

#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "renderer.h"

struct GameLogics
{
  bool runs;
};

struct Game
{
  struct GameLogics *game_logics;
};

void check_input(struct GameLogics *game_logics)
{
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      // key down
      case SDL_KEYDOWN:

        // get key
        switch(event.key.keysym.sym)
        {
          case SDLK_BACKSPACE:
          case SDLK_ESCAPE:
          case SDLK_END: game_logics->runs = false;
            break;

          default: break;
        }
        break;

      // other key type
      default: break;
    }
  }
}


int main(void)
{
  // create game
  struct GameLogics game_logics = { .runs = true };
  struct Game game = { .game_logics = &game_logics };

  // window
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
  //SDL_Delay(2000);

  while(game.game_logics->runs)
  {
    check_input(game.game_logics);
  }

  // destroy
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}