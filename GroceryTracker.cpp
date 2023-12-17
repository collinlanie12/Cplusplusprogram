#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
using namespace std;

// Constructor for the GroceryTracker class
GroceryTracker::GroceryTracker(const map<string, int>& frequencies) : itemFrequencies(frequencies) {}

/**
 * @brief  Returns the map of item names to their frequencies
 * 
 * @param none
 * @return map<string, int> - map of item names to their frequencies
 */
map<string, int> GroceryTracker::getItemFrequencies() const {
    return itemFrequencies;
}

/**
 * @brief Calculates item frequencies by reading the input file
 * 
 * @param none
 * @return void
 */
void GroceryTracker::calculateItemFrequencies() {
    readInputFile(inputFilePath);
}

/**
 * @brief Prints each item with its frequency to the console
 * 
 * @param none
 * @return void
 */
void GroceryTracker::printItemFrequencies() const {
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << " " << pair.second << endl;
    }
}

/**
 * @brief Searches for an item and prints its frequency to the console
 * 
 * @param itemName - name of the item to print the frequency of
 * @return void
 */
void GroceryTracker::printItemFrequency(const string& itemName) const {
    auto it = itemFrequencies.find(itemName);
    if (it != itemFrequencies.end()) {
        cout << itemName << " frequency: " << it->first << " " << it->second << endl;
    } else {
        cout << itemName << " not found." << endl;
    }
}


/**
 * @brief Prints a histogram for each item, using asterisks to represent frequency
 * 
 * @param none
 * @return void
 */
void GroceryTracker::printHistogram() const {
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

/**
 * @brief Reads the input file and stores the item frequencies in the itemFrequencies map
 * 
 * @param none
 * @return void
 */
void GroceryTracker::readInputFile(string inputFilePath) {
    ifstream inputFile(inputFilePath);
    string item;
    while (inputFile >> item) {
        ++itemFrequencies[item]; // Increment the frequency of the item
    }
}
