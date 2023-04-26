#pragma once
#include <string>
#include <iostream>
#include <random>
using namespace std;
class Data
{
	// Store all three things that create a data point (name + data that creates the rating)
	string name;
	double daysAway;
	double caseRate;

public:

	// Constructor that combines year + city + state for the name and stores daysAway and caseRate
	Data(string year, string state, string city, double _daysAway, double _caseRate);

	// Getter functions which will be useful for writing the data
	string getName();
	double getDaysAway();
	double getCaseRate();

};

