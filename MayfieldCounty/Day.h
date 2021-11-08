#pragma once
#include <string>

using namespace std;

class Day
{
public:
	int dayNumber;
	int seasonNum;
	int year;
	int totalDays;
	string season;
	bool isRaining;
	bool isSnowing;
	bool isBuggy;
	bool isHot;
	bool isCold;

	string dailyInformation = "undefined";
	string drunkInformation = "undefined";

	bool updateInfo; // used to check for status information

	Day()
	{
		season = "spring";
		seasonNum = 1;
		dayNumber = 1;
		year = 1;
		totalDays = 1;
		isRaining = false;
		isSnowing = false;
		isBuggy = false;
		isHot = false;
		isCold = false;
	}

	void nextDay()
	{
		dayNumber++;
		totalDays++;

		if (dayNumber > 10 && seasonNum != 4 || dayNumber > 30)
		{
			dayNumber = 1;

			switch (seasonNum)
			{
			case 1:
				seasonNum = 2;
				season = "summer";
				break;
			case 2:
				seasonNum = 3;
				season = "fall";
				break;
			case 3:
				seasonNum = 4;
				season = "winter";
				break;
			case 4:
				seasonNum = 1;
				season = "spring";
				year++;
				break;
			}

		}
	}
};


