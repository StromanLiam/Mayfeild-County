#pragma once
#include <iostream>
#include "Text.h"

//#include "item.h"

using namespace std;

class Player
{
public:
    int hunger;
    int vitamins;
    int fat;
    int thirst;
    int energy;
    int sanity;
    int warmth;

    bool hasHangover;
    //bool isDrunk;
    int drunkCounter;

    int rabbitCounter;

    bool hasBotulism;
    bool hasRabies;
    bool rabiesCure;
    bool isInjured;
    bool isPoisoned;
    bool hasParacite;
    bool hasInfection;
    int happiness;
    bool hasFishingRod;
    bool hasHuntingRifle;
    bool hasTheDog;
    string dogName;
    bool hasTheCat;
    string catName;

    bool botulismDeath;
    bool rabiesDeath;
    bool poisonDeath;
    bool infectionDeath;
    bool maulDeath;
    bool freezeDeath;

    string dog; // stores the dog ascii art.
    string cat; // " " cat ascii art.

    Player()
    {
        hunger = 100;
        vitamins = 100;
        fat = 100;
        thirst = 100;
        energy = 100;
        happiness = 100;
        sanity = 100;
        warmth = 100;

        hasHangover = false;
        //isDrunk = false;
        drunkCounter = 0;
        rabbitCounter = 0;

        hasBotulism = false;
        hasRabies = false;
        isInjured = false;
        isPoisoned = false;
        hasParacite = false;
        hasInfection = false;
        rabiesCure = false;


        botulismDeath = false;
        rabiesDeath = false;
        poisonDeath = false;
        infectionDeath = false;
        maulDeath = false;
        freezeDeath = false;


        hasFishingRod = false;
        hasHuntingRifle = false;
        hasTheDog = false;
        hasTheCat = false;

        dog = " [(0 A 0)]   borf?\n   | | | \\   \n   L \\ L( |---";

        cat = "\n    ^ ^     meow?\n  (=0.0=)\n   |\\  | \\  |\n   L \\ L( |/";

    }



public:
    static int percentRestraint(int value)
    {
        if (value > 100)
        {
            value = 100;
        }

        if (value < 0)
        {
            value = 0;
        }

        return value;
    }



};

