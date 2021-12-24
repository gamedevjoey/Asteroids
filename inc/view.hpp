#pragma once
#include <SDL.h>

class View 
{
public:
    View(class App* app);
    bool Initialize();
    void Finalize();
    void Run();
private:
    class App* app;
    SDL_Window* window;
    SDL_Renderer* renderer;
    class Model* model;
    SDL_Texture* texture = nullptr;
};

