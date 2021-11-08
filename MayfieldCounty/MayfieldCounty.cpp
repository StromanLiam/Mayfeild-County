#include <iostream>
#include <string>
//#include "Player.h"
//#include "Day.h"
//#include "Item.h"
#include "PlayerAction.h"
//#include "RandomEvent.h"
//#include "Location.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void doDay(Player& player, Day& day, Location** locationPtr, Location** prevLocationPTR);
void intro();
void sleep(Player& player, Day& day, bool dayOff);
//void randomEvent(Player& player, Item& bullet, Item& dogMeat, Day& day);
void printChangeLog();

Item cannedVegitables = Item::initialiseCannedVegitables(); // renamed to tomatos 
Item waterJug = Item::initialiseWaterJug();
Item venison = Item::initialiseVenison();
Item rabbit = Item::initialiseRabbit();
Item fishHook = Item::initialiseFishHook();
Item bass = Item::initialiseBass();
Item bullet = Item::initialiseBullet();
Item firstAidKit = Item::initialiseFirstAidKit();
Item antibiotics = Item::initialiseAntibiotics();
Item squirrel = Item::initialiseSquirrel();
Item dogMeat = Item::initialiseDogMeat();
Item charcoal = Item::initialiseCharcoal();
Item cannedPinapples = Item::initialiseCannedPinapples();
Item cannedCorn = Item::initialiseCannedCorn();
Item antitoxin = Item::initialiseAntitoxin();
Item shaggyMane = Item::initialiseShaggyMane();
Item mutton = Item::initialiseMutton();
Item frogLegs = Item::initialiseFrogLegs();
Item birdEgg = Item::initialiseBirdEgg();
Item honey = Item::initialiseHoney();
Item sunfish = Item::initialiseSunfish();
Item catMeat = Item::initialiseCatMeat();
Item deadMouse = Item::initialiseDeadMouse();
Item rabiesShot = Item::initialiseRabiesShot();
Item instantCoffee = Item::initialiseInstantCoffee();
Item cannedBeer = Item::initialiseCannedBeer();
Item raspberries = Item::initialiseRaspberry();
Item morel = Item::initialiseMorel();
Item chickenOfWoods = Item::initialiseChickenOfWoods();
Item goose = Item::initialiseGoose();
Item turkey = Item::initialiseTurkey();
Item duck = Item::initialiseDuck();
Item seagullMeat = Item::initialiseSeagullMeat();
Item beef = Item::initialiseBeef();
Item horseMeat = Item::initialiseHorseMeat();
Item tea = Item::initialiseTea();
Item mussel = Item::initialiseMussel();
Item salmon = Item::initialiseSalmon();

Location home = Location::initialiseHome();
Location lensborough = Location::initialiseLensborough();
Location mayfeildCentre = Location::initialiseMayfeildCentre();
Location frontSt = Location::initialiseFrontSt();

bool alive = true;
bool nextDay;
//string dailyInformation = "undefined";

//string cat = "\n    ^ ^     meow?\n  (=0.0=)\n   |\\  | \\  |\n   L \\ L( |/";

//string dog = " [(0 A 0)]   borf?\n   | | | \\   \n   L \\ L( |---";

int main()
{

    srand((unsigned int)time(NULL));

    //cout << "TESTTESTTESTTEST" << endl;

    string jollyRoger = ".=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n|                     ______                     |\n|                  .-`      `-.                  |\n|                 /            \\                 |\n|     _          |              |          _     |\n|    ( \\         |,  .-.  .-.  ,|         / )    |\n|     > `=._     | )(__/  \\__)( |     _.=` <     |\n|    (_/`=._`=._ |/     /\\     \\| _.=`_.=`\\_)    |\n|           `=._`(_     ^^     _)`_.=`           |\n|               `=\\__|IIIIII|__/=`               |\n|              _.=`| \\IIIIII/ |`=._              |\n|    _     _.=`_.=`\\          /`=._`=._     _    |\n|   ( \\_.=`_.=`     `--------`     `=._`=._/ )   |\n|    > _.=`                            `=._ <    |\n|   (_/                                    \\_)   |\n|                                                |\n'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";




    intro();
    // menu() ???



    Player player;
    Day day;

    //day.seasonNum = 4;
   // day.season = "winter";

   // instantCoffee.amount = 100;

   // player.hasTheCat = true;
    //player.catName = "peepee";

    //player.hasHuntingRifle = true;
    //bullet.amount = 10000000;

    //player.hasInfection = true;

   //player.hasFishingRod = true;
   //fishHook.amount = 10000;


    Location* prevLocationPTR = nullptr;
    Location* locationPTR = nullptr;



    while (alive)
    {
        //player.hasInfection = true;

        //rabbit.amount = 1000;

        if (player.hasTheCat)
        {
            system("CLS");

            if (rand() % 5 == 0)
            {
                Text::printOut(".. and " + player.catName + " brought you a dead mouse.\n");


                Text::printOut(player.cat + "\n\n");

                Text::printOut("Found (1) mice.\n");

                deadMouse.amount += 1;

                Text::printOut("\tYou have (" + to_string(deadMouse.amount) + ") total.\n");

                Text::printOut("\n... hopefully it doesn't come to this, but it is better than starving.\n");

                PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

                system("pause");
            }
        }

        int amountAquired;
        day.isSnowing = false; // just in case it never stops snowing before spring

        switch (day.seasonNum)
        {
        case 1: //spring
            if (rand() % 6 == 0)
            {
                system("CLS");

                Text::printOut("It is raining today.\n");

                day.isRaining = true;

                amountAquired = (rand() % 3) + 3;


                Text::printOut("Collected (" + to_string(amountAquired) + ") Jugs of water.\n");

                waterJug.amount += amountAquired;

                Text::printOut("\tYou have (" + to_string(waterJug.amount) + ") total.\n");

                PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

                system("pause");
            }
            else
            {
                day.isRaining = false;
            }
            break;
        case 2: // summer
            if (rand() % 8 == 0)
            {
                system("CLS");

                Text::printOut("It is raining today.\n");

                day.isRaining = true;

                amountAquired = (rand() % 3) + 3;

                Text::printOut("Collected (" + to_string(amountAquired) + ") Jugs of water.\n");

                waterJug.amount += amountAquired;

                Text::printOut("\tYou have (" + to_string(waterJug.amount) + ") total.\n");

                PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

                system("pause");
            }
            else
            {
                day.isRaining = false;
            }
            break;
        case 3: // fall
            if (rand() % 8 == 0)
            {
                system("CLS");

                Text::printOut("It is raining today.\n");

                day.isRaining = true;

                amountAquired = (rand() % 3) + 3;

                Text::printOut("Collected (" + to_string(amountAquired) + ") Jugs of water.\n");

                waterJug.amount += amountAquired;

                Text::printOut("\tYou have (" + to_string(waterJug.amount) + ") total.\n");

                PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

                system("pause");
            }
            else
            {
                day.isRaining = false;
            }
            break;
        case 4: // winter

            if (rand() % 5 == 0)
            {
                day.isSnowing = true;
            }
            else
            {
                day.isSnowing = false;
            }

            if (rand() % 2 == 0)
            {
                system("CLS");

                amountAquired = 3;
                Text::printOut("There is snow on the ground.\n");
                Text::printOut("You fill " + to_string(amountAquired) + " jugs with snow and bring them inside to melt.\n");

                Text::printOut("Collected (" + to_string(amountAquired) + ") Jugs of water.\n");

                waterJug.amount += amountAquired;

                Text::printOut("\tYou have (" + to_string(waterJug.amount) + ") total.\n");

                PlaySound(TEXT("itemize.wav"), NULL, SND_ASYNC);

                system("pause");
            }

            break;

        }

        if (!day.isRaining && day.seasonNum == 2)
        {
            if (rand() % 4 == 0)
            {
                day.isBuggy = true;
            }
            else
            {
                day.isBuggy = false;
            }
        }
        else
        {
            day.isBuggy = false;
        }

        if (!day.isRaining && day.seasonNum == 2)
        {
            if (rand() % 3 == 0)
            {
                day.isHot = true;
            }
            else
            {
                day.isHot = false;
            }
        }
        else
        {
            day.isHot = false;
        }

        if (day.seasonNum == 4)
        {
            if (rand() % 3 == 0)
            {
                day.isCold = true;
            }
            else
            {
                day.isCold = false;
            }
        }
        else
        {
            day.isCold = false;
        }




        player.drunkCounter = 0;

        

        if (locationPTR != nullptr)
        {
            prevLocationPTR = locationPTR;
        }
        
        locationPTR = &home;

        doDay(player, day, &locationPTR, &prevLocationPTR);

        //player.hasHangover = false;

        day.updateInfo = true;

        if (player.botulismDeath && player.hasBotulism)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have died of botulism.\n\n");
        }

        if (player.infectionDeath && player.hasInfection)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have died of an infection.\n\n");
        }

        if (player.rabiesDeath)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have died of rabies.\n\n");
        }

        if (player.poisonDeath && player.isPoisoned)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have died of poisoning.\n\n");
        }

        if (player.maulDeath)
        {
            alive = false;
            system("CLS");

            Text::printOut("You have been mauled to death by an animal.\n\n");
        }

        if (player.fat < 1 && player.hunger < 1)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have died of rabbit starvation.\n\n");
        }

        if (player.hunger < 1 && alive == true)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have starved to death.\n\n");
        }

        if (player.thirst < 1)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have died of thirst.\n\n");
        }

        if (player.vitamins < 1)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have died of scurvy.\n\n");
        }

        if (player.warmth < 1)
        {
            alive = false;

            system("CLS");
            Text::printOut("You have frozen to death.\n\n");
        }



    }

    Text::printOut("You lasted " + to_string(--day.totalDays) + " days.\n\n");

    Text::printOut(jollyRoger + "\n\n");

    PlaySound(TEXT("death-song.wav"), NULL, SND_ASYNC);

    system("pause");

}

void playerInjury(Player& player, Day& day)
{
    switch ((rand() % 4) + 1)
    {
    case 1:
        day.dailyInformation += "Your wound has become infected.\n";
        player.hasInfection = true;
        break;
    default:
        day.dailyInformation += "You have an untreated wound.\n";
        // player.energy -= 30;
        player.happiness -= 30;
        player.sanity -= 5;
        break;
    }

    player.energy = Player::percentRestraint(player.energy);
    player.happiness = Player::percentRestraint(player.happiness);
    player.sanity = Player::percentRestraint(player.sanity);
}

void playerRabies(Player& player, Day& day)
{
    switch ((rand() % 10) + 1)
    {
    case 1:
        day.dailyInformation += "You are having seizures.\nYou feel hyper.\nYou hate water.\n";
        player.rabiesDeath = true;
        player.energy -= 40;
        player.sanity -= 40;
        break;
    default:
        break;
    }

    player.energy = Player::percentRestraint(player.energy);
    player.sanity = Player::percentRestraint(player.sanity);
}

void playerInfection(Player& player, Day& day)
{
    switch ((rand() % 6) + 1)
    {
    case 1:
        day.dailyInformation += "You have an infection.\nYou're having trouble breathing.\nYou feel yourself fading away.\n";
        player.happiness -= 20;
        player.sanity -= 5;
        player.energy -= 20;

        player.energy = Player::percentRestraint(player.energy);
        player.happiness = Player::percentRestraint(player.happiness);
        player.sanity = Player::percentRestraint(player.sanity);

        player.infectionDeath = true;
        break;

    default:
        day.dailyInformation += "You have an infection.\nYou are in a lot of pain.\n";
        player.energy -= 20;
        player.happiness -= 20;
        player.sanity -= 5;

        player.energy = Player::percentRestraint(player.energy);
        player.happiness = Player::percentRestraint(player.happiness);
        player.sanity = Player::percentRestraint(player.sanity);

        break;

    }
}


void playerBotulism(Player& player, Day& day)
{
    switch ((rand() % 4) + 1)
    {
    case 1:

        day.dailyInformation += "You are very ill.\n";

        player.energy -= 40;
        player.happiness -= 20;
        player.sanity -= 5;

        player.energy = Player::percentRestraint(player.energy);
        player.happiness = Player::percentRestraint(player.happiness);
        player.sanity = Player::percentRestraint(player.sanity);

        break;
    case 2:
        day.dailyInformation += "You're feeling much better today.\n";
        player.hasBotulism = false;

        break;
    case 3:
        day.dailyInformation += "You are very ill.\nYour vision is blurred.\n";

        player.energy -= 50;
        player.happiness -= 20;
        player.sanity -= 5;

        player.energy = Player::percentRestraint(player.energy);
        player.happiness = Player::percentRestraint(player.happiness);
        player.sanity = Player::percentRestraint(player.sanity);

        break;

    case 4:

        day.dailyInformation += "You are very ill.\nYour vision is blurred.\nYou are paralysed\n";

        player.botulismDeath = true;

        player.energy -= 100;
        player.happiness -= 20;
        player.sanity -= 10;

        player.energy = Player::percentRestraint(player.energy);
        player.happiness = Player::percentRestraint(player.happiness);
        player.sanity = Player::percentRestraint(player.sanity);

        break;
    }

    cout << endl;
}

void doRain(Player& player, Day& day)
{
    day.dailyInformation += "It's raining today.\n";
    player.energy -= 10;
}

void doBugs(Player& player, Day& day)
{
    day.dailyInformation += "It's really buggy out.\n\t-10 happiness\n";
    player.happiness -= 10;
}

void doSnow(Player& player, Day& day)
{
    day.dailyInformation += "It's snowing today.\n";
    // player.energy -= 10;
}

void doHeat(Player& player, Day& day)
{
    day.dailyInformation += "It's brutally hot today.\n";
    player.energy -= 15;
}

void doCold(Player& player, Day& day)
{
    day.dailyInformation += "It's bitterly cold today.\n";
}

void playerHangover(Player& player, Day& day)
{
    day.dailyInformation += "You're a bit hungover today\n";
    day.dailyInformation += "\t-15 energy\n";
    day.dailyInformation += "\t-15 happiness\n";

    player.energy -= 15;
    player.happiness -= 15;

    player.energy = Player::percentRestraint(player.energy);
    player.happiness = Player::percentRestraint(player.happiness);

    player.hasHangover = false;
}



void playerPoison(Player& player, Day& day)
{
    switch ((rand() % 10) + 1)
    {
    case 1:
    case 2:
        day.dailyInformation += "You are sweating.\nYour eyes are watering.\n";
        break;
    case 3:
    case 4:
    case 5:
        day.dailyInformation += "You are very sick.\n";
        player.energy -= 15;
        player.energy = Player::percentRestraint(player.energy);
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        day.dailyInformation += "You are sweating.\nYour eyes are watering.\n";
        day.dailyInformation += "You are very sick.\n";
        player.energy -= 35;
        player.energy = Player::percentRestraint(player.energy);
        break;
    case 10:
        day.dailyInformation += "You are very sick.\n";
        day.dailyInformation += "You are having trouble breathing.\n";

        player.poisonDeath = true;

        player.energy -= 50;
        player.energy = Player::percentRestraint(player.energy);
        break;
    }
}

void doDay(Player& player, Day& day, Location** locationPTR, Location** prevLocationPTR)
{
    int choice;
    bool sameDay = true;
    char sleepConfirm;

    bool dayOffValid = true;



    day.dailyInformation = "";

    /*
    if (player.drunkCounter > 0)
    {
        playerDrunk(player);
    }
    */

    while (sameDay)
    {

        system("CLS");



        if (day.updateInfo)
        {
            day.dailyInformation = "";
            day.drunkInformation = "";

            if (day.seasonNum == 4 && day.dayNumber == 1)
            {
                day.dailyInformation += "NOTICE: now that it's winter, keep on eye on your 'warmth' stat!\n";
            }

            if (day.isRaining)
            {
                doRain(player, day);
            }

            if (day.isSnowing)
            {
                doSnow(player, day);
            }

            if (day.isBuggy)
            {
                doBugs(player, day);
            }

            if (day.isHot)
            {
                doHeat(player, day);
            }

            if (day.isCold)
            {
                doCold(player, day);
            }

            if (player.hasHangover)
            {
                playerHangover(player, day);
            }

            if (player.hasBotulism)
            {
                playerBotulism(player, day);
            }

            if (player.hasRabies)
            {
                playerRabies(player, day);
            }

            if (player.isPoisoned)
            {
                playerPoison(player, day);
            }

            if (player.isInjured)
            {
                playerInjury(player, day);
            }

            if (player.hasInfection)
            {
                playerInfection(player, day);
            }



            if (player.vitamins < 30)
            {
                player.rabbitCounter += 20;

                switch ((rand() % 3) + 1)
                {
                case 1:

                    day.dailyInformation += "You feel very weak today.\n";
                    player.energy -= 40;
                    break;
                case 2:
                    day.dailyInformation += "Your teeth are yellowed and decaying.\nYour gums are bleeding.\n";
                    player.energy -= 20;
                    break;
                case 3:
                    day.dailyInformation += "Your joints are aching.\nYou feel irritable.\n";
                    player.energy -= 20;
                    break;

                }

                player.energy = Player::percentRestraint(player.energy);
            }

            if (player.fat < 20)
            {
                player.rabbitCounter += 10;

                switch ((rand() % 3) + 1)
                {
                case 1:
                    day.dailyInformation += "You feel very weak today.\n";
                    player.energy -= 40;
                    break;
                case 2:
                    day.dailyInformation += "You have a headache.\n";
                    break;
                case 3:
                    day.dailyInformation += "You have nausea.\nYou feel weak.\n";
                    player.energy -= 20;
                    break;
                }

                //cout << endl;

            }

            day.updateInfo = false;

            player.energy = Player::percentRestraint(player.energy);

        }

        Text::printOut(day.season + " " + to_string(day.dayNumber) + " year " + to_string(day.year) + ", day " + to_string(day.totalDays) + "\n");

        if (day.seasonNum == 4)
        {
            Text::printOut("Energy " + to_string(player.energy) + "% Hunger " + to_string(player.hunger) + "% Thirst " + to_string(player.thirst) + "% Happiness " + to_string(player.happiness) + "% Sanity " + to_string(player.sanity) + "% Warmth " + to_string(player.warmth) + "%\n");
        }
        else
        {
            Text::printOut("Energy " + to_string(player.energy) + "% Hunger " + to_string(player.hunger) + "% Thirst " + to_string(player.thirst) + "% Happiness " + to_string(player.happiness) + "% Sanity " + to_string(player.sanity) + "%" + "\n");
        }




        Text::printOut("Current Location: " + (*locationPTR)->locationName + ".\n\n");



        if (day.drunkInformation != "")
            Text::printOut(day.drunkInformation + "\n\n");

        if (day.dailyInformation != "")
            Text::printOut(day.dailyInformation + "\n\n");


        /*
       * Drunk information has to be its own string because it can update during the span of the day.
       * This is awkward, and I wish that there was a better way to show these messages, but for now it works.
       * The result of this is that your drunkenness can change throughout the day, but other contitions are daily.
       * Hence daily information.
       *
       * Putting the information strings in day makes it so that they can be accessed anywhere, but it would have been smarter to put it in player if only for ease of implimentation.
       * In the case that accessing the strings in day becomes a problem because they're being used in another class, they may have to be moved to player. Or something.
       */

        Text::printOut("What will you do today?\n\n");

        if (day.seasonNum == 4 && day.isCold)
        {
            Text::printOut("1. Search for supplies\n\t-20 energy\n\t-30 warmth\n\n");
            Text::printOut("2. Hunt\n\t-30 energy\n\t-30 warmth\n\n");
            Text::printOut("3. Go fishing\n\t-20 energy\n\t-30 warmth\n\n");
            Text::printOut("4. Check supplies\n\n");
        }
        else if (day.seasonNum == 4)
        {
            Text::printOut("1. Search for supplies\n\t-20 energy\n\t-25 warmth\n\n");
            Text::printOut("2. Hunt\n\t-30 energy\n\t-25 warmth\n\n");
            Text::printOut("3. Go fishing\n\t-20 energy\n\t-25 warmth\n\n");
            Text::printOut("4. Check supplies\n\n");
        }
        else
        {
            Text::printOut("1. Search for supplies\n\t-20 energy\n\n");
            Text::printOut("2. Hunt\n\t-30 energy\n\n");
            Text::printOut("3. Go fishing\n\t-20 energy\n\n");
            Text::printOut("4. Check supplies\n\n");
        }



        if (dayOffValid && day.dayNumber > 1)
        {
            Text::printOut("5. Take a day off\n\t+25 sanity\n\n");
        }
        else
        {
            Text::printOut("5. Rest for the night\n\n");
        }

        Text::printOut("6. Change location\n\n");
        Text::printOut("7. (Info) What's new?\n\n");


        int noChoices = 7;

        Text::printOut("\nEnter number for choice.\n");
        Text::printOut(">");
        cin >> choice;
        cin.ignore(1000, '\n');

        PlaySound(TEXT("menu-navigate-00.wav"), NULL, SND_ASYNC);

        /*
        while (cin.fail() || choice > noChoices || choice < 1)
        {
            cin.clear();
            cin.ignore(500, '\n');
            Text::printOut("Invalid entry, enter only digits 1-" + to_string(noChoices) + "\n");
            Text::printOut(">");
            cin >> choice;
            cin.ignore(1000, '\n');
        }
        */


        system("CLS");

        switch (choice)
        {
        case 1:

            if ((*locationPTR)->locationName == "Home")
            {
                //system("CLS");
                Text::printOut("You havn't picked somewhere to loot.\nSelect a location to continue.\n\n");

                if (*prevLocationPTR != nullptr)
                {
                    char ans;
                    //system("pause");
                    Text::printOut("Would you like to continue from where you left off yesterday (" + (*prevLocationPTR)->locationName + ")?\nEnter Y/N >");
                    cin >> ans;
                    PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);
                    while (cin.fail() || (toupper(ans) != 'Y' && toupper(ans) != 'N'))
                    {
                        Text::printOut("Invalid entry, enter only Y or N.");
                        cin >> ans;
                        PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);
                    }

                    cin.ignore(1000, '\n');

                    if (toupper(ans) == 'N')
                    {
                        //system("pause");

                        *locationPTR = Location::selectLocation(*locationPTR, lensborough, mayfeildCentre, frontSt);

                        (*locationPTR)->locationInfo(day);
                    }
                    else if (toupper(ans) == 'Y')
                    {
                        *locationPTR = *prevLocationPTR;
                    }
                }
                else
                {
                    system("pause");

                    *locationPTR = Location::selectLocation(*locationPTR, lensborough, mayfeildCentre, frontSt);

                    (*locationPTR)->locationInfo(day);
                }

                system("pause");

            }

            if (player.energy < 20)
            {
                Text::printOut("You're too exhausted to loot right now.\n\n");
                system("pause");
                break;
            }

            PlayerAction::loot(cannedVegitables, day, *locationPTR, waterJug, player, fishHook, bullet, firstAidKit, antibiotics, charcoal, cannedPinapples, cannedCorn, antitoxin, rabiesShot, instantCoffee, cannedBeer, tea);

            dayOffValid = false;

            player.energy -= 20;

            player.energy = Player::percentRestraint(player.energy);

            if (day.seasonNum == 4 && day.isCold)
            {
                player.warmth -= 30;
                player.warmth = Player::percentRestraint(player.warmth);
            }
            else if (day.seasonNum == 4)
            {
                player.warmth -= 25;
                player.warmth = Player::percentRestraint(player.warmth);
            }



            if ((rand() % 8) + 1 == 1) // it was 8
            {
                PlayerAction::forage(shaggyMane, frogLegs, birdEgg, honey, player, deadMouse, day, raspberries, morel, chickenOfWoods, *locationPTR);
            }


            if ((rand() % 8) + 1 == 1) //was 8
            {
                randomEvent::doRandomEvent(player, *locationPTR, bullet, dogMeat, catMeat, day);
            }


            break;
        case 2:

            if ((*locationPTR)->locationName == "Home")
            {
                system("CLS");
                Text::printOut("You havn't picked somewhere to hunt.\nSelect a location to continue.\n\n");

                if (*prevLocationPTR != nullptr)
                {
                    char ans;
                    //system("pause");
                    Text::printOut("Would you like to continue from where you left off yesterday (" + (*prevLocationPTR)->locationName + ")?\nEnter Y/N >");
                    cin >> ans;
                    PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);
                    while (cin.fail() || (toupper(ans) != 'Y' && toupper(ans) != 'N'))
                    {
                        Text::printOut("Invalid entry, enter only Y or N.");
                        cin >> ans;
                        PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);
                    }

                    cin.ignore(1000, '\n');

                    if (toupper(ans) == 'N')
                    {
                        //system("pause");

                        *locationPTR = Location::selectLocation(*locationPTR, lensborough, mayfeildCentre, frontSt);

                        (*locationPTR)->locationInfo(day);
                    }
                    else if (toupper(ans) == 'Y')
                    {
                        locationPTR = prevLocationPTR;
                    }
                }
                else
                {
                    //system("pause");

                    *locationPTR = Location::selectLocation(*locationPTR, lensborough, mayfeildCentre, frontSt);

                    (*locationPTR)->locationInfo(day);
                }

                system("pause");

            }

            if (player.energy < 30)
            {
                Text::printOut("You're too exhausted to hunt right now.\n\n");
                system("pause");
                break;
            }

            if (!player.hasHuntingRifle)
            {
                Text::printOut("You don't have a hunting rifle.\n\n");
                system("pause");
                break;
            }

            if (bullet.amount < 1)
            {
                Text::printOut("You're all out of bullets.\n\n");
                system("pause");
                break;
            }



            PlayerAction::hunt(player, day, *locationPTR, venison, rabbit, bullet, squirrel, dogMeat, mutton, catMeat, goose, turkey, duck, seagullMeat, beef, horseMeat);

            if (day.seasonNum == 4 && day.isCold)
            {
                player.warmth -= 30;
                player.warmth = Player::percentRestraint(player.warmth);
            }
            else if (day.seasonNum == 4)
            {
                player.warmth -= 25;
                player.warmth = Player::percentRestraint(player.warmth);
            }

            player.energy -= 30;
            player.energy = Player::percentRestraint(player.energy);

            dayOffValid = false;

            if ((rand() % 8) + 1 == 1) // it was 8
            {
                PlayerAction::forage(shaggyMane, frogLegs, birdEgg, honey, player, deadMouse, day, raspberries, morel, chickenOfWoods, *locationPTR);
            }

            if ((rand() % 5) + 1 == 1) // was 5
            {
                randomEvent::doRandomEvent(player, *locationPTR, bullet, dogMeat, catMeat, day);
            }

            break;
        case 3:

            if ((*locationPTR)->locationName == "Home")
            {
                system("CLS");
                Text::printOut("You havn't picked somewhere to fish.\nSelect a location to continue.\n\n");

                if (*prevLocationPTR != nullptr)
                {
                    char ans;
                    Text::printOut("Would you like to continue from where you left off yesterday (" + (*prevLocationPTR)->locationName +")?\nEnter Y/N >");
                    cin >> ans;
                    PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);
                    while (cin.fail() || (toupper(ans) != 'Y' && toupper(ans) != 'N'))
                    {
                        Text::printOut("Invalid entry, enter only Y or N.");
                        cin >> ans;
                        PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);
                    }

                    cin.ignore(1000, '\n');

                    if (toupper(ans) == 'N')
                    {
                        

                        *locationPTR = Location::selectLocation(*locationPTR, lensborough, mayfeildCentre, frontSt);

                        (*locationPTR)->locationInfo(day);
                    }
                    else if (toupper(ans) == 'Y')
                    {
                        locationPTR = prevLocationPTR;
                    }
                }
                else
                {
                    

                    *locationPTR = Location::selectLocation(*locationPTR, lensborough, mayfeildCentre, frontSt);

                    (*locationPTR)->locationInfo(day);
                }

                system("CLS");
            }

            if (player.energy < 20)
            {
                Text::printOut("You're too exhausted to fish right now.\n\n");
                system("pause");
                break;
            }

            if (!player.hasFishingRod)
            {
                Text::printOut("You don't have a fishing rod.\n\n");
                system("pause");
                break;
            }

            if (fishHook.amount < 1)
            {
                Text::printOut("You're all out of hooks.\n\n");
                system("pause");
                break;
            }



            PlayerAction::goFish(player, day, *locationPTR, bass, sunfish, mussel, salmon);

            player.energy -= 20;

            player.energy = Player::percentRestraint(player.energy);

            if (day.seasonNum == 4 && day.isCold)
            {
                player.warmth -= 30;
                player.warmth = Player::percentRestraint(player.warmth);
            }
            else if (day.seasonNum == 4)
            {
                player.warmth -= 25;
                player.warmth = Player::percentRestraint(player.warmth);
            }

            dayOffValid = false;

            fishHook.amount--;

            if ((rand() % 8) + 1 == 1) //it was 8
            {
                PlayerAction::forage(shaggyMane, frogLegs, birdEgg, honey, player, deadMouse, day, raspberries, morel, chickenOfWoods, *locationPTR);
            }

            if ((rand() % 6) + 1 == 1) // was 6
            {
                randomEvent::doRandomEvent(player, *locationPTR, bullet, dogMeat, catMeat, day);
            }

            break;
        case 4:
            Item::supplyCheck(cannedVegitables, player, waterJug, venison, rabbit, fishHook, bass, bullet, firstAidKit, antibiotics, squirrel, dogMeat, day, charcoal, cannedPinapples, cannedCorn, antitoxin, shaggyMane, mutton, frogLegs, birdEgg, honey, sunfish, catMeat, deadMouse, rabiesShot, instantCoffee, cannedBeer, raspberries, morel, chickenOfWoods, goose, turkey, duck, seagullMeat, beef, horseMeat, tea, mussel, salmon);
            break;
        case 5:
            if (player.hunger < 50 || player.thirst < 50)
            {
                system("CLS");

                Text::printOut("You are very hungry / thirsty, are you sure you shouldn't eat today?\nTo eat, go to 'check supplies' in the previous menu.\n\n");

                Text::printOut("Hunger " + to_string(player.hunger) + " % Thirst " + to_string(player.thirst) + " % \n\n");

                Text::printOut("(You lose 30 thirst per rest and lose 10 hunger per rest.)\n\n");

                Text::printOut("Enter 'S' to sleep, 'E' to check your supplies, or anything else to go back.\n\n");

                Text::printOut(">");
                cin >> sleepConfirm;
                cin.ignore(1000, '\n');

                PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

                if (toupper(sleepConfirm) == 'S')
                {
                    if (dayOffValid && day.dayNumber > 1)
                    {
                        sleep(player, day, true);
                    }
                    else
                    {
                        sleep(player, day, false);
                    }

                    sameDay = false;
                }
                else if (toupper(sleepConfirm) == 'E')
                {
                    Item::supplyCheck(cannedVegitables, player, waterJug, venison, rabbit, fishHook, bass, bullet, firstAidKit, antibiotics, squirrel, dogMeat, day, charcoal, cannedPinapples, cannedCorn, antitoxin, shaggyMane, mutton, frogLegs, birdEgg, honey, sunfish, catMeat, deadMouse, rabiesShot, instantCoffee, cannedBeer, raspberries, morel, chickenOfWoods, goose, turkey, duck, seagullMeat, beef, horseMeat, tea, mussel, salmon);

                    if (dayOffValid && day.dayNumber > 1)
                    {
                        sleep(player, day, true);
                    }
                    else
                    {
                        sleep(player, day, false);
                    }

                    sameDay = false;


                }

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(500, '\n');
                }
            }
            else
            {
                if (dayOffValid && day.dayNumber > 1)
                {
                    sleep(player, day, true);
                }
                else
                {
                    sleep(player, day, false);
                }

                sameDay = false;
            }

            break;
        case 6:
            *locationPTR = Location::selectLocation(*locationPTR, lensborough, mayfeildCentre, frontSt);

            (*locationPTR)->locationInfo(day);

            break;
        case 7:
            printChangeLog();
            break;

        default:

            cin.clear();
            cin.ignore(500, '\n');
            Text::printOut("Invalid entry, enter only digits 1-" + to_string(noChoices) + "\n\n");

            system("pause");


            break;
        }

        if (player.maulDeath)
        {
            sameDay = false;
        }

        if (player.warmth < 1)
        {
            sameDay = false;
        }


    }


    day.nextDay();

    system("pause");


}

void intro()
{
    Text::printOut("At the stroke of midnight, the entire human race disappears.\n\n");
    Text::printOut("Billions of piles of clothing fall to the ground.\n\n");
    Text::printOut("Millions of vehicles crash.\n\n");
    Text::printOut("An eerie silence encompases the earth.\n\n");
    Text::printOut("You, are still here, and you are all alone.\n\n");
    Text::printOut("This is the story of how you will survive in the wastes of a world without mankind.\n\n");



    /*
    cout << "At the stroke of midnight, the entire human race disappears." << endl << endl;
    cout << "Billions of piles of clothing fall to the ground." << endl << endl;
    cout << "Millions of vehicles crash." << endl << endl;
    cout << "An eerie silence encompases the earth." << endl << endl;
    cout << "You, are still here, and you are all alone." << endl << endl;
    cout << "This is the story of how you will survive in the wastes of a world without mankind." << endl << endl;
    */
    system("pause");

}

void sleep(Player& player, Day& day, bool dayOff)
{
    int whichOne;

    system("CLS");

    if (player.hunger < 60 || player.thirst < 60)
    {
        player.happiness -= 5;
    }
    else if (player.hunger < 30 || player.thirst < 30)
    {
        player.happiness -= 10;
    }
    else if (player.hunger > 90 && player.thirst > 90)
    {
        player.happiness += 15;
    }

    if (dayOff)
    {
        Text::printOut("You take a day off from looting and hunting.\n\t+25 sanity\n\n");
        player.sanity += 25;
        player.sanity = Player::percentRestraint(player.sanity);

        whichOne = (rand() % 2) + 1;

        if (player.hasTheDog && !player.hasTheCat || ((player.hasTheDog && player.hasTheCat) && whichOne == 1))
        {
            Text::printOut("... and you spend some good time with " + player.dogName + ".\n\n" + player.dog + "\n+15 happiness\n");

            player.happiness += 15;
            player.happiness = Player::percentRestraint(player.happiness);
        }

        if (!player.hasTheDog && player.hasTheCat || ((player.hasTheDog && player.hasTheCat) && whichOne == 2))
        {
            Text::printOut("... and you spend some good time with " + player.catName + ".\n\n" + player.cat + "\n+15 happiness\n");

            player.happiness += 15;
            player.happiness = Player::percentRestraint(player.happiness);
        }
    }



    player.happiness = Player::percentRestraint(player.happiness);

    player.hunger -= 10;
    player.hunger = Player::percentRestraint(player.hunger);

    player.thirst -= 30;
    player.thirst = Player::percentRestraint(player.thirst);

    player.vitamins -= 5;
    player.thirst = Player::percentRestraint(player.thirst);

    player.fat -= 5;
    player.fat = Player::percentRestraint(player.fat);

    player.warmth = 100;
    player.warmth = Player::percentRestraint(player.warmth);

    if (player.sanity > 50 && player.happiness > 50)
    {
        Text::printOut("You sleep and are well rested.\n\n");

        player.energy += 80;
        player.energy = Player::percentRestraint(player.energy);

    }
    else if (player.sanity < 10 || player.happiness < 10)
    {
        Text::printOut("You barely get any sleep.\n\n");
        player.energy += 20;
        player.energy = Player::percentRestraint(player.energy);

    }
    else
    {
        Text::printOut("You toss and turn, but eventually get to sleep.\n\n");

        player.energy += 60;
        player.energy = Player::percentRestraint(player.energy);

    }
}

void printChangeLog()
{
    system("CLS");

    Text::printOut("CHANGELOG\n\nUpdate 8/27/2021\n\t-Made it so that all the text reads out letter by letter.\n\t-Made it so that in the supply check inventory you can enter whole words instead of just numbers.\n\t-Added the word 'edible' to the fungi so that people were less confused about how getting poisoned works.\n\t-Revampt rabbit starvation so that it takes away from max hunger and \n\t\tgives you hints while eating when you have it.\n\t-Made it so that items are more dependant on time, i.e. deer start rare and get more common \n\t\twhile canned food does the opposite.\n\n");

    Text::printOut("Update 9/1/2021\n\t-Added Locations mechanic\n\t-Added Lensborough\n\t-The rarity of items is now based on location\n\t-PlayerAction.h now exists so location and items can interact without the compiler screaming\n\t-Added Mayfeild Centre\n\n");

    Text::printOut("Update 9/3/2021\n\t-Added the ability to freeze to death\n\t-Added warmth mechanic\n\t-Added tea\n\t-Made food scarcer in the winter\n\t-Made it so that certain items warm the player\n\n");

    Text::printOut("Update 9 / 17 / 2021\n\t-Added hot, cold and bugs weather (yes bugs is a kind of weather)\n\t-Added winter location descriptions\n\t-fixed a bug in supplycheck.\n\n");

    Text::printOut("Update 10 / 23 / 2021\n\t-I got the thang ding to work again\n\t-The game is now called 'Mayfield County' instead of 'postanthropocene simulator'\n\n");

    Text::printOut("Update 10 / 24 / 2021 \n\t-Random Events are now dependant on the location in which they take place \n\t-Acquiring the hunting rifle and fishing rod is also dependant on location and considered to be 'random events'\n\n");

    Text::printOut("Update 10 / 28 / 2021 \n\t-Added option to continue from where you left off yesterday instead of having to pick location over and over. \n\n");

    system("pause");
}




