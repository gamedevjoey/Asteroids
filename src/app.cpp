#include "app.hpp"
#include <iostream>

using std::cout;


App::App()
        : controller(this),
          model(this),
          view(this),
          isRunning(true)
{
    cout << "constructing app \n";
    if (Initialize())
    {
        Run();
    }
    Finalize();
}

void App::Stop()
{
    isRunning = false;
}

bool App::Initialize()
{
    return (view.Initialize() && controller.Initialize() && model.Initialize());
}

void App::Run()
{
    while (isRunning)
    {
        controller.Run();
        model.Run();
        view.Run();
        isRunning = false;
    }
    while (true);
}

void App::Finalize()
{
    model.Finalize();
    controller.Finalize();
    view.Finalize();
}

Model* App::GetModel()
{
    return &model;
}