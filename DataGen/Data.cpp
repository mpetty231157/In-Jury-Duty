#include "Data.h"

Data::Data(string year, string state, string city, double _daysAway, double _caseRate) {
	name = year + ',' + city + ',' + state;
	daysAway = _daysAway;
	caseRate = _caseRate;
}

string Data::getName() {
	return name;
}

double Data::getDaysAway() {
	return daysAway;
}

double Data::getCaseRate() {
	return caseRate;
}