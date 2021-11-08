#include "RandomEvent.h"


class PlayerAction
{
public:

	static int localRarity(Item& item, Location* location)
	{
		//size_t sizeOfCommonItems = sizeof(location.commonItem) / sizeof(location.commonItem[0]);

		for (int i = 0; i <= Item::LENGTH; i++)
		{
			if (item.id == location->abundantItem[i])
			{
				return -5;
			}

			if (item.id == location->commonItem[i])
			{
				return 0;
			}

			if (item.id == location->uncommonItem[i])
			{
				return 5;
			}

			if (item.id == location->rareItem[i])
			{
				return 10;
			}

			if (item.id == location->noItem[i])
			{
				return 10000;
			}

			if (i == Item::LENGTH)
			{
				return 0; // this is if I missed it, it's considered common
			}

		}

		// prob += Location::localRarity(item, location);

		// you're checking if an item is in the locations common, rare, very rare item arrays
		//when loot, hunt, gofish are done, ADD item.localRarity() to the reroll variable.
	}

	static void goFish(Player& player, Day& day, Location* locationPTR, Item& bass, Item& sunfish, Item& mussel, Item& salmon)
	{
		int randEvent, prob;
		int amountAquired;
		//char keepAns;
		//int randRisk;

		bool roll = true;

		randEvent = (rand() % 5) + 1;

		system("CLS");
		while (roll)
		{
			switch (randEvent)
			{
			case 1:
				prob = 10;

				prob += localRarity(bass, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You catch a bass.\n");

				if (rand() % 4 == 0)
				{
					Text::printOut("\nWhat a catch!\n");
					amountAquired *= 2;
					Text::printOut("\t+20 Happiness\n\n");
					player.happiness += 20;
				}

				amountAquired = (rand() % 3) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") bass.\n");

				bass.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(bass.amount) + ") total.\n");

				roll = false;
				break;
			case 2:

				prob = 10;

				prob += localRarity(sunfish, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You catch some sunfish.\n");

				amountAquired = (rand() % 5) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") sunfish.\n");

				sunfish.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(sunfish.amount) + ") total.\n");

				roll = false;
				break;

			case 3:
				prob = 10;

				prob += localRarity(mussel, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You catch nothing... but you find some mussels.\n");

				amountAquired = (rand() % 8) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") mussels.\n");

				mussel.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(mussel.amount) + ") total.\n");

				roll = false;
				break;
			case 4:
				prob = 15;

				prob += localRarity(salmon, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You catch a salmon!\n");

				amountAquired = (rand() % 5) + 5;

				if (rand() % 4 == 0)
				{
					Text::printOut("\nWhat a catch!\n");
					amountAquired *= 2;
					Text::printOut("\t+20 Happiness\n\n");
					player.happiness += 20;
				}

				Text::printOut("Found (" + to_string(amountAquired) + ") pounds.\n");

				salmon.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(salmon.amount) + ") pounds total.\n");

				roll = false;
				break;

			default:

				prob = 10;

				prob += (day.totalDays < 15 ? -5 : 0);
				prob += (day.totalDays > 30 ? 5 : 0);

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You catch nothing.\n");

				roll = false;
				break;

			}
		}


		cout << endl;
		system("pause");
	}

	static void hunt(Player& player, Day& day, Location* locationPTR, Item& venison, Item& rabbit, Item& bullet, Item& squirrel, Item& dogMeat, Item& mutton, Item& catMeat, Item& goose, Item& turkey, Item& duck, Item& seagullMeat, Item& beef, Item& horseMeat)
	{
		int randEvent;
		int amountAquired;
		char keepAns;
		bool roll = true;
		bool dogRoll = true;
		//char keepAns;
		//int randRisk;

		int prob = 0;



		system("CLS");

		while (roll)
		{

			randEvent = (rand() % 13) + 1;

			switch (randEvent)
			{
			case 1:

				prob = 10;

				prob += localRarity(venison, locationPTR);

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				if (day.totalDays <= 20)
				{
					prob += (20 - day.totalDays);
				}

				if (rand() % prob > 0) // rerolling allows adjusted probability
				{
					break;
				}

				Text::printOut("You shoot a deer.\n");

				amountAquired = (rand() % 1) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") venison steak.\n");

				venison.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(venison.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;
			case 2:

				prob = 5;

				prob += localRarity(rabbit, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You shoot a rabbit.\n");

				amountAquired = (rand() % 3) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") rabbit meat.\n");

				rabbit.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(rabbit.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;

			case 3:
				prob = 5;

				prob += localRarity(squirrel, locationPTR);

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You shoot a squirrel.\n");

				amountAquired = (rand() % 3) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") squirrel meat.\n");

				squirrel.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(squirrel.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;
			case 4:
				prob = 5;

				prob += localRarity(dogMeat, locationPTR);

				prob += day.totalDays / 10;

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				if (rand() % prob > 0)
				{
					break;
				}
				Text::printOut("You find a feral dog.\n");
				Text::printOut("... You could shoot and eat it, but is that something you want to do?\n");

				Text::printOut("\nEnter (Y/N): ");
				Text::printOut("\n\n>");
				cin >> keepAns;
				cin.ignore(1000, '\n');

				PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

				while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
				{
					Text::printOut("\nInvalid entry, enter only Y or N.\n");
					Text::printOut(">");
					cin >> keepAns;
					cin.ignore(1000, '\n');
				}

				if (toupper(keepAns) == 'Y')
				{
					amountAquired = (rand() % 3) + 1;

					Text::printOut("Found (" + to_string(amountAquired) + ") dog meat.\n");

					dogMeat.amount += amountAquired;

					Text::printOut("\tYou have (" + to_string(dogMeat.amount) + ") total.\n");

					bullet.amount -= amountAquired;

				}
				else
				{
					Text::printOut("\nYou leave it behind.\n");
				}

				roll = false;
				break;
			case 5:
				prob = 10;

				prob += localRarity(mutton, locationPTR);

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				if (day.totalDays < 40)
				{
					break;
				}

				if (day.totalDays > 70)
				{
					prob /= 2;
				}

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You shoot a feral sheep.\n");

				amountAquired = (rand() % 3) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") mutton.\n");

				mutton.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(mutton.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;
			case 6:
				prob = 10;

				prob += localRarity(catMeat, locationPTR);

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You find a feral cat.\n");
				Text::printOut("... You could shoot and eat it, but is that something you want to do?\n");

				Text::printOut("\nEnter (Y/N): ");

				Text::printOut("\n\n>");
				cin >> keepAns;
				cin.ignore(1000, '\n');

				PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

				while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
				{
					Text::printOut("\nInvalid entry, enter only Y or N.\n");
					Text::printOut(">");
					cin >> keepAns;
					cin.ignore(1000, '\n');
				}

				if (toupper(keepAns) == 'Y')
				{
					amountAquired = (rand() % 2) + 1;

					Text::printOut("Found (" + to_string(amountAquired) + ") cat meat.\n");

					catMeat.amount += amountAquired;

					Text::printOut("\tYou have (" + to_string(catMeat.amount) + ") total.\n");

					bullet.amount -= amountAquired;

				}
				else
				{
					Text::printOut("\nYou leave it behind.\n");
				}

				roll = false;
				break;
			case 7:

				prob = 10;

				prob += localRarity(goose, locationPTR);

				if (day.seasonNum == 4)
				{
					prob += 10000;
				}

				if (day.totalDays < 25)
				{
					prob /= 2;
				}

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You shoot a goose.\n");

				amountAquired = (rand() % 2) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") goose.\n");

				goose.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(goose.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;
			case 8:

				prob = 10;

				prob += localRarity(turkey, locationPTR);

				if (day.totalDays > 25)
				{
					prob /= 2;
				}

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You shoot a turkey.\n");

				amountAquired = (rand() % 3) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") turkey.\n");

				turkey.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(turkey.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;
			case 9:

				prob = 10;

				prob += localRarity(duck, locationPTR);

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You shoot a duck.\n");

				amountAquired = (rand() % 3) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") duck.\n");

				duck.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(duck.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;
			case 10:

				prob = 1;

				prob += day.totalDays / 5;

				if (locationPTR->locationName == "Front St.") //water front areas the populations don't drop so much
				{
					prob = 10;
				}

				prob += localRarity(seagullMeat, locationPTR);

				if (day.seasonNum == 4)
				{
					prob += 1000000;
				}

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You shoot a seagull.\n");

				amountAquired = (rand() % 5) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") seagull meat.\n");

				seagullMeat.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(seagullMeat.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;
			case 11:

				if (day.totalDays < 40)
				{
					break;
				}

				prob = 10;


				prob += localRarity(beef, locationPTR);

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				if (rand() % prob > 0)
				{
					break;
				}



				Text::printOut("You shoot a feral cow.\n");

				amountAquired = (rand() % 2) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") beef.\n");

				beef.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(beef.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;
			case 12:

				if (day.totalDays < 40)
				{
					break;
				}

				if (day.seasonNum == 4)
				{
					prob += 10;
				}

				prob = 10;

				prob += localRarity(horseMeat, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}


				Text::printOut("You shoot a feral horse.\n");

				amountAquired = (rand() % 2) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") horse meat.\n");

				horseMeat.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(horseMeat.amount) + ") total.\n");

				bullet.amount -= amountAquired;

				roll = false;
				break;

			default:

				prob = 10;

				if (day.totalDays < 20)
				{
					prob /= 2;
				}

				if (day.seasonNum == 4)
				{
					prob /= 2;
				}


				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("You catch nothing.\n");

				roll = false;
				break;
			}

			if (player.hasTheDog && !roll)
			{
				while (dogRoll)
				{
					switch (rand() % 10)
					{
					case 1:

						prob = 5;

						prob += localRarity(rabbit, locationPTR);

						if (rand() % prob > 0)
						{
							break;
						}

						amountAquired = (rand() % 3) + 1;

						Text::printOut("\n.. and " + player.dogName + " caught a rabbit!\n\n");


						Text::printOut(player.dog + "\n\n");

						Text::printOut("Found (" + to_string(amountAquired) + ") rabbit meat.\n");

						rabbit.amount += amountAquired;

						Text::printOut("\tYou have (" + to_string(rabbit.amount) + ") total.\n");

						PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

						dogRoll = false;
						break;
					case 2:

						prob = 5;

						prob += localRarity(squirrel, locationPTR);

						if (day.seasonNum == 4)
						{
							prob += 10;
						}

						if (rand() % prob > 0)
						{
							break;
						}

						amountAquired = (rand() % 3) + 1;

						Text::printOut("\n.. and " + player.dogName + " caught a squirrel!\n\n");

						Text::printOut(player.dog + "\n\n");

						Text::printOut("Found (" + to_string(amountAquired) + ") squirrel meat.\n");

						squirrel.amount += amountAquired;

						Text::printOut("\tYou have (" + to_string(squirrel.amount) + ") total.\n");

						PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

						dogRoll = false;
						break;
					case 3:

						prob = 10;

						prob += localRarity(duck, locationPTR);

						if (day.seasonNum == 4)
						{
							prob += 10;
						}

						if (rand() % prob > 0)
						{
							break;
						}

						amountAquired = (rand() % 3) + 1;

						Text::printOut("\n.. and " + player.dogName + " caught a duck!\n\n");

						Text::printOut(player.dog + "\n\n");

						Text::printOut("Found (" + to_string(amountAquired) + ") duck.\n");

						duck.amount += amountAquired;

						Text::printOut("\tYou have (" + to_string(duck.amount) + ") total.\n");

						PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

						dogRoll = false;
						break;
					case 4:

						prob = 1;

						prob += day.totalDays / 5;

						prob += localRarity(seagullMeat, locationPTR);

						if (day.seasonNum == 4)
						{
							prob += 1000000;
						}

						if (rand() % prob > 0)
						{
							break;
						}

						amountAquired = (rand() % 3) + 1;

						Text::printOut("\n.. and " + player.dogName + " caught a seagull!\n\n");

						Text::printOut(player.dog + "\n\n");

						Text::printOut("Found (" + to_string(amountAquired) + ") seagull.\n");

						seagullMeat.amount += amountAquired;

						Text::printOut("\tYou have (" + to_string(seagullMeat.amount) + ") total.\n");

						PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

						dogRoll = false;
						break;
					}
				}

			}
		}


		if (bullet.amount < 0)
			bullet.amount = 0;

		cout << endl;

		system("pause");
	}

	static void loot(Item& cannedVegitables, Day day, Location* locationPTR, Item& waterJug, Player& player, Item& fishHook, Item& bullet, Item& firstAidKit, Item& antibiotics, Item& charcoal, Item& cannedPinapples, Item& cannedCorn, Item& antitoxin, Item& rabiesShot, Item& instantCoffee, Item& cannedBeer, Item& tea)
	{
		int randEvent;
		int amountAquired;
		char keepAns;
		int randRisk;
		bool roll = true;
		int prob;




		system("CLS");

		while (roll)
		{
			randEvent = (rand() % 16) + 1;

			switch (randEvent)
			{
			case 1:

				prob = 10;

				prob += localRarity(cannedVegitables, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = (rand() % 5) + 1;


				Text::printOut("Found (" + to_string(amountAquired) + ") Canned Tomatos.\n");


				randRisk = (rand() % 100) + 1;

				randRisk += (day.totalDays / 4);

				if (randRisk > 90)
				{
					switch (rand() % 3)
					{
					case 0:
						Text::printOut("\n\nThese cans are rusted a bit, do you think they're still fine to eat?");
						break;
					case 1:
						Text::printOut("\n\nOne of these cans seems a bit off, will you still keep it?");
						break;
					case 2:
						Text::printOut("\n\nThese cans don't smell very fresh anymore, will you still keep them?");
						break;
					}

					Text::printOut("\nEnter (Y/N): ");
					Text::printOut("\n\n>");

					cin >> keepAns;
					cin.ignore(1000, '\n');

					PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

					while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
					{
						Text::printOut("\nInvalid entry, enter only Y or N.\n");
						Text::printOut(">");
						cin >> keepAns;
						cin.ignore(1000, '\n');
					}

					if (toupper(keepAns) == 'Y')
					{
						cannedVegitables.riskFactor += (amountAquired / (++cannedVegitables.amount)) * 10;

						cannedVegitables.riskFactor = Player::percentRestraint(cannedVegitables.riskFactor);

					}
					else
					{
						Text::printOut("\nYou throw them away, seems like a waste, but better to be safe right?");
					}


				}
				else
				{
					keepAns = 'Y';
				}

				if (keepAns == 'Y')
				{
					cannedVegitables.amount += amountAquired;

					Text::printOut("\tYou have (" + to_string(cannedVegitables.amount) + ") total.");
				}

				roll = false;
				break;
			case 2:

				prob = 10;

				prob += localRarity(waterJug, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = (rand() % 2) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") Jugs of water.\n");

				waterJug.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(waterJug.amount) + ") total.");

				roll = false;
				break;
			case 3:

				prob = 10;

				prob += randomEvent::eventRarity(locationPTR, "findFishingRod");

				if (rand() % prob > 0)
				{
					break;
				}

				if (player.hasFishingRod)
				{
					break;
				}
				else
				{
					Text::printOut("You found a fishing rod!\n");
					player.hasFishingRod = true;
				}
				roll = false;
				break;

			case 4:

				prob = 10;

				prob += localRarity(fishHook, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = (rand() % 3) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") fish hooks.\n");

				fishHook.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(fishHook.amount) + ") total.\n");
				roll = false;
				break;

			case 5:

				prob = 10;

				prob += randomEvent::eventRarity(locationPTR, "findRifle");

				if (rand() % prob > 0)
				{
					break;
				}

				if (player.hasHuntingRifle)
				{
					break;
				}
				else
				{
					Text::printOut("You found a hunting rifle!\n");
					player.hasHuntingRifle = true;
				}
				roll = false;
				break;
			case 6:

				prob = 10;

				prob += localRarity(bullet, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = (rand() % 10) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") bullets.\n");

				bullet.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(bullet.amount) + ") total.\n");
				roll = false;
				break;

			case 7:

				prob = 10;

				prob += localRarity(firstAidKit, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") first aid kit.\n");

				firstAidKit.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(firstAidKit.amount) + ") total.\n");
				roll = false;
				break;
			case 8:
				prob = 10;

				prob += localRarity(antibiotics, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = (rand() % 2) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") antibiotics.\n");

				antibiotics.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(antibiotics.amount) + ") total.\n");
				roll = false;
				break;
			case 9:
				prob = 10;

				prob += localRarity(charcoal, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = (rand() % 2) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") charcoal.\n");

				charcoal.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(charcoal.amount) + ") total.\n");
				roll = false;
				break;
			case 10:
				prob = 10;

				prob += localRarity(cannedPinapples, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}


				amountAquired = (rand() % 5) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") canned pinapples.\n");

				randRisk = (rand() % 100) + 1;

				randRisk += (day.totalDays / 4);

				if (randRisk > 90)
				{
					switch (rand() % 3)
					{
					case 0:
						Text::printOut("\n\nThese cans are rusted a bit, do you think they're still fine to eat?");
						break;
					case 1:
						Text::printOut("\n\nOne of these cans seems a bit off, will you still keep it?");
						break;
					case 2:
						Text::printOut("\n\nThese cans don't smell very fresh anymore, will you still keep them?");
						break;
					}

					Text::printOut("\nEnter (Y/N): ");

					Text::printOut("\n\n>");
					cin >> keepAns;
					cin.ignore(1000, '\n');

					PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

					while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
					{
						Text::printOut("\nInvalid entry, enter only Y or N.\n");
						Text::printOut(">");
						cin >> keepAns;
						cin.ignore(1000, '\n');
					}

					if (toupper(keepAns) == 'Y')
					{
						cannedPinapples.riskFactor += (amountAquired / (++cannedPinapples.amount)) * 10;

						cannedPinapples.riskFactor = Player::percentRestraint(cannedPinapples.riskFactor);

					}
					else
					{
						Text::printOut("\nYou throw them away, seems like a waste, but better to be safe right?");
					}


				}
				else
				{
					keepAns = 'Y';
				}

				if (keepAns == 'Y')
				{
					cannedPinapples.amount += amountAquired;


					Text::printOut("\tYou have (" + to_string(cannedPinapples.amount) + ") total.\n");
				}
				roll = false;
				break;
			case 11:

				prob = 10;

				prob += localRarity(cannedCorn, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}


				amountAquired = (rand() % 5) + 1;


				Text::printOut("Found (" + to_string(amountAquired) + ") canned corn.\n");



				randRisk = (rand() % 100) + 1;

				randRisk += (day.totalDays / 4);

				if (randRisk > 95)
				{
					switch (rand() % 3)
					{
					case 0:
						Text::printOut("\n\nThese cans are rusted a bit, do you think they're still fine to eat?");
						break;
					case 1:
						Text::printOut("\n\nOne of these cans seems a bit off, will you still keep it?");
						break;
					case 2:
						Text::printOut("\n\nThese cans don't smell very fresh anymore, will you still keep them?");
						break;
					}

					Text::printOut("\nEnter (Y/N): ");
					Text::printOut("\n\n>");

					cin >> keepAns;
					cin.ignore(1000, '\n');

					PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

					while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
					{
						Text::printOut("\nInvalid entry, enter only Y or N.\n");
						Text::printOut(">");
						cin >> keepAns;
						cin.ignore(1000, '\n');
					}

					if (toupper(keepAns) == 'Y')
					{
						cannedCorn.riskFactor += (amountAquired / (++cannedPinapples.amount)) * 10;

						cannedCorn.riskFactor = Player::percentRestraint(cannedCorn.riskFactor);

					}
					else
					{
						Text::printOut("\nYou throw them away, seems like a waste, but better to be safe right?");
					}


				}
				else
				{
					keepAns = 'Y';
				}

				if (keepAns == 'Y')
				{
					cannedCorn.amount += amountAquired;

					Text::printOut("\tYou have (" + to_string(cannedCorn.amount) + ") total.\n");
				}
				roll = false;
				break;
			case 12:

				prob = 10;

				prob += localRarity(antitoxin, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") antitoxin.\n");

				antitoxin.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(antitoxin.amount) + ") total.\n");

				roll = false;
				break;

			case 13:

				prob = 10;

				prob += localRarity(rabiesShot, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				if (player.rabiesCure)
				{
					break;
				}
				amountAquired = 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") rabies shot.\n");

				rabiesShot.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(rabiesShot.amount) + ") total.\n");

				roll = false;
				break;
			case 14:

				prob = 10;

				prob += localRarity(instantCoffee, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}


				amountAquired = (rand() % 2) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") instant coffee.\n");

				instantCoffee.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(instantCoffee.amount) + ") total.\n");

				roll = false;
				break;
			case 15:

				prob = 10;

				prob += localRarity(cannedBeer, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = (rand() % 4) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") canned beer.\n");

				cannedBeer.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(cannedBeer.amount) + ") total.\n");
				roll = false;
				break;
			case 16:
				prob = 10;

				prob += localRarity(tea, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				amountAquired = (rand() % 2) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") tea.\n");

				tea.amount += amountAquired;

				Text::printOut("\tYou have (" + to_string(tea.amount) + ") total.\n");

				roll = false;
				break;
			default:
				Text::printOut("You are unable to find anything.");
				roll = false;
				break;
			}
		}




		cout << endl << endl;
		system("pause");
	}

	static void forage(Item& shaggyMane, Item& frogLegs, Item& birdEgg, Item& honey, Player& player, Item& deadMouse, Day& day, Item& raspberries, Item& morel, Item& chickenOfWoods, Location* locationPTR)
	{
		int amountAquired, randRisk;
		char keepAns;
		bool roll = true;
		int prob;

		system("CLS");

		while (roll)
		{
			switch ((rand() % 7) + 1)
			{
			case 1:

				if (day.seasonNum == 4)
				{
					break;
				}

				if (day.seasonNum == 2 && (rand() % 2) == 0)
				{
					break;
				}

				prob = 10;

				prob += localRarity(shaggyMane, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("While you are walking you stumble across some (edible) mushrooms.\n");
				amountAquired = (rand() % 6) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") Shaggy Mane.\n");

				randRisk = (rand() % 100) + 1;

				if (randRisk > 75)
				{
					switch (rand() % 2)
					{
					case 0:
						Text::printOut("\n... They might actually be something else similar, it's hard to say. Should you keep them?");
						break;
					case 1:
						Text::printOut("\n\n... You're only mostly sure they're shaggy mane though.\nProbably safe to keep right?");
						break;
					}

					Text::printOut("\nEnter (Y/N): ");
					Text::printOut("\n\n>");

					cin >> keepAns;
					cin.ignore(1000, '\n');

					PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

					while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
					{
						Text::printOut("\nInvalid entry, enter only Y or N.\n");
						Text::printOut(">");
						cin >> keepAns;
						cin.ignore(1000, '\n');
					}

					if (toupper(keepAns) == 'Y')
					{
						shaggyMane.riskFactor += (amountAquired / (++shaggyMane.amount)) * 30;

						shaggyMane.riskFactor = Player::percentRestraint(shaggyMane.riskFactor);

					}
					else
					{
						Text::printOut("\nYou throw them away, seems like a waste, but better to be safe right?");
					}


				}
				else
				{
					keepAns = 'Y';
				}

				if (keepAns == 'Y')
				{
					shaggyMane.amount += amountAquired;

					PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

					Text::printOut("\tYou have (" + to_string(shaggyMane.amount) + ") total.");
				}

				roll = false;

				break;
			case 2:

				prob = 10;

				prob += localRarity(frogLegs, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				if (day.seasonNum == 4)
				{
					break;
				}

				Text::printOut("While you are walking you find some frogs.\n");

				amountAquired = (rand() % 3) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") Frog Legs.\n");


				frogLegs.amount += amountAquired;

				PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);
				Text::printOut("\tYou have (" + to_string(frogLegs.amount) + ") total.");

				roll = false;
				break;
			case 3:

				prob = 10;

				prob += localRarity(birdEgg, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				if (day.seasonNum == 4 || day.seasonNum == 3)
				{
					break;
				}
				Text::printOut("While you are walking you find a bird's nest.\n");
				Text::printOut(" ... you could take the eggs for food, but do you really want to do that?\n");

				Text::printOut("\nEnter (Y/N): ");

				Text::printOut("\n\n>");

				cin >> keepAns;
				cin.ignore(1000, '\n');

				PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

				while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
				{
					Text::printOut("\nInvalid entry, enter only Y or N.\n");
					Text::printOut(">");
					cin >> keepAns;
					cin.ignore(1000, '\n');
				}

				if (toupper(keepAns) == 'Y')
				{
					amountAquired = (rand() % 6) + 1;

					Text::printOut("Found (" + to_string(amountAquired) + ") Eggs.\n");

					birdEgg.amount += amountAquired;

					PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

					Text::printOut("\tYou have (" + to_string(birdEgg.amount) + ") total.");

				}
				else
				{
					Text::printOut("\nYou leave them behind.\n");
				}

				roll = false;
				break;
			case 4:

				prob = 10;

				prob += localRarity(honey, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				if (day.seasonNum == 4)
				{
					break;
				}
				Text::printOut("While you are walking you find a bee hive.\n");
				Text::printOut(" ... you could eat the honey, but how good of an idea is this?\n");

				Text::printOut("\n1. Light a fire and smoke the bees out.\n");
				Text::printOut("2. Just grab a handful of honey and run.\n");
				Text::printOut("3. Leave, you aren't that despirate yet.\n");

				Text::printOut(">");
				cin >> keepAns;
				cin.ignore(1000, '\n');

				PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

				while (cin.fail() || (keepAns != '1' && keepAns != '2' && keepAns != '3'))
				{
					Text::printOut("Invalid entry, enter only 1, 2, or 3.\n");
					Text::printOut(">");
					cin >> keepAns;
					cin.ignore(1000, '\n');
				}

				if (toupper(keepAns) == '1')
				{
					amountAquired = (rand() % 4) + 1;

					Text::printOut("Found (" + to_string(amountAquired) + ") honey.\n");

					honey.amount += amountAquired;

					PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

					Text::printOut("\tYou have (" + to_string(honey.amount) + ") total.");

					switch ((rand() % 2) + 1)
					{
					case 1:
						Text::printOut("\n... you also got stung a bit.\n");
						Text::printOut("\t-10 happiness.\n");

						player.happiness -= 10;
						player.happiness = Player::percentRestraint(player.happiness);


					}

				}
				else if (toupper(keepAns) == '2')
				{
					Text::printOut("... you didn't get any honey.\n");
					Text::printOut("... you also got stung a lot.\n");
					Text::printOut("\t-20 happiness.\n");

					player.happiness -= 20;
					player.happiness = Player::percentRestraint(player.happiness);

					Text::printOut("\nThat was really stupid.\n");
				}
				else
				{
					Text::printOut("\nYou leave it behind.");

				}

				roll = false;
				break;
			case 5:
				prob = 10;

				prob += localRarity(raspberries, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				Text::printOut("While you are walking you find a raspberry bush.\n");

				amountAquired = (rand() % 5) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") ounces of raspberries.\n");

				raspberries.amount += amountAquired;

				PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);
				Text::printOut("\tYou have (" + to_string(raspberries.amount) + ") total.");


				roll = false;
				break;
			case 6:

				prob = 10;

				prob += localRarity(morel, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}

				if (day.seasonNum == 4)
				{
					break;
				}

				if (day.seasonNum == 2 && (rand() % 2) == 0)
				{
					break;
				}

				Text::printOut("While you are walking you stumble across some (edible) mushrooms.\n");
				amountAquired = (rand() % 9) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") morels.\n");

				randRisk = (rand() % 100) + 1;

				if (randRisk > 50)
				{
					switch (rand() % 2)
					{
					case 0:
						Text::printOut("\n... They might actually be something else similar, it's hard to say. Should you keep them?");
						break;
					case 1:
						Text::printOut("\n\n... You're only mostly sure they're shaggy mane though.\nProbably safe to keep right?");
						break;
					}

					Text::printOut("\nEnter (Y/N): ");

					Text::printOut("\n\n>");
					cin >> keepAns;
					cin.ignore(1000, '\n');

					PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

					while (cin.fail() || (toupper(keepAns) != 'Y' && toupper(keepAns) != 'N'))
					{
						Text::printOut("\nInvalid entry, enter only Y or N.\n");
						Text::printOut(">");
						cin >> keepAns;
						cin.ignore(1000, '\n');
					}

					if (toupper(keepAns) == 'Y')
					{
						morel.riskFactor += (amountAquired / (++morel.amount)) * 30;

						morel.riskFactor = Player::percentRestraint(morel.riskFactor);

					}
					else
					{
						Text::printOut("\nYou throw them away, seems like a waste, but better to be safe right?");
					}


				}
				else
				{
					keepAns = 'Y';
				}

				if (keepAns == 'Y')
				{
					morel.amount += amountAquired;

					PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

					Text::printOut("\tYou have (" + to_string(morel.amount) + ") total.");
				}

				roll = false;

				break;

			case 7:

				prob = 10;

				prob += localRarity(chickenOfWoods, locationPTR);

				if (rand() % prob > 0)
				{
					break;
				}


				if (day.seasonNum == 4)
				{
					break;
				}

				if (day.seasonNum == 2 && (rand() % 2) == 0)
				{
					break;
				}

				Text::printOut("While you are walking you find some (edible) fungus.\n");

				amountAquired = (rand() % 4) + 1;

				Text::printOut("Found (" + to_string(amountAquired) + ") ounces of Chicken of the Woods.\n");

				chickenOfWoods.amount += amountAquired;

				PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);
				Text::printOut("\tYou have (" + to_string(chickenOfWoods.amount) + ") total.");

				roll = false;
				break;
			}
		}





		cout << endl;
		system("pause");
	}



};


