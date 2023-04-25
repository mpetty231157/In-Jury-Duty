#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

//Returns the smallest ratings given the numElements input using a unordered map
vector<string> UmapSmallest(vector<pair<string, double>>& data, int numElements) {

    //The key is the year/location and the value is the injury rating
    unordered_map <string, double> testMap;
    //Add all of the data points to the unordered map
    for (int i = 0; i < data.size(); i++) {
        testMap[data.at(i).first] = data.at(i).second;
    }

    vector<string> smallestNums;
    //Store smallest values into a vector of strings
    for (int i = 0; i < numElements; i++) {

        //Rewrite min_element to find smallest value in map
        auto pointer = min_element(testMap.begin(), testMap.end(), [](const auto& x, const auto& y) {
            return x.second < y.second;
            });

        //Add name to the vector of strings and erase the value
        smallestNums.push_back(pointer->first);

        testMap.erase(pointer->first);
    }

    return smallestNums;
}

//Returns the largest ratings given the numElements input using a unordered map
vector<string> UmapLargest(vector<pair<string, double>>& data, int numElements) {

    //The key is the year/location and the value is the injury rating
    unordered_map <string, double> testMap;

    //Add all of the data points to the unordered map
    for (int i = 0; i < data.size(); i++) {
        testMap[data.at(i).first] = data.at(i).second;
    }

    vector<string> largestNums;
    //Store largest values into a vector of strings
    for (int i = 0; i < numElements; i++) {

        //Rewrite max_element to find largest value in unordered map
        auto pointer = max_element(testMap.begin(), testMap.end(), [](const auto& x, const auto& y) {
            return x.second < y.second;
            });

        //Add name to the vector of strings and erase the value
        largestNums.push_back(pointer->first);

        testMap.erase(pointer->first);
    }

    return largestNums;
}

//Returns the rating of a data point given the name using a unordered map
double UmapgetRating(vector<pair<string, double>>& data, string name) {

    //The key is the year/location and the value is the injury rating
    unordered_map <string, double> testMap;

    //Add all of the data points to the unordered map
    for (int i = 0; i < data.size(); i++) {

        testMap[data.at(i).first] = data.at(i).second;
    }

    double rating = 0;
    //Use find() function to see if name is in map
    if (testMap.find(name) == testMap.end()) {
        //If not state NOT FOUND
        rating = 0;
        cout << "NOT FOUND" << endl;
    }
    else {
        //If so save its rating and return it
        rating = testMap[name];
    }


    return rating;
}