#include "sprite.hpp"

SDL_Renderer *Sprite::renderer;

void Sprite::SetRenderer(SDL_Renderer* renderer)
{
  Sprite::renderer = renderer;
}

Sprite::Sprite(const char* imgFile, float posX, float posY, float posA, float dimX, float dimY, float speed, float traj, float spin)
  : posX(posX),
    posY(posY),
    posA(posA),
    dimX(dimX),
    dimY(dimY),
    speed(speed),
    traj(traj),
    spin(spin)
{
    SDL_Surface* surface = IMG_Load(imgFile);
    if (!surface)
    {
        SDL_Log("ERROR LOADING SURFACE: ");
    }
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    if(!texture)
    {
        SDL_Log("ERROR CREATING TEXTURE: ");
    }
}

void Sprite::RunModel(size_t timeChange)
{
  //TODO
}

void Sprite::RunView()
{
  SDL_Rect rect{(int)posX,(int)posY,(int)dimX,(int)dimY};
  SDL_RenderCopyEx(renderer,texture,nullptr,&rect,posA,nullptr,SDL_FLIP_NONE);
 	SDL_RenderPresent(renderer);
}