#pragma once
#include <string>
#include <iostream>
#include <random>
using namespace std;
class Data
{

	string name;
	double daysAway;
	double caseRate;

public:

	Data(string year, string state, string city, double _daysAway, double _caseRate);
	string getName();
	double getDaysAway();
	double getCaseRate();

};

