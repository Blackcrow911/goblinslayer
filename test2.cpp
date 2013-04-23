#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main()

{
	string choice;
	string pname;
	//GRID SIZE
	const int len = 3;
	const int hi = 3;
	//POS vars
	int x = 0;
	int y = 0;
	int prevx = 0;
	int prevy = 0;
	//Item vars
	bool key = 0;
	bool sword = 0;
	//Finish vars
	bool done = 0;
	bool cdone = 0;
	bool bdone = 0;
	//Player vars
	int playerhealth = 100;
	int pmaxhealth = 100;
	int playerdmg;
	int pmaxdmg = 5;
	int comchoice;
	int pheal = 15;
	bool playerdead = 0;

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

	while(!done)
	{
	cout << "Go left or right or up or down?";
	cin >> choice;
	prevx = x;
	prevy = y;
	if(choice == "right" && x != len)
		x++;
	else if(choice == "right" && x == len)
		cout << "Can't go any further right" << endl;
	else if(choice =="left" && x != 0)
		x--;
	else if(choice == "left" && x == 0)
		cout << "Can't go any further left" << endl;
	else if(choice == "up" && y != hi)
		y++;
	else if(choice == "up" && y == hi)
		cout << "Can't go any further up" << endl;
	else if(choice =="down" && y != 0)
		y--;
	else if(choice == "down" && y == 0)
		cout << "Can't go any further down" << endl;
	else if(choice == "pos")
		cout << x << " " << y << endl;
	else if(choice == "gpos")
		cout << gobx << " " << goby << endl;
	else
		cout << "invalid entry" << endl;

	gobx = rand()%3;		//walkin goblin
	goby = rand()%3;

		//EVENTS
		if(x == len && y == hi && key)	//Victory
			done = 1;

		if(x == 2 && y == 3)			//Trap
		{
			cout << "ITS A TRAPPP" << endl;
			cout << "You are sent back to start loser" << endl;
			x = 0;
			y = 0;
		}
		if(x == 0 && y == 3 && !key)		//Get key
		{
			cout << "You got the KEYY" << endl;
			key = 1;
		}
		if(x == 3 && y == 3 && !key)		//Locked door at Victory
		{
			cout << "This door is locked find the key" << endl;
			x = prevx;
			y = prevy;
		}

		if(x == 3 && y == 0 && !sword)
		{
			cout << "You found the sword of HE MAN, YOU HAVE THE POWER!!" << endl; // sword
			cout << "+30 Max dmg up!!" << endl;
			pmaxdmg += 30;
			sword = 1;
		}

		if(x == gobx && y == goby && !gobdead)		//Goblin attack
		{
			cout << "ITS A GOBLIN!!" << endl;
			while(!cdone)	//While goblin and player are alive
			{
				cout << "What do you want to do(1. attack 2. heal)?";
				cin >> comchoice;

				if(comchoice == 1)
				{
					playerdmg = (rand()%pmaxdmg)+1;
					cout << "You hit the goblin for " << playerdmg << "!" << endl;
					goblinhealth -= playerdmg;
					cout << "MAX DMG: " << pmaxdmg << endl;
				}
				else if(comchoice == 2)
				{
					cout << "You heal for " << pheal << "!" << endl;
					playerhealth += pheal;

					if(playerhealth > pmaxhealth)		//makes sure the player doesnt heal above max health
						playerhealth = pmaxhealth;
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
					playerhealth -= goblindmg;
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
					playerhealth -= goblindmg;
				}

				cout << "Your health: " << playerhealth << endl;
				cout << "Goblin health: " << goblinhealth << endl;

				if(goblinhealth <= 0)		//check gob dead
				gobdead = 1;
				else if(playerhealth <= 0)
				playerdead = 1;
				if(gobdead || playerdead){
					cdone = 1;
				}
			}
			if(gobdead)
				cout << "Victory! The foul goblin lies slain at your feet!" << endl;
			else if(playerdead)
			{
				cout << "Wow... a goblin killed you.. GAME OVER" << endl;
				return 0;
			}
		}

		if(x == 3 && y == 2 && !bdead)		//Penis attack
		{
			cout << "ITS A WALKING TALKING PENIS!!" << endl;
			while(!bdone)	//While goblin and player are alive
			{
				cout << "What do you want to do(1. attack 2. heal)?";
				cin >> comchoice;

				if(comchoice == 1)
				{
					playerdmg = (rand()%pmaxdmg)+1;
					cout << "You hit the WALKING TALKING PENIS for " << playerdmg << "!" << endl;
					bhealth -= playerdmg;
					cout << "MAX DMG: " << pmaxdmg << endl;
				}
				else if(comchoice == 2)
				{
					cout << "You heal for " << pheal << "!" << endl;
					playerhealth += pheal;

					if(playerhealth > pmaxhealth)		//makes sure the player doesnt heal above max health
						playerhealth = pmaxhealth;
				}
				else
					cout << "Invalid entry, you lose your turn" << endl;


					bdmg = (rand()%20)+1;
					cout << "WALKING TALKING PENIS hits you for" << bdmg << "!" << endl;
					playerhealth -= bdmg;


				cout << "Your health: " << playerhealth << endl;
				cout << "WALKING TALKING PENIS health: " << bhealth << endl;

				if(bhealth <= 0)		//check penis dead
				bdead = 1;
				else if(playerhealth <= 0)
				playerdead = 1;
				if(bdead || playerdead){
					bdone = 1;
				}
			}
			if(bdead)
				cout << "Victory! you must of hacked. :(!" << endl;
			else if(playerdead)
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

