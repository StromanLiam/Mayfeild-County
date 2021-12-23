//#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Day.h"
#include "Player.h"
//#include "Location.h"
//#include "Text.h"
#include <windows.h>
#include <ctype.h>

using namespace std;


//class Location;


class Item
{
public:
	//Location* getLocation();


	static const int LENGTH = 50;
	string name;
	string collectiveNoun = "ERRR";
	int amount = 0;
	int riskFactor = 0;
	bool botulismRisk = false;
	bool poisonRisk = false;
	bool paraciteRisk = false;
	bool isEdible = true;
	bool isGross = false;
	bool isAlcoholic = false;
	int id;

	bool curesInjury = false;
	bool curesInfection = false;
	bool curesPoison = false;
	bool curesBotulism = false;
	bool curesRabies = false;

	int hungerValue = 0;
	int vitaminValue = 0;
	int fatValue = 0;
	int thirstValue = 0;
	int energyValue = 0;
	int happinessValue = 0;
	int warmthValue = 0;

	static Item initialiseCannedVegitables()
	{
		Item cannedVegitables;

		cannedVegitables.name = "Canned Tomatos";
		cannedVegitables.collectiveNoun = "cans";
		cannedVegitables.botulismRisk = true;
		cannedVegitables.amount = 0;

		cannedVegitables.hungerValue = 10;
		cannedVegitables.vitaminValue = 15;
		cannedVegitables.fatValue = 0;
		cannedVegitables.thirstValue = 15;

		cannedVegitables.id = 0;


		return cannedVegitables;
	}

	static Item initialiseCannedPinapples()
	{
		Item cannedPinapples;

		cannedPinapples.name = "Canned Pinapples";
		cannedPinapples.collectiveNoun = "cans";
		cannedPinapples.botulismRisk = true;
		cannedPinapples.amount = 0;

		cannedPinapples.hungerValue = 5;
		cannedPinapples.vitaminValue = 15;
		cannedPinapples.fatValue = 0;
		cannedPinapples.thirstValue = 20;

		cannedPinapples.id = 1;


		return cannedPinapples;
	}

	static Item initialiseCannedCorn()
	{
		Item cannedCorn;

		cannedCorn.name = "Canned Corn";
		cannedCorn.collectiveNoun = "cans";
		cannedCorn.botulismRisk = true;
		cannedCorn.amount = 0;

		cannedCorn.hungerValue = 15;
		cannedCorn.vitaminValue = 15;
		cannedCorn.fatValue = 0;
		cannedCorn.thirstValue = 10;

		cannedCorn.id = 2;


		return cannedCorn;
	}

	static Item initialiseWaterJug()
	{
		Item waterJug;

		waterJug.name = "Jug of Water";
		waterJug.collectiveNoun = "jugs";
		waterJug.amount = 0;

		waterJug.hungerValue = 0;
		waterJug.vitaminValue = 0;
		waterJug.fatValue = 0;
		waterJug.thirstValue = 40;


		waterJug.id = 3;


		return waterJug;
	}

	static Item initialiseInstantCoffee()
	{
		Item instantCoffee;

		instantCoffee.name = "Instant Coffee";
		instantCoffee.collectiveNoun = "tins";
		instantCoffee.amount = 0;

		instantCoffee.hungerValue = 0;
		instantCoffee.vitaminValue = 0;
		instantCoffee.fatValue = 0;
		instantCoffee.thirstValue = 15;
		instantCoffee.energyValue = 20;
		instantCoffee.warmthValue = 30;

		instantCoffee.id = 4;


		return instantCoffee;
	}



	static Item initialiseCannedBeer()
	{
		Item cannedBeer;

		cannedBeer.name = "Canned Beer";
		cannedBeer.collectiveNoun = "cans";
		cannedBeer.amount = 0;

		cannedBeer.hungerValue = 0;
		cannedBeer.vitaminValue = 0;
		cannedBeer.fatValue = 0;
		cannedBeer.thirstValue = 0;
		cannedBeer.energyValue = 0;
		cannedBeer.happinessValue = 15;

		cannedBeer.isAlcoholic = true;

		cannedBeer.id = 5;


		return cannedBeer;
	}

	static Item initialiseVenison()
	{
		Item venison;

		venison.name = "Venison Steak";
		venison.collectiveNoun = "steaks";
		venison.amount = 0;

		venison.hungerValue = 40;
		venison.vitaminValue = 0;
		venison.fatValue = 30;
		venison.thirstValue = 0;

		venison.id = 6;


		return venison;
	}

	static Item initialiseMutton()
	{
		Item mutton;

		mutton.name = "Mutton";
		mutton.collectiveNoun = "pounds";
		mutton.amount = 0;

		mutton.hungerValue = 40;
		mutton.vitaminValue = 0;
		mutton.fatValue = 30;
		mutton.thirstValue = 0;

		mutton.id = 7;

		return mutton;
	}

	static Item initialiseGoose()
	{
		Item goose;

		goose.name = "Goose";
		goose.collectiveNoun = "pounds";
		goose.amount = 0;

		goose.hungerValue = 30;
		goose.vitaminValue = 0;
		goose.fatValue = 50;
		goose.thirstValue = 0;

		goose.id = 8;

		return goose;
	}

	static Item initialiseDuck()
	{
		Item duck;

		duck.name = "Duck";
		duck.collectiveNoun = "pounds";
		duck.amount = 0;

		duck.hungerValue = 20;
		duck.vitaminValue = 0;
		duck.fatValue = 40;
		duck.thirstValue = 0;

		duck.id = 9;

		return duck;
	}

	static Item initialiseTurkey()
	{
		Item turkey;

		turkey.name = "Turkey";
		turkey.collectiveNoun = "pounds";
		turkey.amount = 0;

		turkey.hungerValue = 30;
		turkey.vitaminValue = 0;
		turkey.fatValue = 20;
		turkey.thirstValue = 0;

		turkey.id = 10;

		return turkey;
	}

	static Item initialiseSeagullMeat()
	{
		Item seagullMeat;

		seagullMeat.name = "Seagull Meat";
		seagullMeat.collectiveNoun = "ounces";
		seagullMeat.amount = 0;

		seagullMeat.hungerValue = 10;
		seagullMeat.vitaminValue = 0;
		seagullMeat.fatValue = 10;
		seagullMeat.thirstValue = 0;
		seagullMeat.botulismRisk = true;
		seagullMeat.riskFactor = 2;

		seagullMeat.id = 11;

		return seagullMeat;
	}

	static Item initialiseBeef()
	{
		Item beef;

		beef.name = "Beef";
		beef.collectiveNoun = "steaks";
		beef.amount = 0;

		beef.hungerValue = 50;
		beef.vitaminValue = 0;
		beef.fatValue = 25;
		beef.thirstValue = 0;

		beef.id = 12;

		return beef;
	}

	static Item initialiseHorseMeat()
	{
		Item horseMeat;

		horseMeat.name = "Horse Meat";
		horseMeat.collectiveNoun = "steaks";
		horseMeat.amount = 0;

		horseMeat.hungerValue = 50;
		horseMeat.vitaminValue = 0;
		horseMeat.fatValue = 15;
		horseMeat.thirstValue = 0;

		horseMeat.id = 13;

		return horseMeat;
	}


	static Item initialiseDogMeat()
	{
		Item dogMeat;

		dogMeat.name = "Dog Meat";
		dogMeat.collectiveNoun = "pounds";
		dogMeat.amount = 0;

		dogMeat.hungerValue = 25;
		dogMeat.vitaminValue = 0;
		dogMeat.fatValue = 10;
		dogMeat.thirstValue = 0;

		dogMeat.id = 14;

		return dogMeat;
	}

	static Item initialiseCatMeat()
	{
		Item catMeat;

		catMeat.name = "Cat Meat";
		catMeat.collectiveNoun = "pounds";
		catMeat.amount = 0;

		catMeat.hungerValue = 15;
		catMeat.vitaminValue = 0;
		catMeat.fatValue = 5;
		catMeat.thirstValue = 0;

		catMeat.id = 15;

		return catMeat;
	}

	static Item initialiseRabbit()
	{
		Item rabbit;

		rabbit.name = "Rabbit Meat";
		rabbit.collectiveNoun = "pounds";
		rabbit.amount = 0;

		rabbit.hungerValue = 20;
		rabbit.vitaminValue = 0;
		rabbit.fatValue = -10;
		rabbit.thirstValue = 0;

		rabbit.id = 16;

		return rabbit;
	}

	static Item initialiseSquirrel()
	{
		Item squirrel;

		squirrel.name = "Squirrel Meat";
		squirrel.collectiveNoun = "pounds";
		squirrel.amount = 0;

		squirrel.hungerValue = 20;
		squirrel.vitaminValue = 0;
		squirrel.fatValue = 15;
		squirrel.thirstValue = 0;

		squirrel.id = 17;

		return squirrel;
	}
	static Item initialiseBass()
	{
		Item bass;

		bass.name = "Bass Fillet";
		bass.collectiveNoun = "pounds";
		bass.amount = 0;

		bass.hungerValue = 20;
		bass.vitaminValue = 0;
		bass.fatValue = 10;
		bass.thirstValue = 4;

		bass.id = 18;


		return bass;
	}

	static Item initialiseSunfish()
	{
		Item sunfish;

		sunfish.name = "Sunfish Fillet";
		sunfish.collectiveNoun = "pounds";
		sunfish.amount = 0;

		sunfish.hungerValue = 10;
		sunfish.vitaminValue = 0;
		sunfish.fatValue = 5;
		sunfish.thirstValue = 2;

		sunfish.id = 19;


		return sunfish;
	}

	static Item initialiseDeadMouse()
	{
		Item deadMouse;

		deadMouse.name = "Dead Mouse";
		deadMouse.collectiveNoun = "mice";
		deadMouse.amount = 0;
		deadMouse.botulismRisk = true;
		deadMouse.riskFactor = 15;

		deadMouse.hungerValue = 5;
		deadMouse.vitaminValue = 0;
		deadMouse.fatValue = 1;
		deadMouse.thirstValue = 0;
		deadMouse.isGross = true;

		deadMouse.id = 20;

		return deadMouse;
	}

	static Item initialiseFrogLegs()
	{
		Item frogLegs;

		frogLegs.name = "Frog Legs";
		frogLegs.collectiveNoun = "pairs";
		frogLegs.amount = 0;

		frogLegs.hungerValue = 15;
		frogLegs.vitaminValue = 0;
		frogLegs.fatValue = 10;
		frogLegs.thirstValue = 0;

		frogLegs.id = 21;

		return frogLegs;
	}

	static Item initialiseBirdEgg()
	{
		Item birdEgg;

		birdEgg.name = "Bird Egg";
		birdEgg.collectiveNoun = "eggs";
		birdEgg.amount = 0;
		birdEgg.isGross = true;

		birdEgg.hungerValue = 3;
		birdEgg.vitaminValue = 0;
		birdEgg.fatValue = 1;
		birdEgg.thirstValue = 4;

		birdEgg.id = 22;


		return birdEgg;
	}

	static Item initialiseRaspberry()
	{
		Item raspberry;

		raspberry.name = "Raspberries";
		raspberry.collectiveNoun = "pounds";
		raspberry.amount = 0;

		raspberry.hungerValue = 10;
		raspberry.vitaminValue = 10;
		raspberry.fatValue = 0;
		raspberry.thirstValue = 10;

		raspberry.id = 23;

		return raspberry;
	}

	static Item initialiseHoney()
	{
		Item honey;

		honey.name = "Honey";
		honey.collectiveNoun = "ounces";
		honey.amount = 0;

		honey.hungerValue = 15;
		honey.vitaminValue = 0;
		honey.fatValue = 0;
		honey.thirstValue = 5;

		honey.id = 24;

		return honey;
	}

	static Item initialiseShaggyMane()
	{
		Item shaggyMane;

		shaggyMane.name = "Shaggy Mane";
		shaggyMane.collectiveNoun = "mushrooms";
		shaggyMane.amount = 0;

		shaggyMane.hungerValue = 15;
		shaggyMane.vitaminValue = 25;
		shaggyMane.fatValue = 0;
		shaggyMane.thirstValue = 0;
		shaggyMane.poisonRisk = true;

		shaggyMane.id = 25;

		return shaggyMane;
	}

	static Item initialiseMorel()
	{
		Item morel;

		morel.name = "Morel";
		morel.collectiveNoun = "mushrooms";
		morel.amount = 0;
		morel.hungerValue = 10;
		morel.vitaminValue = 25;
		morel.fatValue = 0;
		morel.thirstValue = 0;
		morel.poisonRisk = true;

		morel.id = 26;

		return morel;
	}

	static Item initialiseChickenOfWoods()
	{
		Item chickenOfWoods;

		chickenOfWoods.name = "Chicken of the Woods";
		chickenOfWoods.collectiveNoun = "pounds";
		chickenOfWoods.amount = 0;
		chickenOfWoods.hungerValue = 20;
		chickenOfWoods.vitaminValue = 25;
		chickenOfWoods.fatValue = 0;
		chickenOfWoods.thirstValue = 0;

		chickenOfWoods.id = 27;

		return chickenOfWoods;

	}

	static Item initialiseFishHook()
	{
		Item fishHook;

		fishHook.name = "Fish Hooks";
		fishHook.collectiveNoun = "hooks";
		fishHook.amount = 0;
		fishHook.isEdible = false;

		fishHook.id = 28;

		return fishHook;
	}

	static Item initialiseBullet()
	{
		Item bullet;

		bullet.name = "Bullets";
		bullet.collectiveNoun = "rounds";
		bullet.amount = 0;
		bullet.isEdible = false;

		bullet.id = 29;

		return bullet;
	}

	static Item initialiseFirstAidKit()
	{
		Item firstAidKit;

		firstAidKit.name = "First Aid Kit";
		firstAidKit.collectiveNoun = "bandages";
		firstAidKit.amount = 0;
		firstAidKit.curesInjury = true;

		firstAidKit.id = 30;

		return firstAidKit;
	}

	static Item initialiseAntibiotics()
	{
		Item antibiotics;

		antibiotics.name = "Antibiotics";
		antibiotics.collectiveNoun = "bottles";
		antibiotics.amount = 0;
		antibiotics.curesInfection = true;

		antibiotics.id = 31;

		return antibiotics;
	}

	static Item initialiseRabiesShot()
	{
		Item rabiesShot;

		rabiesShot.name = "Rabies Shot";
		rabiesShot.collectiveNoun = "needles";
		rabiesShot.amount = 0;
		rabiesShot.curesRabies = true;

		rabiesShot.id = 32;

		return rabiesShot;
	}

	static Item initialiseCharcoal()
	{
		Item charcoal;

		charcoal.name = "Charcoal";
		charcoal.collectiveNoun = "ounces";
		charcoal.amount = 0;
		charcoal.curesPoison = true;
		charcoal.isGross = true;

		charcoal.id = 33;

		return charcoal;
	}

	static Item initialiseAntitoxin()
	{
		Item antitoxin;

		antitoxin.name = "Antitoxin";
		antitoxin.collectiveNoun = "bottles";
		antitoxin.amount = 0;
		antitoxin.curesBotulism = true;

		antitoxin.id = 34;

		return antitoxin;
	}

	static Item initialiseTea()
	{
		Item tea;

		tea.name = "Tea";
		tea.collectiveNoun = "bags";
		tea.amount = 0;

		tea.thirstValue = 20;
		tea.energyValue = 15;
		tea.warmthValue = 30;

		tea.id = 35;

		return tea;
	}

	static Item initialiseMussel()
	{
		Item mussel;

		mussel.name = "mussel";
		mussel.collectiveNoun = "pounds";
		mussel.amount = 0;

		mussel.hungerValue = 5;
		mussel.thirstValue = 2;
		mussel.fatValue = 3;

		mussel.id = 36;

		return mussel;
	}

	static Item initialiseSalmon()
	{
		Item salmon;

		salmon.name = "Salmon Fillet";
		salmon.collectiveNoun = "pounds";
		salmon.amount = 0;

		salmon.hungerValue = 40;
		salmon.vitaminValue = 0;
		salmon.fatValue = 20;
		salmon.thirstValue = 15;

		salmon.id = 37;


		return salmon;
	}






	static void supplyCheck(Item& cannedVegitables, Player& player, Item& waterJug, Item& venison, Item& rabbit, Item& fishHook, Item& bass, Item& bullet, Item& firstAidKit, Item& antibiotics, Item& squirrel, Item& dogMeat, Day& day, Item& charcoal, Item& cannedPinapples, Item& cannedCorn, Item& antitoxin, Item& shaggyMane, Item& mutton, Item& frogLegs, Item& birdEgg, Item& honey, Item& sunfish, Item& catMeat, Item& deadMouse, Item& rabiesShot, Item& instantCoffee, Item& cannedBeer, Item& raspberries, Item& morel, Item& chickenOfWoods, Item& goose, Item& turkey, Item& duck, Item& seagullMeat, Item& beef, Item& horseMeat, Item& tea, Item& mussel, Item& salmon)
	{


		char itemQuery[100] = {};
		int itemQueryNum;
		bool stillInMenu = true;
		bool throwAwayMode = false;
		bool numericQuery = true;

		int i, j;

		bool bust = true, bash = true; // these are used for some fors, the name is arbitrary

		/*
		for (int i = 0; i < 100; i++)
		{
			itemQuery[i] = '0';
		}
		*/


		//const int LENGTH = 35;

		//this is janky but better than before

		Item allItems[LENGTH] = { cannedVegitables, waterJug,  venison,  rabbit, fishHook,  bass,  bullet,  firstAidKit,  antibiotics,  squirrel, dogMeat,charcoal,  cannedPinapples,  cannedCorn,  antitoxin,  shaggyMane,  mutton,  frogLegs,  birdEgg,  honey,  sunfish,  catMeat,  deadMouse,  rabiesShot,  instantCoffee,  cannedBeer,  raspberries,  morel,  chickenOfWoods,  goose,  turkey,  duck,  seagullMeat,  beef, horseMeat, tea, mussel, salmon };

		while (stillInMenu)
		{
			system("CLS");

			Text::printOut("INVENTORY\n", player.getSanity());


			Text::printOut("Hunger " + to_string(player.hunger) + " % Thirst " + to_string(player.thirst) + " % Energy " + to_string(player.energy), player.getSanity());

			if (day.seasonNum == 4)
			{
				Text::printOut(" Warmth " + to_string(player.warmth) + "%\n\n", player.getSanity());
			}
			else
			{
				Text::printOut("%\n\n", player.getSanity());
			}

			for (int i = 0; i < LENGTH; i++)
			{
				if (allItems[i].amount > 0)
				{

					Text::printOut("\t" + to_string(i + 1) + ". " + allItems[i].name + ": (" + to_string(allItems[i].amount) + ") " + allItems[i].collectiveNoun + ".\n\n", player.getSanity());
				}
			}

			Text::printOut("NOTICE: new and improved menu that took 6+ hours to debug!\nYou can enter the name of the item now!\n\n", player.getSanity());

			if (throwAwayMode)
			{
				Text::printOut("Enter item number OR item name to throw away, or enter 0 to exit throw away mode.\n", player.getSanity());
				Text::printOut("Enter \'L\' to leave this menu.\n", player.getSanity());
			}
			else
			{
				Text::printOut("Enter item number OR item name to consume, or enter 0 to throw something away.\n", player.getSanity());
				Text::printOut("Enter \'L\' to leave this menu.\n", player.getSanity());
			}


			for (int i = 0; i < 100; i++) // galaxy brain moment
			{
				itemQuery[i] = '\0';
			}



			//cin >> itemQuery;

			//cin.clear();

			Text::printOut(">");

			cin.sync();

			cin.getline(itemQuery, 100);

			//getline(cin >> ws, itemQuery);

			//cin >> itemQuery;

			//cout << itemQuery << endl;



			int queryCount;

			for (queryCount = 0; itemQuery[queryCount] != '\0'; queryCount++) // galaxy brain moment




				numericQuery = true;

			// if itemQuery is numeric, cast itemQueryNum to it to do as it was before, if not do the other thing

			//

			for (int i = 0; i < queryCount; i++) // this checks if the char array is numeric
			{
				//cout << "letter number " << i << endl;

				if (itemQuery[i] != '\n')
				{
					switch (itemQuery[i])
					{
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						//cout << "true numeric";
						numericQuery = true;
						break;
					default:
						//cout << "not numeric";
						numericQuery = false;
						break;
					}
				}

			}

			cin.clear();

			if (numericQuery) // this creates an int if the char array is a number
			{
				//sscanf_s(itemQuery, "%d", &itemQueryNum);

				itemQueryNum = 0;

				for (int i = 0; i < queryCount; i++)
				{
					itemQueryNum += (itemQuery[i] - '0') * pow(10, queryCount - i - 1);
				}

				//staticcast?
			}



			PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);


			if (stillInMenu)
			{
				if (numericQuery)
				{
					//cout << "ItemQueryNum is " << itemQueryNum << endl;

					if (itemQueryNum == 0)
					{

						if (throwAwayMode)
						{
							throwAwayMode = false;
						}
						else
						{
							throwAwayMode = true;
						}
					}
					else if (itemQueryNum <= LENGTH && itemQueryNum > 0)
					{
						//cout << "eat is happening inside of the NUMERIC options" << endl;
						//cout << "eating is happening to item num " << itemQueryNum << endl;
						itemQueryNum--;
						eat(player, allItems[itemQueryNum], day, throwAwayMode);
						itemQueryNum++;
					}
					else
					{
						Text::printOut("No such item exists\n", player.getSanity());

					}
				}
				else
				{
					//cout << "it gets to the for mess" << endl;
					bust = true, bash = true;
					i = 0;
					j = 0;

					for (i = 0; i < LENGTH && bash && !(toupper(itemQuery[0]) == 'L' && queryCount == 1); i++) // items
					{
						//cout << "i = " << i << endl;

						bust = true;

						for (j = 0; j < allItems[i].name.length() && bust; j++) // chars in items
						{
							//cout << "j = " << j << endl;

							if (toupper(allItems[i].name[j]) == toupper(itemQuery[j]))
							{
								if ((j + 1) == allItems[i].name.length())
								{
									//it should be the right word
									//cout << "eat is happening inside of the ALPHABETIC options" << endl;
									//cout << "eating is happening to item num " << i << endl;
									eat(player, allItems[i], day, throwAwayMode);
									bust = false;
									bash = false;
								}
							}
							else
							{
								bust = false; // move on to next word

								// letter iterator gets through the word and it's the last word
								if (i == LENGTH - 1)
								{
									Text::printOut("No such item exists\n", player.getSanity());
								}
							}


						}
					}

					if (toupper(itemQuery[0]) == 'L' && queryCount == 1)
					{
						stillInMenu = false;
					}
				}

				//cout << "issue with still in menu" << endl;

			}

			system("pause");
		}


		//system("pause");
	}

	static void eat(Player& player, Item& item, Day& day, bool throwaWayMode)
	{
		//cout << "Would you like to consume this (1), or throw it away (2)? " << endl;
		int itemQuery;
		char keepAns;
		bool rabbitCure = false;

		/*

		cin >> itemQuery;

		while (cin.fail() || (itemQuery != 1 && itemQuery != 2))
		{
			cin.clear();
			cin.ignore(500, '\n');

			cout << "Error: enter 1 or 2." << endl;

			cin >> itemQuery;
		}

		*/

		if (!throwaWayMode)
		{
			if (!item.isEdible)
			{
				Text::printOut("You can't eat " + item.name + ", you silly sausage.\n", player.getSanity());
			}
			else if (item.amount < 1)
			{
				Text::printOut("You are currently out of " + item.name + ".\n", player.getSanity());
			}
			else
			{
				item.amount -= 1;
				player.hunger += item.hungerValue;
				player.vitamins += item.vitaminValue;
				player.fat += item.fatValue;
				player.thirst += item.thirstValue;
				player.energy += item.energyValue;
				player.happiness += item.happinessValue;
				player.warmth += item.warmthValue;

				if (player.hunger > (100 - player.rabbitCounter))
				{
					player.hunger = 100 - player.rabbitCounter;
				}

				if (item.fatValue > 0 && (player.fat + item.fatValue) > 20 && player.rabbitCounter > 0)
				{
					rabbitCure = true;
					player.rabbitCounter = 0;
				}

				player.hunger = Player::percentRestraint(player.hunger);
				player.vitamins = Player::percentRestraint(player.vitamins);
				player.fat = Player::percentRestraint(player.fat);
				player.thirst = Player::percentRestraint(player.thirst);
				player.energy = Player::percentRestraint(player.energy);
				player.happiness = Player::percentRestraint(player.happiness);
				player.warmth = Player::percentRestraint(player.warmth);

				if (item.amount == 0)
				{
					item.riskFactor = 0;
				}

				Text::printOut("You eat one " + item.name + ".\n", player.getSanity());

				if (item.hungerValue > 0)
				{
					Text::printOut("\t+" + to_string(item.hungerValue) + "% hunger\n", player.getSanity());
					Text::printOut("\t\tTotal Hunger: " + to_string(player.hunger) + "\n", player.getSanity());
				}


				if (item.thirstValue > 0)
				{
					Text::printOut("\t+" + to_string(item.thirstValue) + "% thirst\n", player.getSanity());
					Text::printOut("\t\tTotal Thirst: " + to_string(player.thirst) + "\n", player.getSanity());
				}

				if (item.energyValue > 0)
				{
					Text::printOut("\t+" + to_string(item.energyValue) + "% energy\n", player.getSanity());
					Text::printOut("\t\tTotal Energy: " + to_string(player.energy) + "\n", player.getSanity());
				}

				if (item.happinessValue > 0)
				{
					Text::printOut("\t+" + to_string(item.happinessValue) + "% happiness\n", player.getSanity());
					Text::printOut("\t\tTotal Happiness: " + to_string(player.happiness) + "\n", player.getSanity());
				}

				if (item.warmthValue > 0 && day.seasonNum == 4)
				{
					Text::printOut("\t+" + to_string(item.warmthValue) + "% warmth\n", player.getSanity());
					Text::printOut("\t\tTotal Warmth: " + to_string(player.warmth) + "\n", player.getSanity());
				}

				if (rabbitCure)
				{
					Text::printOut("Rabbit Starvation cured\n", player.getSanity());
				}

				if (item.fatValue < 1 && player.rabbitCounter > 0 && player.hunger == 100 - (player.rabbitCounter))
				{
					Text::printOut("\n... You eat, but it does not satiate you.\n", player.getSanity());
				}



				if (item.botulismRisk)
				{
					if ((rand() % 100) < item.riskFactor)
					{
						player.hasBotulism = true;
						day.updateInfo = true; // isNextDay is poorly named, a better descriptor would be 'update warnings'.
					}
				}

				if (item.poisonRisk)
				{
					if ((rand() % 100) < item.riskFactor)
					{
						player.isPoisoned = true;
						day.updateInfo = true; // isNextDay is poorly named, a better descriptor would be 'update warnings'.
					}
				}

				if (item.curesInjury)
				{
					if (player.isInjured)
					{
						Text::printOut("Injury Cured.\n", player.getSanity());
						player.isInjured = false;
						day.updateInfo = true;
					}
					else
					{
						Text::printOut("This has no effect.\n", player.getSanity());
					}
				}

				if (item.curesInfection)
				{
					if (player.hasInfection)
					{
						Text::printOut("Infection Cured.\n", player.getSanity());
						player.hasInfection = false;
						day.updateInfo = true;
					}
					else
					{
						Text::printOut("This has no effect.\n", player.getSanity());
					}
				}

				if (item.curesPoison)
				{
					if (player.isPoisoned)
					{
						Text::printOut("Poisoning Cured.\n", player.getSanity());
						player.isPoisoned = false;
						day.updateInfo = true;
					}
					else
					{
						Text::printOut("This has no effect.\n", player.getSanity());
					}
				}

				if (item.curesRabies)
				{
					if (player.rabiesCure || player.rabiesDeath)
					{
						Text::printOut("This has no effect.\n", player.getSanity());
					}
					else
					{
						Text::printOut("Rabies Cured.\n", player.getSanity());
						player.hasRabies = false;
						day.updateInfo = true;
						player.rabiesCure = true;
					}

				}

				if (item.isGross)
				{
					player.happiness -= 10;

					player.happiness = Player::percentRestraint(player.happiness);

					PlaySound(TEXT("pufferfish.wav"), NULL, SND_ASYNC);

					Text::printOut("... that was awful.\n\t -10 Happiness\n", player.getSanity());
				}

				if (item.isAlcoholic)
				{
					if ((rand() % 2) == 1 && player.drunkCounter < 4)
					{
						player.drunkCounter += 1;

						playerDrunk(player, day);

					}
				}

			}
		}
		else
		{
			Text::printOut("Are you sure you want to throw away all of your " + item.name + "? (Y/N)\n", player.getSanity());
			Text::printOut(">");
			cin >> keepAns;
			cin.ignore(1000, '\n');

			PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

			while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
			{
				Text::printOut("\nInvalid entry, enter only Y or N.\n", player.getSanity());
				Text::printOut(">");
				cin >> keepAns;
				cin.ignore(1000, '\n');
			}

			if ((toupper(keepAns) == 'Y'))
			{
				item.amount = 0;
				item.riskFactor = 0;

				Text::printOut("You throw away your " + item.name + ".\n", player.getSanity());
			}
		}

		cout << endl;
		//system("pause");


	}



	static void maul(string beastName, int dangerLevel, Day day, Player& player, Item& bullet)
	{

		Text::printOut("The " + beastName + " pins you down on the ground.\n", player.getSanity());

		switch (rand() % dangerLevel)
		{
		case 0:
			Text::printOut("It utterly rips you to shreads.\n\n", player.getSanity());

			player.maulDeath = true;

			break;
		default:
			Text::printOut("You struggle and thrash to fight the " + beastName + ".\n", player.getSanity());

			if (player.hasHuntingRifle && bullet.amount > 0)
			{
				Text::printOut("You manage to get your gun out and shoot it.\n", player.getSanity());
			}
			else
			{
				Text::printOut("You stab at it with your knife until it collapses.\n", player.getSanity());
			}

			Text::printOut("\nStill alive, you stumble your way home.\n", player.getSanity());
			Text::printOut("\t-30 energy\n", player.getSanity());
			Text::printOut("\t-20 happiness.\n", player.getSanity());
			Text::printOut("\t-20 sanity\n", player.getSanity());

			player.isInjured = true;

			player.sanity -= 20;
			player.sanity = Player::percentRestraint(player.sanity);

			player.happiness -= 20;
			player.happiness = Player::percentRestraint(player.sanity);

			player.energy -= 30;
			player.energy = Player::percentRestraint(player.energy);

			break;
		}

	}

	static void playerDrunk(Player& player, Day& day)
	{
		switch (player.drunkCounter)
		{
		case 1:
			day.drunkInformation = "You're feeling a bit tipsy.\n", player.getSanity();
			break;
		case 2:
			day.drunkInformation = "You're kinda drunk now.\n", player.getSanity();
			player.energy -= 15;
			player.energy = Player::percentRestraint(player.energy);
			break;
		case 3:
			day.drunkInformation = "You're quite sloshed.\n", player.getSanity();
			player.energy -= 30;
			player.energy = Player::percentRestraint(player.energy);
			player.hasHangover = true;
			break;
		default:
			day.drunkInformation = "Error in playerDrunk()\n", player.getSanity();
			break;
		}
	}

};



