#include "GroceryTracker.h"
#include "FileUtility.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

/**
 * @brief This is the main function of the program. It will have the input and output file paths.
 * The main function will also have the menu for the user to choose from. It will also call 
 * the functions from the GroceryTracker and FileUtility classes.
 * 
 * @param none
 * 
 * @return int
 */
int main() {
    // Get the input and output file paths
    string inputFilePath = "assets/CS210_Project_Three_Input_File.txt";
    string outputFilePath = "frequency.dat";

    // Create an instance of the FileUtility class
    FileUtility fileUtility(inputFilePath, outputFilePath);
    auto itemFrequencies = fileUtility.readInputFile(); // Read the input file and get the item frequencies

    // Create an instance of the GroceryTracker class
    GroceryTracker groceryTracker(itemFrequencies);

    // Calculate the frequencies of items from the input file
    groceryTracker.calculateItemFrequencies();

    // Flag to control the main program loop
    bool running = true;
    while(running){
        //Display the menu options
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "1. Search for an item frequency" << endl;
        cout << "2. Print all item frequencies" << endl;
        cout << "3. Print a histogram of item frequencies" << endl;
        cout << "4. Exit" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << "Enter your choice: ";

        //Get the user's choice
        int choice;
        cin >> choice;

        //Handle invalid input
        if(cin.fail()){
            cin.clear(); // clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
            continue;
        }

        //Handle the user's choice
        switch(choice) {
            case 1: {
                // Get the item name from the user and print its frequency
                cout << "Enter the item name to search: ";
                string itemName;
                cin >> itemName;
                groceryTracker.printItemFrequency(itemName);
                break;
            }
            case 2: {
                groceryTracker.printItemFrequencies(); // Print the frequencies of each item
                break;
            }
            case 3: {
                groceryTracker.printHistogram(); // Print the histogram
                break;
            }
            case 4: {
                running = false; // Exit the program
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    // Write the calculated frequencies to the output file
    fileUtility.writeOutputFile(groceryTracker.getItemFrequencies());

    return 0;
    
}
