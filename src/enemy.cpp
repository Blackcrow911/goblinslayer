#include "../include/enemy.h"

enemy::enemy(string name, int x,int y,int health,int damage,int heal_value)
{
    m_name = name;
    m_x = x;
    m_y = y;
    m_health = health;
    m_max_health = health;
    m_damage = damage;
    m_max_damage = damage;
    m_heal_value = heal_value;
    m_dead = 0;
}

string enemy::get_name()
{
    return m_name;
}
int enemy::get_x()
{
    return m_x;
}
int enemy::get_y()
{
    return m_y;
}
int enemy::get_damage()
{
    return m_damage;
}

int enemy::get_max_damage()
{
    return m_max_damage;
}
int enemy::get_health()
{
    return m_health;
}

int enemy::get_max_health()
{
    return m_max_health;
}
int enemy::get_heal_value()
{
    return m_heal_value;
}
bool enemy::heal_self()
{
    int healed;
    healed = rand() % m_heal_value + 1;
    m_health += healed;
    cout << m_name << " healed for " << healed << endl;
    if(m_health > m_max_health)
        m_health = m_max_health;

    return true;
}

bool enemy::get_dead()
{
    return m_dead;
}

bool enemy::set_enemy_var(string var, int val)
{
    if(var == "x")
        m_x = val;
    else if(var == "y")
        m_y = val;
    else if(var == "health")
      m_health = val;
    else if(var == "damage")
       m_damage = val;
    else if(var == "dead")
        m_dead = val;
    else
       return false;

       return true;
}

enemy::~enemy()
{
    //dtor
}
