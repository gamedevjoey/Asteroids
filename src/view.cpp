#include "view.hpp"
#include "app.hpp"
#include <iostream>
#include <SDL_image.h>
#include "sprite.hpp"

using std::cout;

View::View(App* app)
        : app(app),
          window(nullptr),
          renderer(nullptr),
          model(app->GetModel())
{
    cout << "constructing view \n";
}

bool View::Initialize()
{
    /* Options (which can be joined by | operator) are
        SDL_INIT_TIMER: timer subsystem
        SDL_INIT_AUDIO: audio subsystem
        SDL_INIT_VIDEO: video subsystem; automatically initializes the events
                        subsystem
        SDL_INIT_JOYSTICK: joystick subsystem; automatically initializes the
                           events subsystem
        SDL_INIT_HAPTIC: haptic (force feedback) subsystem
        SDL_INIT_GAMECONTROLLER: controller subsystem; automatically initializes
                                 the joystick subsystem
        SDL_INIT_EVENTS: events subsystem
        SDL_INIT_EVERYTHING: all of the above subsystems
        SDL_INIT_NOPARACHUTE: compatibility; this flag is ignored
    */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("ERROR SDL FAILED TO INITIALIZE: %s", SDL_GetError());
        return false;
    }

    /* Options (which can be joined by | operator) are 
        SDL_WINDOW_FULLSCREEN: fullscreen window
        SDL_WINDOW_FULLSCREEN_DESKTOP: fullscreen window at desktop resolution
        SDL_WINDOW_OPENGL: window usable with an OpenGL context
        SDL_WINDOW_VULKAN: window usable with a Vulkan instance
        SDL_WINDOW_METAL: window usable with a Metal instance
        SDL_WINDOW_HIDDEN: window is not visible
        SDL_WINDOW_BORDERLESS: no window decoration
        SDL_WINDOW_RESIZABLE: window can be resized
        SDL_WINDOW_MINIMIZED: window is minimized
        SDL_WINDOW_MAXIMIZED: window is maximized
        SDL_WINDOW_INPUT_GRABBED: window has grabbed input focus
        SDL_WINDOW_ALLOW_HIGHDPI: window should be created in high-DPI mode if
                                  supported (>= SDL 2.0.1)
    */
    window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
    if (!window) {
        SDL_Log("ERROR SDL FAILED TO CREATE WINDOW: %s", SDL_GetError());
        return false;
    }

    /* Index of the rendering driver to initialize, or -1 to initialize the
    first one supporting the requested flags. */
    /* Options (which can be joined by | operator) are
        SDL_RENDERER_SOFTWARE: the renderer is a software fallback
        SDL_RENDERER_ACCELERATED: the renderer uses hardware acceleration
        SDL_RENDERER_PRESENTVSYNC: present is synchronized with the refresh rate
        SDL_RENDERER_TARGETTEXTURE: the renderer supports rendering to texture
    */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_Log("ERROR SDL FAILED TO CREATE RENDERER: %s", SDL_GetError());
        return false;
    }
    Sprite::SetRenderer(renderer);
    //TODO send to sprite

    /* Options (which can be joined by | operator) are
        IMG_INIT_JPG
        IMG_INIT_PNG
        SDL_INIT_TIF.
    */

    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        SDL_Log("ERROR SDL FAILED TO INIT IMG: %s", SDL_GetError());
        return false;
    }

    model = app->GetModel();

    //testing only
    



    return true; //TODO return false if problem
}

void View::Finalize()
{
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
 	SDL_DestroyWindow(window);
 	SDL_Quit();
}

void View::Run()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
 	SDL_RenderClear(renderer);

    model->GetShip()->RunView();

    std::vector<Sprite*> *rocks = model->GetRocks();

    for (auto rock : *rocks)
    {
        rock->RunView();
    }

    //SDL_Rect rect{100,100,100,100};
    //SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    //SDL_RenderFillRect(renderer,&rect);
    //SDL_Rect rect2{100,100,100,100};
    //SDL_RenderCopyEx(renderer,texture,nullptr,&rect2,45,nullptr,SDL_FLIP_NONE);
 	SDL_RenderPresent(renderer);


    
}