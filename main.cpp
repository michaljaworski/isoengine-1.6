#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Engine* engine = new Engine();

    try
    {
        engine->Go();
    } catch(char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return EXIT_SUCCESS;
}
