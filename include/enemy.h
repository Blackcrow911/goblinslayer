#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class enemy
{
    public:
        enemy(string name, int x,int y,int health,int damage,int heal_value);
        string get_name();
        int get_x();
        int get_y();
        int get_damage();
        int get_max_damage();
        int get_health();
        int get_max_health();
        int get_heal_value();
        bool heal_self();

        bool get_dead();
        bool set_enemy_var(string var, int val);
        ~enemy();
    private:
        string m_name;
        int m_x, m_y,m_health,m_max_health,m_damage,m_max_damage,m_heal_value;
        bool m_dead;
};

#endif // ENEMY_H
