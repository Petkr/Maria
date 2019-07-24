#include "Level.hpp"

Level::Level(std::string filename)
{
    m_filename = filename;
    std::istream f(m_filename);

    char c;
    while(f >> std::noskipws >> c)
    {
        switch (c)
        {
            case '.':
                break;
            case 'W':
                walls.push_back(new Wall());
                break;
            case 'O':
                coins.push_back(new Coin());
                break;
            case '#':
                monsters.push_back(new Monster());
                break;
            case 'M':
                if (!mario) mario = new Mario();
                else        throw 0;
                break;
            case 'F':
                if (!flag) flag = new Flag();
                else       throw 0;
                break;
            default:
                break;
        }
    }
    
}