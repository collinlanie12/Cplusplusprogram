#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

/**
 * @file GroceryTracker.h
 * @author Collin Lanier
 * @brief This file contains the GroceryTracker class, its member variables, and its member functions.
 * @date 2023-12-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <map>
using namespace std;

/**
 * @brief This class is used to track the grocery items in the store.
 * 
 */
class GroceryTracker {
    public:
        // Constructor. Initializes the class with the path of the input file
        GroceryTracker(const map<string, int>& itemFrequencies);

        // Calulate the frequencies of each item from the input file
        void calculateItemFrequencies();

        // Print the frequencies of each item from the input fole
        void printItemFrequencies() const;

        // Searches for an item and prints its frequency
        void printItemFrequency(const string& itemName) const;

        // Returns the map of item names to their frequencies
        map<string, int> getItemFrequencies() const;

        // Prints a histogram representing the frequencies of each item from the input file
        void printHistogram() const;

    private:
        string inputFilePath; // Path of the input file
        map<string, int> itemFrequencies; // Map of item names to their frequencies

        // Reads the input file and stores the item frequencies in the itemFrequencies map
        void readInputFile(string inputFilePath);
};

#endif // GROCERY_TRACKER_H
