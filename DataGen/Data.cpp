#include "Data.h"

// Constructor that concatenates year + city + state for the year and stores other two data values
Data::Data(string year, string state, string city, double _daysAway, double _caseRate) {
	name = year + ',' + city + ',' + state;
	daysAway = _daysAway;
	caseRate = _caseRate;
}

// Simple getter functions for each piece of data in the Data object
string Data::getName() {
	return name;
}

double Data::getDaysAway() {
	return daysAway;
}

double Data::getCaseRate() {
	return caseRate;
}