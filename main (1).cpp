#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*************** Player Class ***************/
class Player
{
	public:
		static string charName;
		static char command[30];
		static bool haveSword;
		static bool havePaper;
		static bool haveKey;
		static bool haveDoll;
		static bool havePhoto;
    static bool doorA6;
    static bool book;
		static bool leverA5;
		static bool leverE4;
		static bool atPeaceC4;
		static bool lichDead;
};
string Player::charName;
char Player::command[30];
bool Player::haveSword = 0;
bool Player::havePaper = 0;
bool Player::haveKey = 0;
bool Player::haveDoll = 0;
bool Player::havePhoto = 0;
bool Player::doorA6 = 0;
bool Player::book = 0;
bool Player::leverE4 = 0;
bool Player::leverA5 = 0;
bool Player::atPeaceC4 = 0;
bool Player::lichDead = 0;


/*************** Utilities Class ***************/
class Util
{
	public:
		//each block the player goes to gets added to this vector, effectively counting their steps
		static vector<string> v_blockTally;

		static void makeLowercase(char conversion[30])
		{
			for (int i = 0; conversion[i] != '\0'; i++)
				conversion[i] = tolower(conversion[i]);
		}

		static void displayHelp()
		{
			cout << endl << "Commands available are GO, CHECK, USE, OPEN, and PICK UP." << endl;
			cout << "When available, use GO with the cardinal directions: NORTH, SOUTH, EAST, and WEST. Alternatively, you can use GO BACK to return to the previous location when in a room." << endl;
			cout << "Use CHECK by itself or with anything that might be [worth] checking out." << endl;
			cout << "USE works with some items and is used as a universal action command." << endl;
			cout << "PICK UP works with objects you might want to move or save for later.";
		}
};
vector<string> Util::v_blockTally;


/*************** Functions ***************/

//intro functions
void enterName();
void gameOver();
void gameWin();

//block functions & //notes
void blockA1();	// done
void blockB1();	// done
void blockC1();	// done
void blockD1();	// done
void blockE1();	// done

void blockA2();	// done
void blockB2();	// done
void blockD2();	// done
void blockE2();	// done

void blockA3();	// done
void blockB3();	// done
void blockC3();	// done
void blockD3();	// done
void blockE3();	// done

void blockA4();	// done
void blockB4();	// done
void blockC4();	// enemy block
void blockE4();	// done

void blockA5();	// done
void blockB5(); // done
void blockC5();	// done
void blockD5();	// done
void blockE5();	// done

void blockA6();	// done
void blockB6();	// enemy block
void blockC6();	// done
void blockD6();	// done
void blockE6();	// done


/********************************************/

int main()
{
	//intro
	enterName();
	
	//Start at D1 (maze entrance)
	blockD1();

	return 0;
}

/********************************************/

//intro
void enterName()
{
	cout << "What is your name?" << endl << "> ";
	getline(cin,Player::charName);

	cout << "Your name is " << Player::charName << ", correct? [ Y / N ]" << endl << "> ";
	cin >> Player::command;
	cin.ignore(1, '\n');

	Util::makeLowercase(Player::command);

	while (string(Player::command) != "y" && string(Player::command) != "n")
	{
		cout << "Your name is " << Player::charName << ", correct? [ Y / N ]" << endl << "> ";
		cin >> Player::command;
    cin.ignore(1, '\n');

		Util::makeLowercase(Player::command);
	}

	if (string(Player::command) == "n")
	{
		cout << "Okay, well what's your name then, huh?" << endl << "> ";
		getline(cin,Player::charName);
	}
}


void gameOver()
{
  cout << endl << " ****************** GAME OVER ****************** " << endl;
  cout << "Would you like to try again? (Y/N)" << endl;
  cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  if (string(Player::command) == "y") // restarts game
	{
    // resets every item/object
    Player::haveSword = 0;
    Player::havePaper = 0;
    Player::haveKey = 0;
    Player::haveDoll = 0;
    Player::havePhoto = 0;
    Player::doorA6 = 0;
    Player::book = 0;
    Player::leverE4 = 0;
    Player::leverA5 = 0;
    Player::atPeaceC4 = 0;
	Player::lichDead = 0;
    blockD1(); // starts at first block again
	}

  else if (string(Player::command) == "n") // ends program
    exit(0);
}


void gameWin()
{
	ofstream outFile("PlayerWin.txt", ios_base::app);
	
	for (unsigned i=0; i < Util::v_blockTally.size(); i++)
		std::cout << ' ' << Util::v_blockTally.at(i);
	std::cout << '\n';}


/*************** BLOCK FUNCTIONS A1 - E1 ***************/

void blockA1()
{
	Util::v_blockTally.push_back("A1");
	static int stoneMoved = 0; // 0 = not picked up, 1 = picked up, 2 = got rid of

	cout << endl << "You stand at the edge of a cliff to the looking out over a still body of water. One bird in the distance. No other land in sight." << endl;
	cout << "A large disc-shaped [stone] lays on the ground." << endl;

	cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

	while (1)
	{
		if (string(Player::command) == "check")
		{
			if (stoneMoved == 0) // no stone
				cout << endl << "You stand at the edge of a cliff looking out over a still body of water. There's a bird in the distance. No other land in sight." << endl << "A large disc-shaped [stone] lays on the ground." << endl;
			else if (stoneMoved == 1) // has stone
				cout << endl << "You stand at the edge of a cliff looking out over a still body of water. The bird that was there is gone. Still no land in sight." << endl;				
		}

		else if ((string(Player::command) == "pick up stone") && (stoneMoved == 0))
		{
				cout << endl << "You lift the [stone] up off the ground. It's surprisingly light for how large it is." << endl;
				stoneMoved = 1;
		}

		else if ((string(Player::command) == "use stone") && (stoneMoved == 1))
		{
			cout << endl << "You toss the stone over the edge and into the water. It takes longer than you think until you hear a splash. It probably wasn’t that important, right?" << endl;
			stoneMoved = 2; // tossed away stone
		}

		else if (string(Player::command) == "go east")
			blockB1();

		else if (string(Player::command) == "go west")
		{
			cout << endl << "You decide that you should jump into the water. It's a lot higher than you thought, but you do survive the fall. Unfortunately due to there not being any land, you have nowhere to swim to and you tread water endlessly until you perish... that's a pretty bad way to go." << endl;
			gameOver();
		}

		else if (string(Player::command) == "help")
			Util::displayHelp();

		cout << endl << "What do you do?" << endl << "> ";
		cin.getline(Player::command,30);
		Util::makeLowercase(Player::command);
	}
}

void blockB1()
{
	Util::v_blockTally.push_back("B1");

  cout << endl << "You move closer to the cliff towards the [west]." << endl;
  cout << "What do you do?" << endl << "> ";
  cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while (1)
  {
    if (string(Player::command) == "check")
			cout << endl << "This path leads to what seems to be the edge of a cliff.." << endl;

    else if (string(Player::command) == "go west")
			blockA1();

    else if(string(Player::command) == "go east")
			blockC1();

    else if (string(Player::command) == "help")
			Util::displayHelp();

    cout << endl << endl << "What do you do?" << endl << "> ";
		cin.getline(Player::command,30);
		Util::makeLowercase(Player::command);
  }

}

void blockC1() //options: GO [west, east] / CHECK
{
	Util::v_blockTally.push_back("C1");

  cout << endl << "A pathway. Nothing much. There’s a cliff to the [west]." << endl;
  cout << "What do you do?" << endl << "> ";
  cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while (1)
  {
    if (string(Player::command) == "check")
			cout << endl << "This path leads [west] towards a cliff." << endl;

    else if (string(Player::command) == "go west")
			blockB1();

    else if(string(Player::command) == "go east")
			blockD1(); 

    else if (string(Player::command) == "help")
			Util::displayHelp();

    cout << endl << endl << "What do you do?" << endl << "> ";
		cin.getline(Player::command,30);
		Util::makeLowercase(Player::command);

  }
}

void blockD1()
{
	Util::v_blockTally.push_back("D1");
	static bool gateOpen = 0;

	cout << endl << "You stand in front of an iron [gate] to the [north]. Beyond the [gate] is a [courtyard]." << endl;
	cout << "There's a cliff to the [west], but otherwise you're surrounded by walls to the south and [east]." << endl;
	cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

	while (1)
	{
		if (string(Player::command) == "check")
		{
			if (gateOpen == 0)
				cout << endl << "You stand in front of an iron [gate] to the [north]. Beyond the [gate] is a [courtyard]." << endl;
			else if (gateOpen == 1)
				cout << "There's a pitch black void directly in front of you to the [north] where an entrnace to a courtyard should be.";

			cout << endl << "There's a cliff to the [west], but otherwise you're surrounded by walls to the south and [east]." << endl;
		}

		else if ((string(Player::command) == "check courtyard") && (gateOpen == 0))
			cout << endl << "You see some vague shapes walking in the distance. Where are your glasses?";

		else if ((string(Player::command) == "use gate") || (string(Player::command) == "open gate"))
		{
			if (gateOpen == 0)
			{
				cout << endl << "As it creaks open, the space in front of you turns pitch black. You can't see a thing more than 2 feet out to the [north].";
				gateOpen = 1;
			}
			else if (gateOpen == 1)
			{
				cout << endl << "It won't move." << endl;
			}
		}

		else if (string(Player::command) == "check gate")
		{
			if (gateOpen == 0)
			{
				cout << endl << "It's made of iron." << endl;
			}

			if (gateOpen == 1)
			{
				cout << endl << "The gate is open." << endl; 
			}
		}

		//DIRECTIONS
		if (string(Player::command) == "go north")
		{
			if (gateOpen == 0)
				cout << endl << "You're not small enough to fit between the iron bars on the gate.";
			else if (gateOpen == 1)
				blockD2();
		}
		else if (string(Player::command) == "go west")
			blockC1();

		else if (string(Player::command) == "go east")
			blockE1();

		else if (string(Player::command) == "help")
			Util::displayHelp();

		cout << endl << endl << "What do you do?" << endl << "> ";
		cin.getline(Player::command,30);
		Util::makeLowercase(Player::command);

	}
}

void blockE1()
{
	Util::v_blockTally.push_back("E1");

  cout << endl << "A stone [wall] prevents you from going any further. It's a dead end." << endl;
  cout << "What do you do?" << endl << "> ";
  cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while (1)
  {
    if (string(Player::command) == "check")
    cout << endl << "A stone [wall] prevents you from going any further. It's a dead end." << endl;

    else if ((string(Player::command) == "go west") || (string    (Player::command) == "go back"))
    blockD1();

    else if (string(Player::command) == "help")
		Util::displayHelp();

    else if (string(Player::command) == "check wall")
    cout << endl << "The stone [wall] looks too high to be climbed. There's no way of getting through here." << endl;

    cout << endl << endl << "What do you do?" << endl << "> ";
		cin.getline(Player::command,30);
		Util::makeLowercase(Player::command);
  }

}


/*************** BLOCK FUNCTIONS A2 - E2 ***************/

void blockA2()
{
	Util::v_blockTally.push_back("A2");

  cout << endl << "You head west, running into nothing but a stone wall again. The strange laugh giggles again from [north] of the hallway." << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
      cout << endl << "You can hear the birds outside faintly chirping when you get close to the wall..";

    else if (string(Player::command) == "go north")
      blockA3();

    else if (string(Player::command) == "go east")
      blockB2();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }
}

void blockB2()
{
	Util::v_blockTally.push_back("B2");

  cout << endl << "You head south down towards the hallway. There's a strange laugh coming from the [west]. " << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while (1)
  {
    if (string(Player::command) == "check")
    cout << endl << "The laugh sounds like a little girl. What's so funny?" << endl;

    else if (string(Player::command) == "go west")
    blockA2();

    else if (string(Player::command) == "go north")
    blockB3();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);

  }
}

void blockD2() // options: go north, go east, check
{
	Util::v_blockTally.push_back("D2");
	static bool hasEnteredD2 = 0; // if player has entered block before

	if (hasEnteredD2 == 0) // has not entered yet
	{
		cout << endl << "You walk into the pitch black, when all of a sudden the gate shuts swiftly behind you. It's a moment of absolute darkness but suddenly, torches illuminate the hallway. It's an interior of decrepit stone, with spider webs everywhere and mice running around. The hallway leads to the [north], but you see a room to the [east]." << endl;
		hasEnteredD2 = 1;
	}
	else if (hasEnteredD2 == 1) // has entered before
	{
		cout << endl << "You go back into the hallway with an uneasy feeling. The mice have disappeared and all there is left is a torch on the wall [north]." << endl;
	}

  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while (1)
  {
    if (string(Player::command) == "check")
			cout << endl << "It looks like an old abandoned hallway of what seems to be a castle. ";

    else if (string(Player::command) == "go north")
			blockD3();

    else if ((string(Player::command) == "go south") || (string(Player::command) == "go back"))
			cout << endl << "The gate has shut behind you. You can't go back this way..";

    else if (string(Player::command) == "go east")
			blockE2();

		else if (string(Player::command) == "help")
			Util::displayHelp();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }
}

void blockE2()
{
	Util::v_blockTally.push_back("E2");
	string wallGrid[6][5] =	{ {"A6", "B6", "C6", "D6", "E6"},
														{"A5", "B5", "C5", "D5", "E5"},
														{"A4", "B4", "C4", "[]", "E4"},
														{"A3", "B3", "C3", "D3", "E3"},
														{"A2", "B2", "[]", "D2", "E2"},
														{"A1", "B1", "C1", "D1", "E1"}
														};

  cout << endl << "You walk into the room carefully and all the mice scurry away. A single torch on the wall brightens up the room. There's a strange [pattern] on the wall. Unfortunately, this room is empty and doesn't lead anywhere." << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while (1)
  {
    if (string(Player::command) == "check")
      cout << endl << "The only things in this room are and a torch on the wall. There's nothing else here." << endl;

    else if ((string(Player::command) == "go west") || (string(Player::command) == "go back"))
      blockD2();

		else if (string(Player::command) == "check pattern")
		{
			cout << endl << "Very weird. I wonder what it could mean?" << endl << endl;
			for (int i = 0; i < 6; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					std::cout << wallGrid[i][j] << ' ';
				}
				std::cout << std::endl;
			}
		}

		else if (string(Player::command) == "help")
			Util::displayHelp();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }
}


/*************** BLOCK FUNCTIONS A3 - E3 ***************/

void blockA3()
{
	Util::v_blockTally.push_back("A3");

  cout << endl << "You continue [north] towards the eerie laugh, when suddenly you stop and observe. The hallway is surrounded by paintings that seem to be staring at you whenever you move. Above you is a chandelier that seems to be flickering continuously. The creepy laugh coming from the [north] seems to be getting louder. " << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
      cout << endl << "These paintings are creepy. Somebody has a weird taste in art. " << endl;

    else if (string(Player::command) == "go south")
      blockA2();

    else if(string(Player::command) == "go north")
      blockA4();

		else if (string(Player::command) == "help")
			Util::displayHelp();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }

}

void blockB3()
{
	Util::v_blockTally.push_back("B3");

  cout << endl << "Your path is blocked by rubble. There is a hallway to the [south]. " << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
    cout << endl << "Something in the rubble is whispering your name. Yikes." << endl;

    else if(string(Player::command) == "go south")
      blockB2();

		else if (string(Player::command) == "help")
			Util::displayHelp();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }

}

void blockC3()
{
	Util::v_blockTally.push_back("C3");

  cout << endl << "You continue [west] down the hallway." << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
      cout << endl << "It's spooky in here." << endl;

    else if (string(Player::command) == "go west")
      blockB3();

    else if (string(Player::command) == "go east")
      blockD3();

		else if (string(Player::command) == "help")
			Util::displayHelp();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }
}

void blockD3()
{
	Util::v_blockTally.push_back("D3");
  static bool hasEnteredD3 = 0; // if player has entered block before

  if (hasEnteredD3 == 0) // has not entered block yet
  {
    cout << endl << "You walk towards the hallway and observe around you. The hallway has a clear path to the [west], but there's also a room to the [east]." << endl;
    hasEnteredD3 = 1; // player has entered block before
  }

  // if player has entered block before with no sword
  else if ((hasEnteredD3 == 1) && (Player::haveSword == 0))
    cout << endl << "You walk back into the hallway where you find yourself where you were before you entered the room. The path continues to the [west], but it also leads [south] to where you started." << endl;
  
  // if player has entered block before with possesion of sword
  else if ((hasEnteredD3 == 1) && (Player::haveSword == 1))
  {
    cout << endl << "With your newfound sword, you feel a little safer and more confident. You go back into the abandoned hallway and find yourself where you were before you entered the room. The path continues to the [west], but it also leads [south] to where you started." << endl;
  }
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
			cout << endl << "There's a room to the [east], but the hallway continues to the [west]." << endl;

    else if (string(Player::command) == "go west")
			blockC3();

    else if (string(Player::command) == "go east")
			blockE3();

		else if (string(Player::command) == "go south")
			blockD2();

		else if (string(Player::command) == "help")
			Util::displayHelp();

    cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }
}

void blockE3()
{
	Util::v_blockTally.push_back("E3");

  cout << endl << "You enter a room with two statues. The statue on the left is holding a torch. The statue on the right is holding a [sword]." << endl;

  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
		if (string(Player::command) == "check")
	  {
			if (Player::haveSword == 0) // player doesn't have sword
				cout << endl << "The statue holding the torch almost looks like the Statue of Liberty. The statue holding the [sword] looks like a valiant warrior from olden times. " << endl;
			else if (Player::haveSword == 1) // player has sword
				cout << endl << "The statue that was holding the sword seems to have moved its eyes towards you. " << endl;
		}

    else if (string(Player::command) == "pick up torch")
    cout << endl << "There's no point in picking up the torch. Better leave it there." << endl;

		else if ((string(Player::command) == "pick up sword") && (Player::haveSword == 0))
		{
			cout << endl << "You pry the sword out of the statue's hand. The sword feels heavy but powerful." << endl;
			Player::haveSword = 1; // player obtains sword
		}

    else if ((string(Player::command) == "pick up sword") && (Player::haveSword == 1))
    {
      cout << endl << "You already have the sword in your hand." << endl;
    }

    else if (string(Player::command) == "check torch")
    cout << "You put your hand near the flames of the torch. For some reason, it doesn't feel hot at all. Weird. " << endl;

    else if ((string(Player::command) == "check sword") && (Player::haveSword == 0))
    cout << endl <<  "The sword looks like it was forged from expensive steel. Only skilled warriors could use this sword to its fullest potential." << endl;

    else if ((string(Player::command) == "check sword") && (Player::haveSword == 1))
    cout << endl << "The sword looks to be in pristine condition, as if a great knight wielded this sword." << endl;

		else if ((string(Player::command) == "go west") || (string    (Player::command) == "go back"))
			blockD3();

		else if (string(Player::command) == "help")
			Util::displayHelp();

  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);
  }
}

/*************** BLOCK FUNCTIONS A4 - E4 ***************/

void blockA4()
{
	Util::v_blockTally.push_back("A4");
  static bool hasEnteredA4; // if player has entered block before

  if (hasEnteredA4 == 0) // if player has not entered block before
  {
    cout << endl << "You come across a dining room. On the dining table are empty plates with empty chairs, except for one. You see a porcelain [doll] sitting towards the end of the table. She stares at you with a scary grin. Suddenly, there is a rattling sound coming from a door in the [east]." << endl;
		hasEnteredA4 = 1; // player has entered block before
  }

  // if player has entered block before with possession of doll
  else if ((hasEnteredA4 == 1) && (Player::haveDoll == 1))
  {
    cout << endl << "You walk back in the dining room, but there's nothing significant worth checking out." << endl;
  }

  // if player has entered block before without possession of doll
  else if ((hasEnteredA4 == 1) && (Player::haveDoll == 0))
  cout << endl << "You walk back in the dining room, and see the [doll] still staring at you." << endl;
  
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
			cout << endl << "The doll's smile makes you feel uneasy... along with the rattling coming from the [east].";

    else if ((string(Player::command) == "pick up doll") && (Player::haveDoll == 0))
    {
      cout << endl << "You pick up the porcelain doll and hold it in your hand. As you hold it, it stares deeply into your eyes, still creepily grinning. You wonder what this could be used for." << endl;
      Player::haveDoll = 1;
    }

    else if ((string(Player::command) == "pick up doll") && (Player::haveDoll == 1))
    {
      cout << endl << "You're already holding the porcelain doll." << endl;
    }

    else if(string(Player::command) == "go east")
			blockB4();

		else if (string(Player::command) == "help")
			Util::displayHelp();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }
}

void blockB4()
{
	Util::v_blockTally.push_back("B4");
  static bool hasEnteredB4 = 0; // if player has not entered block before

  // the text that shows before enemy is defeated
  if (hasEnteredB4 == 0)
  {
    cout << endl << "As you approach the rattling sound, you see a door to the [east]. The door handle is violently shaking, as if something or someone was desperately trying to get out. There's also a new path to the [north] that you can go to. " << endl;

    hasEnteredB4 = 1;
  }

  // text that shows after enemy is defeated
  if ((hasEnteredB4 == 1) && (Player::atPeaceC4 == 1))
  {
    cout << endl << "You successfully escape from the surreal experience of a little girl's ghost. You feel as if she is at peace now. The path dims brightly towards the [north]." << endl;
  }

    cout << endl << "What do you do?" << endl << "> ";
	  cin.getline(Player::command,30);
	  Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
      cout << endl << "The air suddenly feels tense for some reason." << endl;

    else if(string(Player::command) == "go west")
      blockA4();

    else if(string(Player::command) == "go east")
      blockC4();
    
    else if(string(Player::command) == "go north")
      blockB5();

    // if player tries to go back to room after defeating enemy
    else if ((string(Player::command) == "go east") && (Player::atPeaceC4 == 1))
      cout << endl << "The door handle no longer seems to be rattling, but it's locked now. There's no way to go through here." << endl; 

		else if (string(Player::command) == "help")
			Util::displayHelp();

   cout << endl << "What do you do?" << endl << "> ";
	 cin.getline(Player::command,30);
	 Util::makeLowercase(Player::command);
  }
}

void blockC4() //ghost girl trapped in room 
{
	Util::v_blockTally.push_back("C4");
	
	if (Player::atPeaceC4 == 0)
	{
		cout << endl << "You approach the door which is inscribed with the name \"BELA\" in large serifed letters. The closer you get, the louder it rattles. Once you touch the handle the shaking stops. You open the door." << endl;
		cout << "Your eyes lock with a little girl in a yellow dress. Her figure is odd.. It's almost as if she's a ghost. No wait... she is a ghost. She starts smiling at you." << endl;
    cout << endl << "Girl:" << endl;
            cout << "\"Hello! What are you doing here? I didn't know we had visitors! Since you're here, you can be my best friend! I lost my doll a couple of years ago and ever since then I've been really lonely. My father disappeared as well so it's just been me in this big old castle all alone. What's your name?\"" << endl;
    cout << endl << "You mumble your name anxiously." << endl;
    cout << endl << "Girl:";
    cout << endl << "\"Oh, " << Player::charName << "? That's a nice name! Let's be best friends forever!\"" << endl;


		if (Player::haveDoll == 0)
		{
			cout << endl << "You start to panic and try to escape the room. However, the door is locked with no way out." << endl;
      cout << endl << "Girl:" << endl;
      cout << endl << "\"Where are you going? I told you we're going to be best friends FOREVER!\"" << endl;
      gameOver();
		}

		else if (Player::haveDoll == 1)
		{
			cout << endl << "What do you do?" << endl << "> ";
			cin.getline(Player::command,30);
			Util::makeLowercase(Player::command);

			while (1)
			{
				if ((string(Player::command) == "check") && (Player::atPeaceC4 = 0))
				{
					cout << "You feel scared out of your mind that you can't escape. The little girl seems to be excited to play with you." << endl;
				}

        else if ((string(Player::command) == "check") && (Player::atPeaceC4 = 1))
        {
          cout << "The room looks to be the little girl's bedroom. It seems like your typical girly bedroom, other than the fact that everything is decayed and deteriorated." << endl;
        }

        else if ((string(Player::command) == "use doll") || (string(Player::command)) == "give doll")
				{
					cout << endl << "Girl:";
          cout << endl << "\"My doll..? How did you get this? This brings me back memories.. My father gave me this when I was younger and I have been obsessed with it ever since. I thought I would never see it again. Thank you.. for freeing me.\"" << endl;
					Player::atPeaceC4 = 1;
          cout << "The little girl's ghost suddenly fades away and drops a photo. You pick it up and observe it. In the photo it appears to be the little girl when she was alive along with a well-dressed man with a crown on his head who is presumed to be her father. Perhaps he was the king of this castle? They appear to be happily smiling at each other. You figure you'll hold onto this for now." << endl;
          Player::havePhoto = 1;
				}
				
				else if ((string(Player::command) == "go west") || (string(Player::command)) == "go back")
				{
					if (Player::atPeaceC4 == 0)
					{
						//door is shut, girl says something like "I'm never letting you out!"
						cout << endl << "Girl:" << endl;
            cout << "\"Where are you going? You know you can't escape right..? We're going to play in this room forever!\"" << endl;
					}

					else if (Player::atPeaceC4 == 1)
					{
						//the door is unlocked
						cout << endl << "You leave the room as quickly as possible before anything else weird happens. You take a second to process what just happened.. and then continue on your path." << endl;
						blockB4();
					}
				}
				
				else if (string(Player::command) == "help")
					Util::displayHelp();

				cout << endl << "What do you do?" << endl << "> ";
				cin.getline(Player::command,30);
				Util::makeLowercase(Player::command);
			}
		}
	}

	else if (Player::atPeaceC4 == 1)
	{
		cout << "placeholder text" << endl;
	}
}

void blockE4()
{
  Util::v_blockTally.push_back("E4");

  cout << endl << "You come across a room with the door already open. As you approach it, several spiders come crawling out as soon as they see you. You walk inside and see that it's a library, with bookshelves aligned perfectly all around. However, one [book] seems to be out of place among the organized shelves." << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while (1)
  {

    if (string(Player::command) == "pick up book")
      cout << endl << "You pick the book up, flip through it, and then you remember that you don't like books so you toss it on the floor. You look back up and you see a secret [lever] that was hidden on the shelf." << endl;
      Player::book = 1;
      
    if ((string(Player::command) == "check") && (Player::leverE4  == 0))
			cout << endl << "For an abandoned castle, this library seems to be in perfect condition.";
    
    else if ((string(Player::command) == "check") && (Player::leverE4 == 1))
			cout << endl << "That secret lever probably opened something important." << endl;
    
		//E4 switch logic
		if ((string(Player::command) == "use lever") && (Player::book == 1))
		{
			if (Player::leverE4 == 0)
			{
				cout << endl << "You pull the lever and hear something buzz near you. It sounds like it came from the [north]." << endl;
				Player::leverE4 = 1;
			}

			else if (Player::leverE4 == 1)
			{
				cout << endl << "You pull the lever again. It's now back in its original state." << endl;
				Player::leverE4 = 0;
			}

			//checks both switches at the end of USE [switch]
			if ((Player::leverE4 == 1) && (Player::leverA5 == 1))
				cout << endl << "You hear a loud *CLICK* nearby. It seems to be coming from the [north]." << endl;
		}

    else if ((string(Player::command) == "go north") || (string    (Player::command) == "go back"))
			blockE5();

		else if (string(Player::command) == "help")
			Util::displayHelp();

    cout << endl << "What do you do?" << endl << "> ";
	  cin.getline(Player::command,30);
	  Util::makeLowercase(Player::command);
  }
}

/*************** BLOCK FUNCTIONS A5 - E5 ***************/
void blockA5()
{
  Util::v_blockTally.push_back("A5");

  cout << endl << "You come across a dimly lit room, surrounded by spiders crawling on the broken stone walls. A scary painting of a hideous looking person stares at you. But then you realize it's actually a mirror. Across the room is a [lever] on the wall that can be used." << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while (1)
  {
    if ((string(Player::command) == "check") && (Player::leverA5 == 0))
      cout << endl << "This lever looks like it can probably be used for something helpful." << endl;
    
    else if ((string(Player::command) == "check") && (Player::leverA5 == 1))
      cout << endl << "The lever has been pulled." << endl;

		//A5 switch logic
		if (string(Player::command) == "use lever")
		{
			if (Player::leverA5 == 0)
			{
				cout << endl << "You pull the lever and then you faintly hear a buzz sound coming from far away." << endl;
				Player::leverA5 = 1;
			}

			else if (Player::leverA5 == 1)
			{
				cout << endl << "You pulled the lever again. It's now back in its original state." << endl;
				Player::leverA5 = 0;
			}
			
			//checks both switches at the end of USE [switch]
			if ((Player::leverA5 == 1) && (Player::leverE4 == 1))
		    cout << endl << "You hear a faint *click* coming from the north[east]." << endl;
		}

    else if ((string(Player::command) == "go east") || (string    (Player::command) == "go back"))
    blockB5();

		else if (string(Player::command) == "help")
			Util::displayHelp();

    cout << endl << "What do you do?" << endl << "> ";
	  cin.getline(Player::command,30);
	  Util::makeLowercase(Player::command);

  }
}
void blockB5()
{
	Util::v_blockTally.push_back("B5");

  cout << endl << "You make your way up a new corridor of the broken down castle and find a door to the [west] that leads to a room. Or, you can continue along the corridor to the [east]. " << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
    cout << endl << "It's pretty dark in there." << endl;

    else if(string(Player::command) == "go west")
    blockA5();

    else if(string(Player::command) == "go east")
    blockC5();
    
		else if (string(Player::command) == "help")
			Util::displayHelp();

  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);
  }

}

void blockC5()
{
	Util::v_blockTally.push_back("C5");

  cout << endl << "You continue [east] down the long corridor, when suddenly you stop and hear loud screeches through the walls. You wonder what it is for a second, but conclude that it's probably nothing.. " << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
			cout << endl << "Those loud screeches coming from the wall sounded really menacing..";

    else if(string(Player::command) == "go west")
			blockB5();

    else if(string(Player::command) == "go east")
			blockD5();

		else if (string(Player::command) == "help")
			Util::displayHelp();

  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);
  }

}

void blockD5()
{
	Util::v_blockTally.push_back("D5");

  cout << endl << "You find yourself almost at the end of the corridor, when you see a path that can be taken to the [north]. Or, you can continue [east] to the end of the hallway." << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
      cout << endl << "There is a painting on the wall. It appears to be a portrait of a father and his daughter but their faces are ripped off.";

    else if(string(Player::command) == "go north")
      blockD6();

    else if(string(Player::command) == "go west")
      blockC5();

    else if(string(Player::command) == "go east")
      blockE5();

		else if (string(Player::command) == "help")
			Util::displayHelp();

  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);
  }
}

void blockE5()
{
	Util::v_blockTally.push_back("E5");

  cout << endl << "You've reached the end of the hallway. You can either head back [west] or go [south] where a room appears to be located." << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
      cout << "A sealed off window is on the wall. There is a slight breeze coming through the cracks.";

    else if(string(Player::command) == "go south")
      blockE4();

    else if(string(Player::command) == "go west")
      blockD5();
    
		else if (string(Player::command) == "help")
			Util::displayHelp();

  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);
  }
}

/*************** BLOCK FUNCTIONS A6 - E6 ***************/

void blockA6()
{
	Util::v_blockTally.push_back("A6");

  cout << endl << "You've reached the end of a hallway. There is a massive door to the [west] that can only be opened using a certain key. Something tells you that this is the way out." << endl;
  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
      cout << endl << "The door is beautifully decorated in gold and silver with a keyhole on the right side. There is a strange message engraved at the top of the door." << endl;

    else if ((string(Player::command) == "go west") && (Player::haveKey == 1))
      cout << endl << "You decide it's finally time to leave this place. As you insert the key the message engraved at the top of the door starts glowing 
					   Almost instinctively, you recite the strange words on the top of the door, completing the incantation.
					   The door glows a brilliant white as it opens. As you step into the light your surroundings begin to fade away.
					   You find yourself in your bed with the clock reading 6:32 AM. 
					   You're covered in sweat. You should probably start getting ready for class." << endl;

			//GO TO GAME WIN FUNCTION

    else if ((string(Player::command) == "go west") && (Player::haveKey == 0))
      cout << endl << "You're going to need a key to open this door. Maybe from that locked room in the [east]?" << endl;

    else if(string(Player::command) == "go east")
      blockB6();

		else if (string(Player::command) == "help")
			Util::displayHelp();

  cout << endl << "What do you do?" << endl << "> ";
	cin.getline(Player::command,30);
	Util::makeLowercase(Player::command);
  }
}

void blockB6()
{
	Util::v_blockTally.push_back("B6");

	if (Player::lichDead == 0)
	{
		cout << endl << "You approach a hooded figure kneeling on the ground. The figure is surrounded by candles and appears to be performing some kind of ritual. You can hear chants echoing from seemingly nowhere." << endl;

		if (Player::haveSword == 1)
			cout << "Your sword starts to glow brighter with every step." << endl;

		cout << endl << "Figure:" << endl;
		cout << "\"I know you... What did you think to gain by coming here again? You won't stop me from getting to the outside world. Your world. No matter how many times you kill me, I am reborn. I am The Lich. I live within you, " << Player::charName << ".\"" << endl;

		if ((Player::haveSword == 0) && (Player::havePhoto == 0))
		{
			cout << endl << "The Lich says something in an ancient language you can't understand. You're dead. You have no way to combat it." << endl;
			gameOver();
		}

		cout << endl << "What do you do?" << endl << "> ";
		cin.getline(Player::command,30);
		Util::makeLowercase(Player::command);

		while(1)
		{
				if ((string(Player::command) == "use sword") && (Player::haveSword == 1))
				{
					cout << "Before The Lich even gets a chance to say another word, you plunge your blade into its heart, causing lack tar to spray out of every hole in its disgusting, decaying body. It's really gross. The air is calm." << endl << endl;
					Player::lichDead = 1;
					cout << "You've killed The Lich who seems to weirdly know a lot about you. Did it say \"again?\"" << endl << "A large door lies to the [west].";
				}

				else if (string(Player::command) == "use photo" && (Player::havePhoto == 1))
				{
					cout << endl << "Lich:" << endl;
					cout << "\"What.. where did you... how did you get that! Are you...?" << endl;
					cout << "That's Bela. My daughter. Her room has been sealed every time you make this damn place and I've never been able to get inside. I've never been able to be with her. That's all I want." << endl;
					cout << "Strike me down one final time, " << Player::charName <<". Please. I submit. Destroying that image will set me free from your prison.\"" << endl << endl;
					
					cout << "You walk to a nearby torch and hold the picture over the flame. As the photo flakes and melts, The Lich does too. Layers of decaying skin melt away and you briefly see the face of the man in the photo before he is no more. That was intense." << endl;
					Player::lichDead = 1;
				}

				cout << endl << "What do you do?" << endl << "> ";
				cin.getline(Player::command,30);
				Util::makeLowercase(Player::command);
		}
	}
	else if (Player::lichDead == 1)
	{
			cout << endl << "All the candles have been blown out. Remnants of what was once The Lich lay on the ground.. a truly awful sight." << endl;
			cout << endl << "There is a door to the [west] and hall to your [east]." << endl;

			cout << endl << "What do you do?" << endl << "> ";
			cin.getline(Player::command,30);
			Util::makeLowercase(Player::command);

		while (1)
		{
			if (string(Player::command) == "go west")
        blockA6();

      else if (string(Player::command) == "go east")
        blockC6();

      else if (string(Player::command) == "check")
      cout << endl << "The Lich's remnants lay on the ground in white ashes. All the tension in the air dissipates." << endl;

			cout << endl << "What do you do?" << endl << "> ";
			cin.getline(Player::command,30);
			Util::makeLowercase(Player::command);
		}
	}
}

void blockC6() 
{
	Util::v_blockTally.push_back("C6");
	
  cout << endl << "You feel a sinister tension in the air as you walk through the dimly lit hallway. Every step forward gives you anxiety, but you keep pushing on. You hear chants in the distance and a massive dark silhouette [west] of the hallway. " << endl;
  cout << endl << "What do you do?" << endl << "> ";
  cin.getline(Player::command,30);
  Util::makeLowercase(Player::command);

  while (1)
  {

    if (string(Player::command) == "check")
      cout << endl << "That massive dark figure must be the cause of all the anxiety you're getting. Better make sure you're well equipped." << endl; 

    else if(string(Player::command) == "go east")
      blockD6();

    else if(string(Player::command) == "go west")
      blockB6();

    else if (string(Player::command) == "help")
		  Util::displayHelp();

  cout << endl << "What do you do?" << endl << "> ";
  cin.getline(Player::command,30);
  Util::makeLowercase(Player::command);
  }

}

void blockD6() 
{
	Util::v_blockTally.push_back("D6");

  cout << endl << "You've reached the end of the hallway. There are two paths. Towards the [east], there is a locked basement door downstairs. It seems to require some sort of switch to be opened. Towards the [west] leads to a grand staircase going up. " << endl;
  cout << endl << "What do you do?" << endl << "> ";
  cin.getline(Player::command,30);
  Util::makeLowercase(Player::command);

  while(1)
  {
    if (string(Player::command) == "check")
      cout << endl << "There is a strange glow emitting from the bottom of the door. There is another sealed window to the north with a slight breeze coming through the cracks.";

    else if(string(Player::command) == "go east")
      blockE6();

    else if(string(Player::command) == "go west")
      blockC6();

    else if(string(Player::command) == "go south")
      blockD5();

		else if (string(Player::command) == "help")
			Util::displayHelp();

  cout << endl << "What do you do?" << endl << "> ";
  cin.getline(Player::command,30);
  Util::makeLowercase(Player::command);
  }
}

void blockE6() //room with the key
{
	Util::v_blockTally.push_back("E6");

  if ((Player::leverA5 == 0) && (Player::leverE4 == 0))
		cout << endl << "You come across an iron [door] that's locked. Above the [door] are two lights. They're both red. Maybe there's something around here to open it." << endl;

  else if ((Player::leverA5 == 1) && (Player::leverE4 == 0))
		cout << endl << "You come across an iron [door] that's locked. Above the [door] are two lights. One is green and one is red." << endl;

  else if ((Player::leverA5 == 0) && (Player::leverE4 == 1))
		cout << endl << "You come across an iron [door] that's locked. Above the [door] are two lights. One is green and one is red." << endl;

  else if ((Player::leverA5 == 1) && (Player::leverE4 == 1))
		cout << endl << "You come across an iron [door] with two lights above it. They both shine green." << endl;

  else if ((Player::doorA6 == 1) && (Player::haveKey == 1))
  {
    cout << endl << "The gargoyles stare at you intensely as you enter the room once again." << endl;

    if (string(Player::command) == "pick up key")
      cout << endl << "You can't pick up the key, since you already picked it up." << endl;
  }

  cout << endl << "What do you do?" << endl << "> ";
  cin.getline(Player::command,30);
  Util::makeLowercase(Player::command);

  while(1)
  {
    if ((string(Player::command) == "go west") || (string (Player::command) == "go back"))
			blockD6();

    else if (string(Player::command) == "check")
			cout << endl << "You observe the basement and see how small it really is. The gargoyles along with the cramped space gives you anxiety. " << endl;
    
    else if ((string(Player::command) == "use door") || (string(Player::command) == "open door"))
		{
      if ((Player::leverA5 == 0) && (Player::leverE4 == 0))
				cout << endl << "The [door] won't budge at all. It's completely locked." << endl;

      else if ((Player::leverA5 == 1) && (Player::leverE4 == 0))
				cout << endl << "The [door] slightly budges, but is still locked." << endl; 

      else if ((Player::leverA5 == 0) && (Player::leverE4 == 1))
				cout << endl << "The [door] slightly budges, but is still locked." << endl; 

      else if ((Player::leverA5 == 1) && (Player::leverE4 == 1))
			{
				cout << endl << "The heavy door opens, and you come into a room. Two gargoyle statues with bright red eyes stare menacingly at you as you enter. It feels like their eyes follow your movements. In the middle of the room is a table with a brass [key] on it." << endl; 
		    Player::doorA6 = 1;
			}
		}

    else if ((Player::doorA6 == 1) && (string(Player::command) == "pick up key"))
		{
			cout << endl << "You pick up the brass [key] and put it in your pocket." << endl;
			Player::haveKey = 1;
		}

    else if (string(Player::command) == "check key")
    {
      if (Player::haveKey == 0)
				cout << endl << "This key looks like it hasn't been touched in ages. It might prove to be useful though." << endl;

      else if (Player::haveKey == 1)
				cout << endl << "This key might prove to be useful for something." << endl;
    }

		else if (string(Player::command) == "help")
			Util::displayHelp();

    cout << endl << "What do you do?" << endl << "> ";
    cin.getline(Player::command,30);
    Util::makeLowercase(Player::command);
  }
}