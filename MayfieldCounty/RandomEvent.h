//#include "PlayerAction.h"

#pragma once
#include "Location.h"
#include "Item.h"

class randomEvent{
public:

    static int eventRarity(Location* location, string eventCode)
    {
        for (int i = 0; i <= Item::LENGTH; i++)
        {
            
            if (eventCode == location->likelyEvent[i])
            {
                return 0;
            }

            if (eventCode == location->unlikelyEvent[i])
            {
                return 15;
            }

            if (eventCode == location->impossibleEvent[i])
            {
                return 9999;
            }

            if (i == Item::LENGTH)
            {
                return 0; // this is if I missed it, it's considered common
            }

        }
    }


    //randomEvent::doRandomEvent(player, bullet, dogMeat, catMeat, day);
    static void doRandomEvent(Player& player, Location* locationPTR, Item& bullet, Item& dogMeat, Item& catMeat, Day& day)
    {
        int eventChoice = 0;
        bool invalidAnswer = true, roll = true;
        int switcher, amountAquired;
        char picker;
        int prob;

        srand((unsigned int)time(NULL));



        system("CLS");

        while (roll)
        {
            switcher = (rand() % 11) + 1;

            switch (switcher)
            {
            case 1:

                prob = 10;

                prob += eventRarity(locationPTR, "rabidDog");

                if (rand() % prob > 0)
                {
                    break;
                }

                Text::printOut("You encounter a dog who seems to be acting strangely.\n", player.getSanity());
                Text::printOut("He looks sick, he's seen better days.\n", player.getSanity());
                Text::printOut("He foams at the mouth.\n\n", player.getSanity());

                Text::printOut("What will you do?\n\n", player.getSanity());

                Text::printOut("\t1. Approach the dog, he might need help.\n\n", player.getSanity());
                Text::printOut("\t2. Shoot the dog, he could be dangerous.\n\n", player.getSanity());
                Text::printOut("\t3. Best to keep your distance. Just leave.\n\n", player.getSanity());


                while (invalidAnswer)
                {
                    Text::printOut(">");
                    cin >> eventChoice;
                    cin.ignore(1000, '\n');

                    PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        Text::printOut("Invalid entry, enter 1 2 or 3.\n", player.getSanity());
                        Text::printOut(">");
                        cin >> eventChoice;
                        cin.ignore(1000, '\n');
                    }

                    if (eventChoice == 2 && !player.hasHuntingRifle)
                    {
                        Text::printOut("You don't have a gun, enter 1 or 3.\n", player.getSanity());
                    }
                    else if (eventChoice == 2 && bullet.amount < 1)
                    {
                        Text::printOut("You're out of bullets, enter 1 or 3.\n", player.getSanity());
                    }
                    else
                    {
                        invalidAnswer = false;
                    }

                }

                switch (eventChoice)
                {
                case 1:
                    if (rand() % 2)
                    {

                        Text::printOut("The dog growls at you, your instincts tell you to take your hand away.\nYou leave him be.\n", player.getSanity());


                    }
                    else
                    {
                        Text::printOut("The dog attacks you.\nYou recieve some nasty bites but get away.\n", player.getSanity());

                        player.isInjured = true;

                        if (!player.rabiesCure) // you can't get rabies if you have the shot
                        {
                            player.hasRabies = true;
                        }


                        day.updateInfo = true;


                    }

                    PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);
                    roll = false;
                    break;
                case 2:

                    Text::printOut("You shoot the dog.\n You think about what you've become.\n\t-20 sanity.\n\t-10 happiness.\n", player.getSanity());


                    player.sanity -= 20;
                    player.happiness -= 10;

                    player.sanity = Player::percentRestraint(player.sanity);
                    player.happiness = Player::percentRestraint(player.happiness);

                    PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);

                    break;
                case 3:
                    Text::printOut("You leave the area.\n", player.getSanity());
                    break;
                }
                roll = false;
                break;
            case 2:

                prob = 10;

                prob += eventRarity(locationPTR, "findDogFriend");

                if (rand() % prob > 0)
                {
                    break;
                }

                if (player.hasTheDog)
                {
                    break;
                }

                Text::printOut("You encounter a dog, he seems friendly.\n\n", player.getSanity());

                Text::printOut(player.dog + "\n\n");

                Text::printOut("1. You try to befriend the dog, he could be useful.\n2. Move along, he could be dangerous.\n3. Shoot it. You never know when you'll run out of food.\n", player.getSanity());

                while (invalidAnswer)
                {
                    Text::printOut(">");
                    cin >> eventChoice;
                    cin.ignore(1000, '\n');

                    PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                    while (cin.fail() || eventChoice < 1 || eventChoice > 3)
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        Text::printOut("Invalid entry, enter 1 2 or 3.\n", player.getSanity());
                        Text::printOut(">");
                        cin >> eventChoice;
                        cin.ignore(1000, '\n');
                    }

                    if (eventChoice == 3 && !player.hasHuntingRifle)
                    {
                        Text::printOut("You don't have a gun, enter 1 or 2.\n", player.getSanity());
                    }
                    else if (eventChoice == 3 && bullet.amount < 1)
                    {
                        Text::printOut("You're out of bullets, enter 1 or 2.\n", player.getSanity());
                    }
                    else
                    {
                        invalidAnswer = false;
                    }
                }

                switch (eventChoice)
                {
                case 1:

                    Text::printOut("You pet the dog, and he likes you.\nHe follows you home.\n\t+20 happiness\n\t+10 sanity\n", player.getSanity());

                    player.hasTheDog = true;

                    player.happiness += 20;
                    player.sanity += 10;

                    player.happiness = Player::percentRestraint(player.happiness);
                    player.sanity = Player::percentRestraint(player.sanity);

                    invalidAnswer = true;



                    while (invalidAnswer)
                    {
                        Text::printOut("\nWhat would you like to name him?\n", player.getSanity());

                        //cin.clear();
                        //cin.ignore(500, '\n');

                        Text::printOut(">");

                        cin.sync();
                        getline(cin, player.dogName);

                        PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                        //cin.clear();
                       // cin.ignore(500, '\n');

                        Text::printOut("Are you sure? (Y/N)\n", player.getSanity());
                        Text::printOut(">");

                        cin >> picker;
                        cin.ignore(1000, '\n');

                        PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                        switch (toupper(picker))
                        {
                        case 'Y':
                            invalidAnswer = false;
                            break;
                        case 'N':
                            break;
                        default:
                            Text::printOut("Invalid entry, enter Y or N.\n", player.getSanity());
                            break;
                        }

                    }




                    break;
                case 2:
                    Text::printOut("You walk away\n");
                    break;
                case 3:

                    Text::printOut("You shoot the dog.\n You think about what you've become.\n\t-20 sanity.\n\t-10 happiness.\n", player.getSanity());


                    PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);

                    player.sanity -= 20;
                    player.happiness -= 10;

                    player.sanity = Player::percentRestraint(player.sanity);
                    player.happiness = Player::percentRestraint(player.happiness);

                    amountAquired = (rand() % 2) + 1;

                    Text::printOut("Found (" + to_string(amountAquired) + ") dog meat.\n", player.getSanity());

                    dogMeat.amount += amountAquired;

                    Text::printOut("\tYou have (" + to_string(dogMeat.amount) + ") total.\n", player.getSanity());

                    bullet.amount -= amountAquired;
                    break;
                }

                roll = false;
                break;
            case 3:

                prob = 5;

                prob += eventRarity(locationPTR, "meetDelores");

                if (rand() % prob > 0)
                {
                    break;
                }

                Text::printOut("You meet a manikin named Delores.\n", player.getSanity());

                switch (rand() % 3 + 1)
                {
                case 1:
                    Text::printOut("She's looking very fine today.\n", player.getSanity());
                    break;
                case 2:
                    Text::printOut("You gossip about the mannikens accross the street.\n", player.getSanity());
                    break;
                case 3:
                    Text::printOut("She tells you about the time she saw a deer the other day.\n", player.getSanity());
                    break;
                case 4:
                    Text::printOut("She makes a really good joke.\nYou think about it for the rest of the day.\n", player.getSanity());
                    break;
                }

                Text::printOut("\t+20 happiness\n\t+10 sanity\n", player.getSanity());


                player.happiness += 20;
                player.sanity += 10;

                player.happiness = Player::percentRestraint(player.happiness);
                player.sanity = Player::percentRestraint(player.sanity);
                roll = false;
                break;
            case 4:

                prob = 10;

                prob += eventRarity(locationPTR, "findMovie");

                if (rand() % prob > 0)
                {
                    break;
                }

                Text::printOut("You find a movie you used to watch.\n\t+10 happiness\n", player.getSanity());

                player.happiness += 10;
                player.happiness = Player::percentRestraint(player.happiness);
                roll = false;
                break;
            case 5:

                prob = 10;

                prob += eventRarity(locationPTR, "glassCut");

                if (rand() % prob > 0)
                {
                    break;
                }

                Text::printOut("You break some glass to break into an empty mall.\nYou do sloppy job and get a nasty cut on the hand.\nIt looks serious.\n", player.getSanity());

                PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);

                player.isInjured = true;

                day.updateInfo = true;

                roll = false;
                break;
            case 6:

                prob = 10;

                prob += eventRarity(locationPTR, "findCatFriend");

                if (rand() % prob > 0)
                {
                    break;
                }

                if (player.hasTheCat)
                {
                    break;
                }

                Text::printOut("There's a stray cat in your neighborhood.\n", player.getSanity());

                Text::printOut(player.cat + "\n\n");

                Text::printOut("1. Leave out some food for the cat, she might be nice to have around.\n", player.getSanity());
                Text::printOut("2. Ignore it, you've got to take care of yourself first.\n", player.getSanity());
                Text::printOut("3. Shoot it. You never know when you'll run out of food.\n", player.getSanity());

                while (invalidAnswer)
                {
                    Text::printOut(">");
                    cin >> eventChoice;
                    cin.ignore(1000, '\n');

                    PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                    while (cin.fail() || eventChoice < 1 || eventChoice > 3)
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        Text::printOut("Invalid entry, enter 1 2 or 3.\n", player.getSanity());
                        Text::printOut(">");
                        cin >> eventChoice;
                        cin.ignore(1000, '\n');
                    }

                    if (eventChoice == 3 && !player.hasHuntingRifle)
                    {
                        Text::printOut("You don't have a gun, enter 1 or 2.\n", player.getSanity());
                    }
                    else if (eventChoice == 3 && bullet.amount < 1)
                    {
                        Text::printOut("You're out of bullets, enter 1 or 2.\n", player.getSanity());
                    }
                    else
                    {
                        invalidAnswer = false;
                    }
                }

                switch (eventChoice)
                {
                case 1:

                    Text::printOut("You lure the cat with food and give her a good scratch behind the ears.\nNow she likes you.\n", player.getSanity());

                    player.hasTheCat = true;

                    Text::printOut("\t+20 happiness\n\t+10 sanity\n", player.getSanity());

                    player.happiness += 20;
                    player.sanity += 10;

                    player.happiness = Player::percentRestraint(player.happiness);
                    player.sanity = Player::percentRestraint(player.sanity);

                    invalidAnswer = true;



                    while (invalidAnswer)
                    {
                        Text::printOut("\nWhat would you like to name her?\n", player.getSanity());

                        //cin.clear();
                        //cin.ignore(500, '\n');

                        Text::printOut(">");
                        cin.sync();

                        getline(cin, player.catName);

                        PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                        //cin.clear();
                       // cin.ignore(500, '\n');

                        Text::printOut("Are you sure? (Y/N)?\n", player.getSanity());
                        Text::printOut(">");
                        cin >> picker;
                        cin.ignore(1000, '\n');

                        PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                        switch (toupper(picker))
                        {
                        case 'Y':
                            invalidAnswer = false;
                            break;
                        case 'N':
                            break;
                        default:
                            Text::printOut("Invalid entry, enter Y or N.\n", player.getSanity());
                            break;
                        }

                    }




                    break;
                case 2:
                    Text::printOut("You walk away\n", player.getSanity());
                    break;
                case 3:
                    Text::printOut("You shoot the cat.\nYou think about what you've become.\n\t-20 sanity.\n\t-10 happiness.\n", player.getSanity());

                    PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);

                    player.sanity -= 20;
                    player.happiness -= 10;

                    player.sanity = Player::percentRestraint(player.sanity);
                    player.happiness = Player::percentRestraint(player.happiness);

                    amountAquired = (rand() % 2) + 1;

                    Text::printOut("Found (" + to_string(amountAquired) + ") cat meat.\n", player.getSanity());

                    catMeat.amount += amountAquired;

                    Text::printOut("\tYou have (" + to_string(catMeat.amount) + ") total.\n", player.getSanity());

                    bullet.amount -= 1;
                    break;
                }

                roll = false;
                break;
            case 7:

                prob = 10;

                prob += eventRarity(locationPTR, "mallInsanity");

                if (rand() % prob > 0)
                {
                    break;
                }

                Text::printOut("You're alone in a dark empty mall.\nIt's completely quiet.\nYou're reminded of how lonely you are.\n\t-15 Happiness\n\t-15 Sanity\n", player.getSanity());

                PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);

                player.happiness -= 15;
                player.sanity -= 15;

                player.sanity = Player::percentRestraint(player.sanity);
                player.happiness = Player::percentRestraint(player.happiness);
                roll = false;
                break;
            case 8:
                prob = 10;

                prob += eventRarity(locationPTR, "wolfInsanity");

                if (rand() % prob > 0)
                {
                    break;
                }

                if (day.dayNumber < 30)
                {
                    break;
                }

                Text::printOut("You hear a wolf howling in the distance.\n\t-15 Sanity\n", player.getSanity());

                PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);

                player.sanity -= 15;
                player.sanity = Player::percentRestraint(player.sanity);
                roll = false;
                break;
            case 9:
                prob = 10;

                prob += eventRarity(locationPTR, "schoolInsanity");

                if (rand() % prob > 0)
                {
                    break;
                }


                Text::printOut("You find yourself walking through your old highschool.\n", player.getSanity());
                Text::printOut("It's completely quiet, dark and abandoned.\n", player.getSanity());
                Text::printOut("You notice the rotting carcass of a deer in one of the classrooms.\n", player.getSanity());
                Text::printOut("You deside it may be best not to linger here...\n\t-15 Sanity\n", player.getSanity());

                PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);


                player.sanity -= 15;

                player.sanity = Player::percentRestraint(player.sanity);
                roll = false;
                break;
            case 10:

                prob = 10;

                prob += eventRarity(locationPTR, "coyoteAttack");

                if (rand() % prob > 0)
                {
                    break;
                }

                if (day.dayNumber < 30)
                {
                    break;
                }
                Text::printOut("It's around sundown.\n", player.getSanity());
                Text::printOut("You feel a dozen sets of eyes staring at you.\n", player.getSanity());
                Text::printOut("A pack of coyotes has taken an interest.\n", player.getSanity());

                Text::printOut("\n1. Run!\n");
                Text::printOut("2. Scare them off, raise your arms and scream, shoot bullets off in the air\n", player.getSanity());
                Text::printOut("3. Calmly get into the nearest car and stay until they leave.\n", player.getSanity());
                Text::printOut("4. Gun them down.\n\n", player.getSanity());

                Text::printOut("What will you do?\n", player.getSanity());


                invalidAnswer = true;

                PlaySound(TEXT("scary.wav"), NULL, SND_ASYNC);


                while (invalidAnswer)
                {
                    invalidAnswer = false;
                    Text::printOut(">");
                    cin >> eventChoice;
                    cin.ignore(1000, '\n');

                    PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                    if (cin.fail() || eventChoice < 1 || eventChoice > 4)
                    {
                        cin.clear();
                        cin.ignore(500, '\n');

                        Text::printOut("Invalid entry, enter 1 2 or 3.\n");
                        Text::printOut(">");
                        cin >> eventChoice;
                        cin.ignore(1000, '\n');

                        invalidAnswer = true;
                    }
                    else
                    {
                        switch (eventChoice)
                        {
                        case 1:
                            system("CLS");
                            Text::printOut("The coyotes run you down and begin to maul you.\n", player.getSanity());
                            Item::maul("coyote", 6, day, player, bullet);
                            break;
                        case 2:
                            if ((rand() % 10) + 1 <= 7 || (((rand() % 10) + 1 <= 9) && player.hasHuntingRifle))
                            {
                                Text::printOut("After a few terrifying moments, you get them to leave.\n\t-20 sanity\n", player.getSanity());

                                player.sanity -= 20;
                                player.sanity = Player::percentRestraint(player.sanity);
                            }
                            else
                            {
                                system("CLS");
                                Text::printOut("The coyotes begin to maul you.\n", player.getSanity());
                                Item::maul("coyote", 6, day, player, bullet);
                            }

                            break;
                        case 3:
                            Text::printOut("You smash a car window and open it from the inside.\n", player.getSanity());
                            Text::printOut("Once inside they circle you for a while.\n", player.getSanity());
                            Text::printOut("After a few hours you work up the nerve to leave.\n", player.getSanity());

                            Text::printOut("\t-20 sanity\n\t-30 energy\n", player.getSanity());

                            player.sanity -= 20;
                            player.sanity = Player::percentRestraint(player.sanity);

                            player.energy -= 20;
                            player.energy = Player::percentRestraint(player.energy);
                            break;
                        case 4:
                            if (!player.hasHuntingRifle)
                            {
                                Text::printOut("You have no gun.\nPick 1, 2 or 3.\n", player.getSanity());
                                invalidAnswer = true;
                                break;
                            }

                            if (bullet.amount < 1)
                            {
                                Text::printOut("You have no bullets.\nPick 1, 2 or 3.\n", player.getSanity());
                                invalidAnswer = true;
                                break;
                            }

                            Text::printOut("You shoot one, and fire off a couple more shots.\n", player.getSanity());
                            Text::printOut("The coyotes realise they're outmatched and run off.\n", player.getSanity());
                            Text::printOut("You're releaved, but a bit shaken.\n\t-15 sanity\n", player.getSanity());

                            player.sanity -= 20;
                            player.sanity = Player::percentRestraint(player.sanity);
                            break;
                        }
                    }
                }
                roll = false;
                break;
            case 11:

                prob = 10;

                prob += eventRarity(locationPTR, "findFireRuins");

                if (rand() % prob > 0)
                {
                    break;
                }

                if (day.dayNumber > 1)
                {
                    Text::printOut("While searching a neighbourhood, you notice a burned building up ahead.\n", player.getSanity());
                    Text::printOut("Upon further inpection, several buildings have been reduced to cinder.\n", player.getSanity());

                    if (day.dayNumber > 10)
                    {
                        Text::printOut("Undergrowth has begun to overtake the buildings,\n", player.getSanity());
                        Text::printOut("though fire damage can still be seen on the trees.\n", player.getSanity());
                    }
                    else
                    {
                        Text::printOut("The surrounding trees and plants have been burned back,\n", player.getSanity());
                        Text::printOut("leaving ground littered with blackened branches and bushes.\n", player.getSanity());
                    }
                }
                else
                {
                    Text::printOut("While searching a neighbourhood, you notice a burning building up ahead.\n", player.getSanity());
                    Text::printOut("Upon further inpection, several buildings are aflame.\n", player.getSanity());

                    Text::printOut("\nIt's probably a good idea to get out of here.\n", player.getSanity());
                }

                Text::printOut("\nSomeone must have left a stove on.\n\t-10 sanity\n", player.getSanity());

                player.sanity -= 10;

                player.sanity = Player::percentRestraint(player.sanity);
                roll = false;
                break;

            }
        }



        cout << endl;
        system("pause");
    }
};
