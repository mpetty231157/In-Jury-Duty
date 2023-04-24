#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//Returns the smallest ratings given the numElements input using a Max Heap
vector<string> PQSmallest(vector<pair<string, double>>& data, int numElements) {

    priority_queue<pair<string, double>, vector<pair<string, double>>, ComparePairs> pq;

    //Iterates through all the data
    for (auto i : data) {
        //Have numElements be the max size of Max heap and only add to it if new element is lower than top
        if (pq.size() == numElements && i.second >= pq.top().second) {
            continue;
        }
        //Push on new lower elements and if size is too big pop the biggest element
        pq.push(i);
        if (pq.size() > numElements) {
            pq.pop();
        }
    }

    vector<string> smallestNames;
    //Store names with smallest values into a vector of strings
    while (!(pq.empty())) {
        smallestNames.push_back(pq.top().first);
        pq.pop();
    }
    //Reverse the order to its in lowest order and return it
    reverse(smallestNames.begin(), smallestNames.end());

    return smallestNames;
}

//Returns the largest ratings given the numElements input using a max heap
vector<string> PQLargest(vector<pair<string, double>>& data, int numElements) {

    priority_queue<pair<string, double>, vector<pair<string, double>>, ComparePairs> pq;

    //Push all of the given data to the max heap
    for (int i = 0; i < data.size(); i++) {
        pq.push(data.at(i));
    }

    vector<string> largestNames;
    //Pop the top numElements and add to a vector of strings as the largest inputs
    for (int i = 0; i < numElements; i++) {
        largestNames.push_back(pq.top().first);
        pq.pop();
    }

    //Return the vector of strings
    return largestNames;
}

//Returns the rating of a data point given the name using a max heap
double PQgetRating(vector<pair<string, double>>& data, string name) {

    priority_queue<pair<string, double>, vector<pair<string, double>>, ComparePairs> pq;

    //Push all of the data to a max heap
    for (int i = 0; i < data.size(); i++) {
        pq.push(data.at(i));
    }

    double rating = -1000;
    //Iterate through entire max heap, if element is found return that
    for (int i = 0; i < data.size(); i++) {
        if (pq.top().first == name) {
            rating = pq.top().second;
            break;
        }

        pq.pop();
    }
    //If name is not found print NOT FOUND
    if (rating == -1000) {
        cout << "NOT FOUND" << endl;

        rating = 0;
    }

    return rating;
}
