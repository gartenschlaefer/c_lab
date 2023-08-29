// --
// renderer

#include <stdio.h>
#include <SDL.h>

SDL_Renderer* new_renderer(SDL_Window* window)
{
  // renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  return renderer;
}
