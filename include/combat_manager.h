#ifndef COMBAT_MANAGER_H
#define COMBAT_MANAGER_H
#include "../player.h"
#include "enemy.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class combat_manager
{
    public:
        combat_manager();
        bool start_combat(Player &p, enemy &e);
        ~combat_manager();
    private:
        bool m_combat_done;
        int m_combat_choice;
        int m_enemy_choice;
};

#endif // COMBAT_MANAGER_H
