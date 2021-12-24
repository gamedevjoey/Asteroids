#include "controller.hpp"
#include "app.hpp"
#include <iostream>
#include <SDL.h>

using std::cout;

Controller::Controller(App* app)
        : app(app)
{
    cout << "constructing controller \n";
}

bool Controller::Initialize()
{
    return true;
}

void Controller::Run()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            app->Stop();
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                app->Stop();
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) 
            {
                int x;
                int y;
                SDL_GetMouseState(&x,&y);
                app->GetModel()->HandleClick(x,y);
            }
        }
 	}
}

void Controller::Finalize()
{

}
