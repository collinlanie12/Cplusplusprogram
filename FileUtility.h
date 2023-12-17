#ifndef FILE_UTILITY_H
#define FILE_UTILITY_H

/**
 * @file FileUtility.h
 * @author Collin Lanier
 * @brief This file contains the FileUtility class, its member variables, and its member functions.
 * @date 2023-12-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <map>
using namespace std;

/**
 * @brief This class is used to handle the file operations
 * 
 */
class FileUtility {
    public:
        // Constructor. Initializes the class with the path of the input file and output files
        FileUtility(const string& inputFilePath, const string& outputFilePath);

        // Reads the input file and returns a map of item frequencies
        map<string, int> readInputFile();

        // Writes the item frequencies to the output file
        void writeOutputFile(const map<string, int>& itemFrequencies);
    
    private:
        string inputFilePath; // Path of the input file
        string outputFilePath; // Path of the output file
};

#endif // FILE_UTILITY_H
