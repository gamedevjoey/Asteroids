#pragma once
#include "sprite.hpp"
#include <vector>

class Model
{
public:
    Model(class App *app);
    bool Initialize();
    void Run();
    void Finalize();
    void HandleClick(int x, int y);
    Sprite *GetShip() { return ship; }
    std::vector<Sprite*>* GetRocks() {return &rocks;} 

private:
    class App *app;
    std::vector<Sprite*> rocks;
    Sprite *ship;
};