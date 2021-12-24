#pragma once
#include "controller.hpp"
#include "model.hpp"
#include "view.hpp"


class App
{
public:
    App();
    void Stop();
    Model* GetModel();
private:
    bool Initialize();
    void Run();
    void Finalize();
    Controller controller;
    Model model;
    View view;
    bool isRunning;

};

