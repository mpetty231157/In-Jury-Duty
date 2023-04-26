// DataGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Data.h"
using namespace std;

int main()
{

	// Create a vector of 20 years from 2002 to 2022
	vector<string> years;
	for (int i = 2002; i < 2022; i++) {
		years.push_back(to_string(i));
	}

	// Create a vector of state abbreviations
	vector<string> states = { "AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY" };

	// Create a vector of randomly generated (and some specifically added) city names
	vector<string> cities = { "Crestview", "Tampa", "Middleburg", "Jacksonville", "Orlando", "Riverside", "Lancaster", "Chandler", "Providence", "Lincoln", "Boise", "Boulder", "Fargo", "Lubbock", "Des Moines", "Waco", "Rochester", "Lexington", "Pittsburgh", "Huntsville", "Mesa", "Irvine", "Bismarck", "Grand Forks", "Hattiesburg", "Cedar Rapids", "Lawrence", "Norman", "Gillette", "Cheyenne", "Rock Springs", "Cody", "Bend", "Salem", "Eugene", "Medford", "Carlsbad", "Flagstaff", "El Paso", "Amarillo", "Laredo", "Fort Worth", "Helen", "Charleston", "Columbus", "Athens", "Pensacola", "Mobile", "Montgomery", "Portland", "Fayetteville", "Little Rock", "Topeka", "Butte", "Pueblo", "Casper", "North Platte", "Kearney", "Grand Island", "Scottsbluff", "Scranton", "Tupelo", "Biloxi", "Gulfport", "Lafayette", "New Iberia", "Gonzales", "Baton Rouge", "Slidell", "Hammond", "Joplin", "Cape Girardeau", "Fieldsprings", "Columbia", "Champaign", "Moline", "Peoria", "Davenport", "Iowa City", "Sarasota", "Ft. Myers", "St. Augustine", "Gainesville", "Ocala", "Destin", "Panama City", "Tallahassee", "Melbourne", "Daytona Beach", "Vero Beach", "Naples", "Marco Island", "Palm Beach", "Norfolk", "Springfield", "Wilmington", "Daytona", "New York City", "San Francisco", "Lakemont"};

	
	// Check that all values are unique, will output nothing if they are
	for (int i = 0; i < cities.size(); i++) {
		int cnt = count(cities.begin(), cities.end(), cities.at(i));
		if (cnt > 1) {
			cout << cities.at(i) << endl;
		}
	}

	// Use random to create a random generator and two distributions to randomly generate daysAway and caseRate
	default_random_engine gen;
	normal_distribution<double> distrDaysAway(2.5, 7.0);
	normal_distribution<double> distrCaseRate(8.0, 16.0);
	
	// Note: the loops below are technically really inefficient as they could run at worst case infinity time, however, this is intentional to avoid repeated values
	// Also, since this data generator is only run once, it should not create any inefficiency for our actual program run through the main

	// Create a loop that will repeatedly generate values and push them back if within a certain range for daysAway
	vector<double> daysAway;
	while (daysAway.size() != 100000) {
		double randomVal = distrDaysAway(gen);
		if (randomVal < 0.0) {
			continue;
		}
		if (randomVal > 120.0) {
			continue;
		}
		daysAway.push_back(randomVal);
	}
	

	// Create a loop that will repeatedly generate values and push them back if within a certain range for caseRate
	vector<double> caseRate;
	while(caseRate.size() != 100000) {
		double randomVal = distrCaseRate(gen);
		if (randomVal < 0.0) {
			continue;
		}
		if (randomVal > 250.0) {
			continue;
		}
		caseRate.push_back(randomVal);
	}

	// Create all possible combinations of the year, state and size, and create Data objects with them
	vector<Data> data;
	int index = 0;
	for (int i = 0; i < years.size(); i++) {
		for (int j = 0; j < states.size(); j++) {
			for (int k = 0; k < cities.size(); k++) {
				Data newData = Data(years.at(i), states.at(j), cities.at(k), daysAway.at(index), caseRate.at(index));
				data.push_back(newData);
				index++;
			}
		}
	}

	// Output the data to injuries.csv with proper formatting
	string filename = "injuries.csv";
	ofstream outfile(filename);

	outfile << "Year,City,State,daysAway,caseRate\n";

	for (int i = 0; i < data.size(); i++) {
		outfile << data.at(i).getName() << "," << data.at(i).getDaysAway() << "," << data.at(i).getCaseRate() << "\n";
	} 

	outfile.close();

	// Return 1 to show that program successfully created data
	return 1;

}
