# Election Voting System

The code provided implements an election voting system. It allows users to vote for candidates, saves the vote counts to a file, and provides functionality to validate the votes. The system is implemented in C++.

## Prerequisites

The code requires the following libraries to be included:

- `<iostream>`: Provides basic input/output operations.
- `<fstream>`: Enables file input/output operations.
- `<string>`: Provides string manipulation functions.
- `<vector>`: Implements dynamic arrays.
- `<map>`: Implements associative arrays (key-value pairs).
- `<limits>`: Provides information about numeric limits.
- `<sstream>`: Allows string stream operations.
- `<stdexcept>`: Defines standard exception classes.

## Function Definitions

### `clearScreen()`

This function is responsible for clearing the console screen. It uses escape sequences to clear the screen and move the cursor to the top left corner.

### `saveVotes(const std::map<std::string, int>& votes)`

This function saves the vote counts to a file named "votes.txt". It takes a map containing candidate names as keys and their corresponding vote counts as values. The function opens the file and writes each candidate's name and vote count in the format `"candidate_name:vote_count"`, with each entry on a new line.

### `readVotes()`

This function reads the vote counts from the "votes.txt" file and returns a map containing the candidate names and their corresponding vote counts. It opens the file, reads each line, and extracts the candidate name and vote count using string stream operations. The function then populates the map with the extracted data.

### `getNumCandidates()`

This function prompts the user to enter the number of candidates participating in the election. It reads the input from the user, validates it, and returns the number of candidates as an integer. If the user enters an invalid input (not a positive integer), an error message is displayed, and the user is prompted to enter a valid input.

### `getCandidateNames(int numCandidates)`

This function prompts the user to enter the names of the candidates. It takes the number of candidates as a parameter and returns a vector of strings containing the candidate names. The function iterates `numCandidates` times and prompts the user to enter the name for each candidate. Empty names are not allowed, and the user is prompted to re-enter the name if they provide an empty name.

### `displayVotingMenu(const std::vector<std::string>& candidates)`

This function displays the voting menu. It takes a vector of strings containing the candidate names as a parameter. The function outputs the menu options to the console, including the candidate names, an option to display the current vote count, and an option to exit the program.

### `displayVoteCount(const std::map<std::string, int>& votes)`

This function displays the current vote count. It takes a map containing the candidate names and their corresponding vote counts as a parameter. The function iterates over the map and outputs each candidate's name and vote count to the console.

### `vote(std::map<std::string, int>& votes, const std::vector<std::string>& candidates)`

This function handles the voting process. It takes a map containing the candidate names and their corresponding vote counts, and a vector of strings containing the candidate names. The function displays the voting menu, prompts the user to enter their choice, and updates the vote count accordingly. The user can choose a candidate to vote for, display the current vote count, or exit the program. The function continues to prompt for choices until the user selects the exit option. After the voting process is completed, the function saves the votes to a file using the `saveVotes()` function. If the exit option is chosen

, the function also validates the votes using the `validateVotes()` function.

### `validateVotes(const std::map<std::string, int>& votes)`

This function validates the votes by comparing them with the saved votes. It takes a map containing the candidate names and their corresponding vote counts as a parameter. The function reads the saved votes from the "votes.txt" file using the `readVotes()` function. It compares the current votes with the saved votes. If they match, a success message is displayed. If they do not match, an error message is displayed, and the current vote count is saved to the file. If any errors occur during the reading or saving process, appropriate error messages are displayed.

### `runElection()`

This function is the main entry point for running the election. It clears the screen, prompts the user for the number of candidates, and obtains the candidate names. It initializes the vote count map with the candidate names and starts the voting process using the `vote()` function. After the voting process, it saves the votes and validates them. If any errors occur during the saving or validation process, appropriate error messages are displayed.

### `main()`

The main function is responsible for starting the election by calling the `runElection()` function.

## Usage

To use the election voting system, compile and run the C++ code. The program will prompt you to enter the number of candidates participating in the election. Then, you will be asked to enter the names of the candidates. After providing the candidate names, the program will display the voting menu, where you can choose a candidate to vote for, display the current vote count, or exit the program. Upon exiting, the program will save the votes and validate them against the saved votes. Any errors that occur during the process will be displayed on the console.

Ensure that the program has write access to the file system to save the vote counts to the "votes.txt" file.
