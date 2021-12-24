#pragma once

class Controller 
{
public:
    Controller(class App* app);
    bool Initialize();
    void Run();
    void Finalize();
private:
    class App* app;
};