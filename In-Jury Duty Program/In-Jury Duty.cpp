// In-Jury Duty.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

// Overide the comparison operator for comparing the pairs
struct ComparePairs {
    bool operator()(const pair<string, double>& p1, const pair<string, double>& p2) const {
        return p1.second < p2.second;
    }
};

#include "PQ.h"
#include "Umap.h"

int main()
{
    // Read in CSV File
    ifstream file("injuries.csv");

    vector<pair<string, double>> data;

    string line;
    getline(file, line);

    while (getline(file, line)) {

        stringstream ss(line);

        string year;
        string city;
        string state;

        getline(ss, year, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');

        string name = year + " " + city + ", " + state;

        double daysAway;
        double caseRate;

        getline(ss, line, ',');
        daysAway = stod(line);
        getline(ss, line, ',');
        caseRate = stod(line);

        double rating = 10.0 - ((0.02 * daysAway * caseRate) + (0.175 * caseRate));
        data.push_back(make_pair(name, rating));

    }

    // Determine which Data Structure to use
    string choice;
    bool maxHeap = false;
    cout << "What Data Structure would you like to use? (Default - Unordered Map)\n";
    cout << "0. Unordered Map\n1. Max Heap\n";
    cin >> choice;
    if (choice == "1") {
        maxHeap = true;
    }

    // Introduce the Program
    cout << "Welcome to the In-Jury Duty Program.\nHow can I help you today?\n";

    bool runProgram = true;
    while (runProgram) {
        // Provide Options
        cout << "1. Show Safest Place to Live\n";
        cout << "2. Show Most Dangerous Place to Live\n";
        cout << "3. Show Top 5 Safest Places to Live\n";
        cout << "4. Show Top 5 Most Dangerous Places to Live\n";
        cout << "5. Find Rating Given Place Name\n";
        cout << "6. Exit Program\n";

        // Ask for Input and Validate Input
        string taskString;
        char taskChar;
        int taskNumber;

        cin >> taskString;
        taskChar = taskString.at(0);
        if (taskString.size() != 1 || !isdigit(taskChar)) {
            cout << "Wrong Input, please input one of the options below.\n";
            continue;
        }
        taskNumber = taskChar - '0';

        // Choose an Option using a Switch Statement
        vector<string> results;
        double result;
        switch (taskNumber) {
        case 1:
        {
            // Show Safest Place to Live
            auto start = chrono::high_resolution_clock::now();
            if (maxHeap) {
                results = PQLargest(data, 1);
            }
            else {
                results = UmapLargest(data, 1);
            }
            for (int i = 0; i < results.size(); i++) {
                cout << results.at(i) << endl;
            }
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            cout << "Function Runtime: " << duration.count() << " microseconds\n";
            continue;
        }
        case 2:
        {
            // Show Most Dangerous Place to Live
            auto start = chrono::high_resolution_clock::now();
            if (maxHeap) {
                results = PQSmallest(data, 1);
            }
            else {
                results = UmapSmallest(data, 1);
            }
            for (int i = 0; i < results.size(); i++) {
                cout << results.at(i) << endl;
            }
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            cout << "Function Runtime: " << duration.count() << " microseconds\n";
            continue;
        }
        case 3:
        {
            // Show Top 5 Safest Places to Live
            auto start = chrono::high_resolution_clock::now();
            if (maxHeap) {
                results = PQLargest(data, 5);
            }
            else {
                results = UmapLargest(data, 5);
            }
            for (int i = 0; i < results.size(); i++) {
                cout << results.at(i) << endl;
            }
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            cout << "Function Runtime: " << duration.count() << " microseconds\n";
            continue;
        }
        case 4:
        {
            // Show Top 5 Most Dangerous Places to Live
            auto start = chrono::high_resolution_clock::now();
            if (maxHeap) {
                results = PQSmallest(data, 5);
            }
            else {
                results = UmapSmallest(data, 5);
            }
            for (int i = 0; i < results.size(); i++) {
                cout << results.at(i) << endl;
            }
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            cout << "Function Runtime: " << duration.count() << " microseconds\n";
            continue;
        }
        case 5:
        {
            // Ask for the Name
            string year;
            string state;
            string city;

            cout << "What Year are you looking for?\n";
            cin >> year;
            cout << "What State is your City in?\n";
            cin >> state;
            cout << "What is the name of your City?\n";
            getline(cin, city);

            string name = year + " " + city + ", " + state;

            // Find Rating Given Place Name

            auto start = chrono::high_resolution_clock::now();
            if (maxHeap) {
                result = PQgetRating(data, name);
            }
            else {
                result = UmapgetRating(data, name);
            }
            cout << result << endl;
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            cout << "Function Runtime: " << duration.count() << " microseconds\n";
            continue;
        }
        case 6:
        {
            // Exit the Program
            runProgram = false;
            continue;
        }
        default:
        {
            cout << "Wrong Input, please input one of the options below.\n";
            continue;
        }

        }

    }
}