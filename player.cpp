
#include "player.h"
Player::Player(int health, int damage, int heal, string name)
{
            x = 0;
            y = 0;
            prevx = 0;
            prevy = 0;
            playerhealth = health;
            pmaxhealth = health;
            playerdmg = 0;
            pmaxdmg = damage;
            pheal = heal;
            playerdead = 0;
            key = 0;
            sword = 0;
            pname = name;
            playerdead = false;


}

string Player::get_name()
{
    return pname;
}
int Player::get_x()
{
   return x;
}

int Player::get_y()
{
    return y;
}

int Player::get_prev_x()
{
    return prevx;
}

int Player::get_prev_y()
{
    return prevy;
}

int Player::get_damage()
{
    return playerdmg;
}

int Player::get_max_damage()
{
    return pmaxdmg;
}

int Player::get_health()
{
    return playerhealth;
}
int Player::get_heal_value()
{
    return pheal;
}

bool Player::has_sword()
{
    return sword;
}

bool Player::has_key()
{
    return key;
}

bool Player::get_dead()
{
    return playerdead;
}

bool Player::heal_self()
{
    playerhealth += pheal;
    if(playerhealth > pmaxhealth)		//makes sure the player doesnt heal above max health
        playerhealth = pmaxhealth;

    return true;
}

bool Player::set_player_var(string var, int val)
{
    if(var == "x")
        x = val;
    else if(var == "y")
        y = val;
    else if(var == "prevx")
        prevx = val;
    else if(var == "prevy")
        prevy = val;
    else if(var == "sword")
        sword = val;
    else if(var == "key")
        key = val;
    else if(var == "health")
      playerhealth = val;
    else if(var == "maxdamage")
      pmaxdmg = val;
    else if(var == "damage")
       playerdmg = val;
    else if(var == "dead")
        playerdead = val;
    else
       return false;

       return true;
}

bool Player::set_player_var(string var, string val)
{
    if(var == "name")
        pname = val;
    else
        return false;

    return true;
}
