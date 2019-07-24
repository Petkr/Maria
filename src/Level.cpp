#include "Level.hpp"

Level::Level(const std::string& filename)
{
    std::ifstream f(filename);

    char c;
    while(f >> std::noskipws >> c)
    {
        switch (c)
        {
            case '.':
                break;
            case 'W':
                //walls.push_back(new Wall());
                break;
            case 'O':
                //coins.push_back(new Coin());
                break;
            case '#':
                //monsters.push_back(new Monster());
                break;
            case 'M':
                //if (!mario)
                //    mario = new Mario();
                //else
                //    throw 0;
                break;
            case 'F':
                //if (!flag)
                //    flag = new Flag();
                //else
                //    throw 0;
                break;
            default:
                break;
        }
    }
    
}