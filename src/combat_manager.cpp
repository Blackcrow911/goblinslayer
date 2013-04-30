#include "../include/combat_manager.h"

combat_manager::combat_manager()
{
    m_combat_done = false;
}

bool combat_manager::start_combat(Player &p, enemy &e)
{
    if(p.get_x() == e.get_x() && p.get_y() == e.get_y() && !e.get_dead())
    {
        cout << "A " << e.get_name() << " appeared!!" << endl;
        while(!m_combat_done)
        {
                cout << "What do you want to do(1. attack 2. heal)?";
                cin >> m_combat_choice;
                if(m_combat_choice == 1)
                {
                    p.set_player_var("damage",(rand()%p.get_max_damage())+1);
                    cout << "You hit " << e.get_name() << " for " << p.get_damage() << "!" << endl;
                    e.set_enemy_var("health", e.get_health()-p.get_damage());
                    cout << "MAX DMG: " << p.get_max_damage() << endl;
                }
                else if(m_combat_choice == 2)
                {
                    cout << "You heal for " << p.get_heal_value() << "!" << endl;
                    p.heal_self();
                }
                else
                    cout << "Invalid entry, you lose your turn" << endl;

                //if enemy has max health he won't heal
                if(e.get_health() < e.get_max_health())
                {
                    m_enemy_choice = (rand()%2);
                    if(m_enemy_choice == 0)
                    {
                        e.set_enemy_var("damage",(rand()%e.get_max_damage())+1);
                        cout << e.get_name() << " attacks for " << e.get_damage() << "!" << endl;
                        p.set_player_var("health", p.get_health()-e.get_damage());
                    }
                    else if(m_enemy_choice == 1)
                    {
                        e.heal_self();
                    }
                }
                else
                {
                    e.set_enemy_var("damage",(rand()%e.get_max_damage())+1);
                    cout << e.get_name() << " attacks for " << e.get_damage() << "!" << endl;
                    p.set_player_var("health", p.get_health()-e.get_damage());
                }

                cout << "Your health: " << p.get_health() << endl;
                cout << e.get_name() << " health: " << e.get_health() << endl << endl;

                //Check for death
                if(e.get_health() <= 0)
                     e.set_enemy_var("dead", 1);
                else if(p.get_health() <= 0)
                    p.set_player_var("dead", 1);
                if(e.get_dead() || p.get_dead()){
                    m_combat_done = true;
                }
            }
            if(e.get_dead())
            {
                cout << "Victory! The foul "<< e.get_name() <<" lies slain at your feet!" << endl << endl;
                m_combat_done = false;
                return true;
            }
            else if(p.get_dead())
            {
                cout << "Wow... " << e.get_name() <<" killed you.. GAME OVER" << endl;
                return 0;
            }

        }
    return false;
}
combat_manager::~combat_manager()
{
    //dtor
}
