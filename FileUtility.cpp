#include "FileUtility.h"
#include <fstream>
#include <iostream>
using namespace std;

// Constructor for the FileUtility class
FileUtility::FileUtility(const string& inputFilePath, const string& outputFilePath) : inputFilePath(inputFilePath), outputFilePath(outputFilePath) {}

/**
 * @brief Reads the input file and returns a map of item frequencies
 * 
 * @param none
 * @return map<string, int> - map of item names to their frequencies
 */
map<string, int> FileUtility::readInputFile() {
    map<string, int> itemFrequencies;

    try {
        ifstream inputFile(inputFilePath);
        
        // Check to see if the file is being opened successfully
        if(!inputFile){
            throw runtime_error("Error opening input file " + inputFilePath);
        }

        string item;

        while(inputFile >> item) {
            ++itemFrequencies[item]; // Increment the frequency of the item
        }
    } catch(const exception& e) {
        cerr << "Exception occured: " << e.what() << endl;
        exit(1);
    }
    
    return itemFrequencies;
}

/**
 * @brief Writes the item frequencies to the output file
 * 
 * @param itemFrequencies - map of item names to their frequencies
 * @return void
 */
void FileUtility::writeOutputFile(const map<string, int>& itemFrequencies) {
    try {
        ofstream outputFile(outputFilePath);

        if(!outputFile){
            throw runtime_error("Error opening output file " + outputFilePath);
        }

        for (const auto& pair : itemFrequencies) {
            outputFile << pair.first << " " << pair.second << endl;
        }
    } catch(const exception& e) {
        cerr << e.what() << endl;
    }
    
}
