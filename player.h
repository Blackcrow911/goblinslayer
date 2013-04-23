#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player
{
    public:
    Player(int health, int damage, int heal, string name);
        string get_name();
        int get_x();
        int get_y();
        int get_prev_x();
        int get_prev_y();
        int get_damage();
        int get_max_damage();
        int get_health();
        int get_heal_value();
        bool get_dead();
        bool has_sword();
        bool has_key();
        bool heal_self();

        bool set_player_var(string var, int val);
        bool set_player_var(string var, string val);
    private:
        string pname;
    int x;
    int y;
    int prevx;
    int prevy;
    int playerhealth;
    int pmaxhealth;
    int playerdmg;
    int pmaxdmg;
    int pheal;
        bool playerdead;
    bool key;
bool sword;

};

#endif
