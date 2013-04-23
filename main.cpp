#include <iostream>
#include<string>
#include<cstdlib>
#include "player.h"
using namespace std;

int main()

{
    string choice;
    string pname;
    //GRID SIZE
    const int len = 3;
    const int hi = 3;
    //Finish vars
    bool done = 0;
    bool cdone = 0;
    bool bdone = 0;
    int comchoice;

    //Monster vars
    int gobchoice;
    int goblinhealth = 20;
    int gmaxhealth = 20;
    int goblindmg;
    int gobheal;
    bool gobdead = 0;
    int gobx = rand()%3;	//goblin will start on a random square
    int goby = rand()%3;
    int bhealth = 100;        // walking talking penis
    int bmaxhealth = 100;
    int bdmg = 10;
    bool bdead = 0;
    cout << "Enter your name: ";
    getline(cin, pname);

    cout << "You are "<< pname << " the goblin slayer.\nYour goal is to make it to the end of the maze with the key and kill the goblin." << endl;

    //Create player object
    Player player(100,5,15, pname);

    //Main game loop
    while(!done)
    {
    cout << "Go left or right or up or down?";
    cin >> choice;
    player.set_player_var("prevx", player.get_x());
    player.set_player_var("prevy", player.get_y());
    if(choice == "right" && player.get_x() != len)
        player.set_player_var("x", player.get_x()+1);
    else if(choice == "right" && player.get_x() == len)
        cout << "Can't go any further right" << endl;
    else if(choice =="left" && player.get_x() != 0)
        player.set_player_var("x", player.get_x()-1);
    else if(choice == "left" && player.get_x() == 0)
        cout << "Can't go any further left" << endl;
    else if(choice == "up" && player.get_y() != hi)
        player.set_player_var("y", player.get_y()+1);
    else if(choice == "up" && player.get_y() == hi)
        cout << "Can't go any further up" << endl;
    else if(choice =="down" && player.get_y() != 0)
        player.set_player_var("y", player.get_y()-1);
    else if(choice == "down" && player.get_y() == 0)
        cout << "Can't go any further down" << endl;
    else if(choice == "pos")
        cout << player.get_x() << " " << player.get_y() << endl;
    else if(choice == "gpos")
        cout << gobx << " " << goby << endl;
    else
        cout << "invalid entry" << endl;

    gobx = rand()%3;		//walkin goblin
    goby = rand()%3;

        //EVENTS
        if(player.get_x() == len && player.get_y() == hi && player.has_key())	//Victory
            done = 1;

        if(player.get_x() == 2 && player.get_y() == 3)			//Trap
        {
            cout << "ITS A TRAPPP" << endl;
            cout << "You are sent back to start loser" << endl;
            player.set_player_var("x",0);
            player.set_player_var("y",0);
        }
        if(player.get_x() == 0 && player.get_y() == 3 && !player.has_key())		//Get key
        {
            cout << "You got the KEYY" << endl;
            player.set_player_var("key", 1);
        }
        if(player.get_x() == 3 && player.get_y() == 3 && !player.has_key())		//Locked door at Victory
        {
            cout << "This door is locked find the key" << endl;
            player.set_player_var("x", player.get_prev_x());
            player.set_player_var("y", player.get_prev_y());
        }

        if(player.get_x() == 3 && player.get_y() == 0 && !player.has_sword())
        {
					cout << "You found the sword of HE MAN, YOU HAVE THE POWER!!" << endl; // sword
					cout << "+30 Max dmg up!!" << endl;
                    player.set_player_var("maxdamage", player.get_damage()+30);
            player.set_player_var("sword", 1);
        }

        //Goblin attack
        if(player.get_x() == gobx && player.get_y() == goby && !gobdead)
        {
            cout << "ITS A GOBLIN!!" << endl;
            while(!cdone)	//While goblin and player are alive
            {
                cout << "What do you want to do(1. attack 2. heal)?";
                cin >> comchoice;

                if(comchoice == 1)
                {
                    player.set_player_var("damage",(rand()%player.get_max_damage())+1);
                    cout << "You hit the goblin for " << player.get_damage() << "!" << endl;
                    goblinhealth -= player.get_damage();
                    cout << "MAX DMG: " << player.get_max_damage() << endl;
                }
                else if(comchoice == 2)
                {
                    cout << "You heal for " << player.get_heal_value() << "!" << endl;
                    player.heal_self();
                }
                else
                    cout << "Invalid entry, you lose your turn" << endl;

                if(goblinhealth < 20)		//if goblin has max health he won't heal
                {
                    gobchoice = (rand()%2);
                    if(gobchoice == 0)
                    {
                    goblindmg = (rand()%3)+1;
                    cout << "Goblin attacks for " << goblindmg << "!" << endl;
                    player.set_player_var("health", player.get_health()-goblindmg);
                    }
                    else if(gobchoice == 1)
                    {
                    gobheal = (rand()%2)+1;
                    cout << "Goblin heals for " << gobheal << "!" << endl;
                    goblinhealth += gobheal;

                    if(goblinhealth > gmaxhealth)		//makes sure the goblin cant heal above his max health
                        goblinhealth = gmaxhealth;
                    }
                }
                else
                {
                    goblindmg = rand()%3;
                    cout << "Goblin attacks for " << goblindmg << "!" << endl;
                    player.set_player_var("health", player.get_health()-goblindmg);
                }

                cout << "Your health: " << player.get_health() << endl;
                cout << "Goblin health: " << goblinhealth << endl << endl;

                if(goblinhealth <= 0)		//check gob dead
                    gobdead = 1;
                else if(player.get_health() <= 0)
                    player.set_player_var("dead", 1);
                if(gobdead || player.get_dead()){
                    cdone = 1;
                }
            }
            if(gobdead)
                cout << "Victory! The foul goblin lies slain at your feet!" << endl;
            else if(player.get_dead())
            {
                cout << "Wow... a goblin killed you.. GAME OVER" << endl;
                return 0;
            }
        }

        //Penis Boss attack
        if(player.get_x() == 3 && player.get_y() == 2 && !bdead)
        {
            cout << "ITS A WALKING TALKING PENIS!!" << endl;
            while(!bdone)	//While boss and player are alive
            {
                cout << "What do you want to do(1. attack 2. heal)?";
                cin >> comchoice;

                if(comchoice == 1)
                {
                    player.set_player_var("damage",(rand()%player.get_max_damage())+1);
                    cout << "You hit the WALKING TALKING PENIS for " << player.get_damage() << "!" << endl;
                    bhealth -= player.get_damage();
                    cout << "MAX DMG: " << player.get_max_damage() << endl;
                }
                else if(comchoice == 2)
                {
                    cout << "You heal for " << player.get_heal_value() << "!" << endl;
                    player.heal_self();
                }
                else
                    cout << "Invalid entry, you lose your turn" << endl;


                    bdmg = (rand()%20)+1;
                    cout << "WALKING TALKING PENIS hits you for " << bdmg << "!" << endl;
                    player.set_player_var("health", player.get_health()-bdmg);


                cout << "Your health: " << player.get_health() << endl;
                cout << "WALKING TALKING PENIS health: " << bhealth << endl << endl;

                if(bhealth <= 0)		//check penis dead
                    bdead = 1;
                else if(player.get_health() <= 0)
                    player.set_player_var("dead", 1);
                if(bdead || player.get_dead())
                {
                    bdone = 1;
                }
            }
            if(bdead)
                cout << "Victory! you must of hacked. :(!" << endl;
            else if(player.get_dead())
            {
                cout << "Wow... you got killed by the WALKING TALKING PENIS.. He is like small too. GAME OVER" << endl;
                return 0;
            }
        }

    }


    cout << "!!!!!!!!!!!!!!!!!WIIINNNNNNNERRRRR!!!!!!!!!!!!!!" << endl;

    cout << "You spent many hours looking around the maze for the poor goblin and you killed him.\n:( Is it really a win?" << endl;

    system("PAUSE");
return 0;
}

