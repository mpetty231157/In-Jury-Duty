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
    for (auto & it : data){
        string year = it.first;
        double rating = it.second;
        testMap[year] = rating;
    }


    vector<string> smallestNums;
    //Store smallest values into a vector of strings
    for (int i = 0; i < numElements; i++) {
        double min_val = INT_MAX;
        auto pointer = testMap.begin();
        //find smallest value in map and set pointer to its position
        for (auto it = testMap.begin(); it != testMap.end(); ++it){
            if (min_val > it->second){
                min_val = it->second;
                pointer = it;
            }
        }
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
    for (auto & it : data){
        string year = it.first;
        double rating = it.second;
        testMap[year] = rating;
    }


    vector<string> smallestNums;
    //Store smallest values into a vector of strings
    for (int i = 0; i < numElements; i++) {
        double max_val = INT_MIN;
        auto pointer = testMap.begin();
        //Rewrite min_element to find largest value in map
        for (auto it = testMap.begin(); it != testMap.end(); ++it){
            if (max_val < it->second){
                max_val = it->second;
                pointer = it;
            }
        }
        //Add name to the vector of strings and erase the value
        smallestNums.push_back(pointer->first);

        testMap.erase(pointer->first);
    }

    return smallestNums;
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