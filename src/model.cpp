#include "model.hpp"
#include "app.hpp"
#include <iostream>
#include "math.hpp"

using std::cout;

Model::Model(App* app)
        : app(app)
{
    cout << "constructing model \n";
}

bool Model::Initialize()
{
    ship = new Sprite("./assets/player.png", 200.0f, 200.0f, 90.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f);

    for (int i = 0;  i < 10; i++)
    {
        float size = Math::GetRandFloat(20.0f,180.0f);

        rocks.emplace_back( new Sprite(
            "./assets/rock.png",
            Math::GetRandFloat(0.0f,1024.0f),
            Math::GetRandFloat(0.0f,768.0f),
            Math::GetRandFloat(0.0f,360.0f),
            size,size,0,0,0));
    }
    return true;
}

void Model::Run()
{
    //TODO timestop
}

void Model::Finalize()
{

}
void Model::HandleClick(int x, int y)
{
    cout << "handling click at " << x << " , " << y << "\n";
}