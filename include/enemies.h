#ifndef ENEMIES_H
#define ENEMIES_H
#include <vector>
#include "enemy.h"

class enemies
{
    public:
        enemies();
        ~enemies();
    private:
        vector<enemy> m_all_enemies;
};

#endif // ENEMIES_H
