//#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Player.h"
#include "Day.h"
//#include "Item.h"

using namespace std;

//class Item;

class Location
{
public:
	//Item* getItem();

	static const int LENGTH = 36;

	string locationName = "ERR";
	string breifDesc = "ERR"; // a brief description that will appear in the location menu

	string zeroDesc = "ERR"; // the early empty world | after 0 days
	string tenDesc = "ERR"; //plants begin to take over | after 10 days
	string fiftyDesc = "ERR"; //roads and basements flood | after 50 days
	string hundredDesc = "ERR"; //buildings begin to show damage | after 100 days

	string rainDesc = "ERR"; // an added phrase that mentions the deluige
	string winterDesc = "ERR"; // ann added phrase that mentions snow covor

	int abundantItem[LENGTH] = {}; //prob -= 5
	int commonItem[LENGTH] = {}; //prob += 0
	int uncommonItem[LENGTH] = {}; //prob += 5
	int rareItem[LENGTH] = {}; //prob += 10
	int noItem[LENGTH] = {}; // not meant to happen, one in 10,000 because yeet

	string likelyEvent[20] = {}; // prob = 0
	string unlikelyEvent[20] = {}; // prob += 5
	string impossibleEvent[20] = {}; // prob = 99999

	bool canFish = true;

	static Location initialiseHome()
	{
		Location home;

		home.locationName = "Home";

		return home;
	}


	static Location initialiseLensborough()
	{
		Location lensborough;

		lensborough.locationName = "Lensborough";
		lensborough.breifDesc = "The small suburban district where you live.";

		lensborough.zeroDesc = "The constant sound of nearby cars you've grown accustomed to is now gone, giving way to near silence.\n Only the sound of wind rustling leaves and the occasional birdsong, now heard from blocks away, breaks the deafening silence.\nSome cars are abandoned and sit in disorder at the side of the road, left to roll when their drivers vanished.\nTheir keys are still in the ignition, though the battery is long dead.\nWith no one to tend their yards, the grass grows tall.\n";

		lensborough.tenDesc = "The devistating silence of the empty world has, in only a short time, been quelled by life's natural cacophony.\nThe unkept lawns have given way to patches of wildflowers and the natural foliage of the land.\nThis encroachment of plantlife has in turn fed the growing masses of insects,\nwho themselves, fed the cacophony of birds that fly overhead, filling the streets with their song.\nIn the undergrowth and in the buildings the populations of mice and rats would too have found themselves uncontested in their expansion, if not for the owls, hawks, and feral cats who prey on them.\n";

		lensborough.fiftyDesc = "The architecture of these once artificial streets have fallen into disrepair.\nBlocked storm drains allow some roads and basements to flood, allowing frogs and dragonflies to take residence.\nThese ponds regularly satiate the number of wild game that roam the streets.\nDeer have grown very abundant, and show little fear for want of predators, yet they grow ever wary.\nThose basements which remain dry may reek of carcasses, now fed on by the black bears that have made their den.\nLooting buildings grows more dangerous.\n";

		lensborough.hundredDesc = "Trees and bushes have overgrown the lawns, and the streets, cracked and ruined sprout with grasses and wildflowers where not flooded.\n The deer and fowl, as well as the occasional herd of cattle, sheep, or horses now roam the streets ever mindful of the wolves and coyotes that make their dens amongst the rotted fenses and damaged buildings.\nIt's hard to imagine how things used to be.\n";

		lensborough.winterDesc = "With no street ploughs or shovels, the snow lies at an even depth accross the roads, sidewalks and driveways.\nThe freshly laid blanket snow is disturbed only by the tracks of animals, and yourself.\n";

		for (int i = 0; i < LENGTH; i++)
		{
			lensborough.abundantItem[i] = -1;
			lensborough.commonItem[i] = -1;
			lensborough.uncommonItem[i] = -1;
			lensborough.rareItem[i] = -1;
			lensborough.noItem[i] = -1;
		}


		lensborough.abundantItem[0] = 6; //deer
		lensborough.abundantItem[1] = 10; //turkey
		lensborough.abundantItem[2] = 15; //cat
		lensborough.abundantItem[3] = 14;//dog
		lensborough.abundantItem[4] = 33; //charcoal
		lensborough.abundantItem[5] = 22; //birdegg
		lensborough.abundantItem[6] = 24; //honey
		lensborough.abundantItem[7] = 25; //shaggymane

		lensborough.uncommonItem[0] = 7; //sheep
		lensborough.uncommonItem[1] = 31; //antibiotics
		lensborough.uncommonItem[2] = 30; //firstaidkit
		lensborough.uncommonItem[3] = 13; //horse
		lensborough.uncommonItem[4] = 12; //beef
		lensborough.uncommonItem[5] = 9; //duck
		lensborough.uncommonItem[6] = 8; //goose

		lensborough.rareItem[0] = 32; //rabies shot
		lensborough.rareItem[1] = 34; //antitoxin

		lensborough.noItem[0] = 18; //bass
		lensborough.noItem[1] = 19; //sunfish
		lensborough.noItem[2] = 36; //mussel
		lensborough.noItem[3] = 37; //salmon

		lensborough.likelyEvent[0] = "findDogFriend";
		lensborough.likelyEvent[1] = "findCatFriend";
		lensborough.likelyEvent[2] = "findMovie";
		lensborough.likelyEvent[3] = "schoolInsanity";
		lensborough.likelyEvent[4] = "findFishingRod"; 
		lensborough.likelyEvent[5] = "findRifle";
		
		lensborough.unlikelyEvent[0] = "rabidDog";
		lensborough.unlikelyEvent[1] = "wolfInsanity";
		lensborough.unlikelyEvent[2] = "coyoteAttack";
		lensborough.unlikelyEvent[3] = "findFireRuins";
		lensborough.unlikelyEvent[4] = "glassCut";

		lensborough.impossibleEvent[0] = "meetDelores";
		lensborough.impossibleEvent[1] = "mallInsanity";




		return lensborough;
	}

	static Location initialiseMayfeildCentre()
	{
		Location mayfeildCentre;

		mayfeildCentre.locationName = "Mayfeild Centre";
		mayfeildCentre.breifDesc = "A commercial district with supermarkets, pharmacies and restaurants.";

		mayfeildCentre.zeroDesc = "The now vacant parking lots howl with the gentle yet everpresent wind.\nThe now dark buildings stand as vast labyrinths of empty isles,\ndevoid of all life if not for the swarms of flies that plague the once fresh produce.\nThe bread is stale, and dairy remains firmly in warm refrigerators if only to avoid the smell.\nThe empty isles, once mundane, are completely alien, the silence and darkness is maddening.\n";

		mayfeildCentre.tenDesc = "The once silent supermakets now echo with the chirping of birds that have taken residence in the rafters.\nThe swarms of flies that plagued the fruit are gone, though the buildings are not devoid of insects.\nBees make their nests on store shelves, and puddles of rainwater now accent the tilework.\nThe greenery outside is now busy with insects and wildflowers.\n";

		mayfeildCentre.fiftyDesc = "Grass now grows through the craggled cement.\nThe parking lots now act as vast clearings where deer, turkies, and cattle graze amongst the now rusted cars.\nSome of the ditches and parking lots are now flooded, providing a home for waterfowl and frogs.\n";

		mayfeildCentre.hundredDesc = "The parking lots are now discernible only as forest clearings.\nThrough the cracked cement, bushes and grasses grow tall.\nThe buildings themselves have become vast caves, homes for gangs of dogs, cats, or at worse, bears.\nThe infrastructure has begun to falter, and the cars continue to rust.\n";

		mayfeildCentre.winterDesc = "The streets and parking lots lie under a blanket of snow.\nThe stores and buildings now provide some shelter from the cold and wind.\nThe insides of the cavernous supermarkets now creak and howl with the wind.\n";


		for (int i = 0; i < LENGTH; i++)
		{
			mayfeildCentre.abundantItem[i] = -1;
			mayfeildCentre.commonItem[i] = -1;
			mayfeildCentre.uncommonItem[i] = -1;
			mayfeildCentre.rareItem[i] = -1;
		}

		mayfeildCentre.abundantItem[0] = 0; //tomato
		mayfeildCentre.abundantItem[1] = 1; //pinapples
		mayfeildCentre.abundantItem[2] = 2; //corn
		mayfeildCentre.abundantItem[3] = 3; //water
		mayfeildCentre.abundantItem[4] = 4; //coffee
		mayfeildCentre.abundantItem[5] = 5; //beer
		mayfeildCentre.abundantItem[6] = 11; //seagull
		mayfeildCentre.abundantItem[7] = 30; //firstaid
		mayfeildCentre.abundantItem[8] = 31; //antibiotics
		mayfeildCentre.abundantItem[9] = 32; //rabies
		mayfeildCentre.abundantItem[10] = 34; //antitoxin
		mayfeildCentre.abundantItem[11] = 35; //tea

		mayfeildCentre.uncommonItem[0] = 25; //shaggymane
		mayfeildCentre.uncommonItem[1] = 26; //morel
		mayfeildCentre.uncommonItem[2] = 27; //chickenofthewoods
		mayfeildCentre.uncommonItem[3] = 16; //rabbit
		mayfeildCentre.uncommonItem[4] = 17; //squirrel

		mayfeildCentre.rareItem[0] = 14; //dog
		mayfeildCentre.rareItem[1] = 15; //cat

		mayfeildCentre.noItem[0] = 18; //bass
		mayfeildCentre.noItem[1] = 19; //sunfish
		mayfeildCentre.noItem[2] = 36; //mussel
		mayfeildCentre.noItem[2] = 37; //salmon

		mayfeildCentre.likelyEvent[0] = "meetDelores";
		mayfeildCentre.likelyEvent[1] = "findMovie";
		mayfeildCentre.likelyEvent[2] = "mallInsanity";

		mayfeildCentre.unlikelyEvent[0] = "rabidDog";
		mayfeildCentre.unlikelyEvent[1] = "wolfInsanity";
		mayfeildCentre.unlikelyEvent[2] = "coyoteAttack";
		mayfeildCentre.unlikelyEvent[3] = "findFireRuins";
		mayfeildCentre.unlikelyEvent[4] = "glassCut";
		mayfeildCentre.likelyEvent[5] = "findFishingRod";
		mayfeildCentre.likelyEvent[6] = "findRifle";

		mayfeildCentre.impossibleEvent[0] = "schoolInsanity";
		mayfeildCentre.impossibleEvent[1] = "findDogFriend";
		mayfeildCentre.impossibleEvent[2] = "findCatFriend";


		return mayfeildCentre;
	}

	static Location initialiseFrontSt()
	{
		Location frontSt;

		frontSt.locationName = "Front St";
		frontSt.breifDesc = "Waterfront area with shops, restaurants, and boats.";

		frontSt.zeroDesc = "The calls of seagulls, once hardly noticed, break the offputting silence.\nThe waves of Angel Bay lap at the boats and docks along the water.\nThe streets and shops, once popular, lie empty and silent.\nGardens grow tall and messy, and the water seems clearer than it used to be.\n";

		frontSt.tenDesc = "The once popular waterfront area has now been overtaken with foliage and the chirping of insects.\nThe populations of waterfowl and fish now grow and flourish.\n";

		frontSt.fiftyDesc = "After storms some of the boats have sunk or drifted away, others begin to rust.\nThe shops and restaurants now make homes for birds and insects.\nHerds of cattle and game come down by the water to drink.\nThe upper floors of the tallest buildings have become busy roosts for shorebirds.\n";

		frontSt.hundredDesc = "The infrastructure has begun to fail the shoreline, and the occasional flood has eroded away parts of the shoreline.\nBasements and streets have begun to flood, making new homes for snails, mussels and crustaceans.\nThe hotels have been transformed by the great flocks of gulls, terns and gannets that have made their homes in its upper floors.\n";

		frontSt.winterDesc = "A vast sheet of ice now extends over Angel Bay.\nBitterly cold wind sweeps in from the expanse, numbing your ears and hands.\nHoles bored in the ice allow access to the lethargic fish below.\nMost of the shorebirds have migrated away, though some remain in the frigid upper floors of buildings that tower above.\nThe flooded streets have now frozen over, allowing access to flooded lobbys and basements, if a bit slippy.\n";

		for (int i = 0; i < LENGTH; i++)
		{
			frontSt.abundantItem[i] = -1;
			frontSt.commonItem[i] = -1;
			frontSt.uncommonItem[i] = -1;
			frontSt.rareItem[i] = -1;
		}

		frontSt.abundantItem[0] = 8; //ganse
		frontSt.abundantItem[1] = 9; //ente 
		frontSt.abundantItem[2] = 18; //bass
		frontSt.abundantItem[3] = 19; //sunfish
		frontSt.abundantItem[4] = 4; //covfefe
		frontSt.abundantItem[5] = 5; //bier
		frontSt.abundantItem[6] = 11; //gull
		frontSt.abundantItem[7] = 14; //dog
		frontSt.abundantItem[8] = 15; //cyat
		frontSt.abundantItem[9] = 36; //mussel

		frontSt.uncommonItem[0] = 25; //shaggymane
		frontSt.uncommonItem[1] = 30; //firstAidKit
		frontSt.uncommonItem[2] = 31; //antibiotics
		frontSt.uncommonItem[3] = 16; //rabbit
		frontSt.abundantItem[4] = 7; //shep

		frontSt.rareItem[0] = 32; //rabies
		frontSt.rareItem[1] = 34; //antitoxin
		

		
		frontSt.likelyEvent[0] = "findMovie";
		

		frontSt.unlikelyEvent[0] = "rabidDog";
		frontSt.unlikelyEvent[1] = "wolfInsanity";
		frontSt.unlikelyEvent[2] = "coyoteAttack";
		frontSt.unlikelyEvent[3] = "findFireRuins";
		frontSt.unlikelyEvent[4] = "glassCut";
		frontSt.likelyEvent[5] = "findFishingRod";
		frontSt.likelyEvent[6] = "findRifle";

		frontSt.impossibleEvent[0] = "schoolInsanity";
		frontSt.impossibleEvent[1] = "findDogFriend";
		frontSt.impossibleEvent[2] = "findCatFriend";
		frontSt.impossibleEvent[3] = "meetDelores";
		frontSt.impossibleEvent[4] = "mallInsanity";

		return frontSt;
	}



	static Location* selectLocation(Player &player, Location* currentLocation, Location& lensborough, Location& mayfeildCentre, Location& frontSt)
	{
		system("CLS");

		char locationChoice = '&';

		Text::printOut("SELECT LOCATION\n\nCurrent Location: " + currentLocation->locationName + ".\n\n", player.getSanity());

		Text::printOut("[A] " + lensborough.locationName + "\n\t" + lensborough.breifDesc + "\n\n", player.getSanity());

		Text::printOut("[B] " + mayfeildCentre.locationName + "\n\t" + mayfeildCentre.breifDesc + "\n\n", player.getSanity());

		Text::printOut("[C] " + frontSt.locationName + "\n\t" + frontSt.breifDesc + "\n\n", player.getSanity());


		Text::printOut("Enter Location Letter:\n\n", player.getSanity());

		Text::printOut(">");
		cin >> locationChoice;
		cin.ignore(1000, '\n');

		PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);

		while (cin.fail() || (toupper(locationChoice) != 'A' && toupper(locationChoice) != 'B' && toupper(locationChoice) != 'C'))
		{
			Text::printOut("Enter a single valid letter only\n", player.getSanity());
			Text::printOut(">");
			cin >> locationChoice;
			cin.ignore(1000, '\n');
			PlaySound(TEXT("menu-navigate-01.wav"), NULL, SND_ASYNC);
		}

		switch (toupper(locationChoice))
		{
		case 'A':
			currentLocation = &lensborough;
			break;
		case 'B':
			currentLocation = &mayfeildCentre;
			break;
		case 'C':
			currentLocation = &frontSt;
			break;
		default:
			cout << "Error in selectLocation()\n", player.getSanity();
			break;
		}

		Text::printOut("Location set to: " + currentLocation->locationName + ".\n\n", player.getSanity());

		system("pause");

		return currentLocation;
	}

	void locationInfo(Player& player, Day day)
	{
		system("CLS");

		Text::printOut("You Enter: " + this->locationName + ".\n\n", player.getSanity());

		if (day.seasonNum == 4)
		{
			Text::printOut(this->winterDesc, player.getSanity());
		}
		else
		{
			if (day.dayNumber >= 100)
			{
				Text::printOut(this->hundredDesc, player.getSanity());
			}
			else if (day.dayNumber >= 50)
			{
				Text::printOut(this->fiftyDesc, player.getSanity());
			}
			else if (day.dayNumber >= 10)
			{
				Text::printOut(this->tenDesc, player.getSanity());
			}
			else
			{
				Text::printOut(this->zeroDesc, player.getSanity());
			}
		}

		Text::printOut("\n\n");

		system("pause");

	}

};


