#include <iostream>
#include<string>
#include<cstdlib>
#include "player.h"
#include "include/enemy.h"
#include "include/combat_manager.h"
using namespace std;

int main()

{
    combat_manager com_manager;
    //Enemies
    enemy goblin("Goblin", rand()%3, rand()%3,20,5,5);
    enemy test("Test Guy", 1,1,10,10,5);
    enemy boss("Boss",3,2,100,20,5);
    string choice;
    string pname;
    //GRID SIZE
    const int len = 3;
    const int hi = 3;
    //Finish vars
    bool done = 0;
    bool bdone = 0;
    int comchoice;

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
        cout << goblin.get_x() << " " << goblin.get_y() << endl;
    else
        cout << "invalid entry" << endl;

        //Goblin moves after each turn
        goblin.set_enemy_var("x", rand()%3);
        goblin.set_enemy_var("y", rand()%3);

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

        ///Combat manager will go here
        com_manager.start_combat(player,test);
        com_manager.start_combat(player,goblin);
        com_manager.start_combat(player,boss);

    }


    cout << "!!!!!!!!!!!!!!!!!WIIINNNNNNNERRRRR!!!!!!!!!!!!!!" << endl;

    cout << "You spent many hours looking around the maze for the poor goblin and you killed him.\n:( Is it really a win?" << endl;

    system("PAUSE");
return 0;
}

