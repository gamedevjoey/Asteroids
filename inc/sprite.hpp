#pragma once

#include <SDL_image.h>
#include <SDL.h>

class Sprite
{
public:
  Sprite(const char *imgFile, float posX, float posY, float posA, float dimX, float dimY, float speed, float traj, float spin);
  void RunModel(size_t timeChange);
  void RunView();
  static void SetRenderer(SDL_Renderer* renderer);

  static SDL_Renderer *renderer;
private:
  SDL_Texture *texture;
  float posX;
  float posY;
  float posA;
  float dimX;
  float dimY;
  float speed;
  float traj;
  float spin;

};