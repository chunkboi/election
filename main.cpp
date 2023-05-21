#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <thread>

/**
 * Clears the console screen.
 */
void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

/**
 * Saves the votes to a file.
 *
 * @param votes The map containing the candidate names and their vote counts.
 * @throws std::runtime_error If unable to open the file for saving votes.
 */
void saveVotes(const std::map<std::string, int>& votes) {
    std::ofstream file("votes.txt");
    if (!file) {
        throw std::runtime_error("Unable to open file for saving votes.");
    }

    for (const auto& pair : votes) {
        file << pair.first << ":" << pair.second << std::endl;
    }

    file.close();
    
}

/**
 * Reads the votes from a file.
 *
 * @return The map containing the candidate names and their vote counts.
 * @throws std::runtime_error If unable to open the file for reading votes.
 */
std::map<std::string, int> readVotes() {
    std::map<std::string, int> votes;
    std::ifstream file("votes.txt");
    if (!file) {
        throw std::runtime_error("Unable to open file for reading votes.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string candidate;
        int count;
        if (std::getline(iss, candidate, ':') && iss >> count) {
            votes[candidate] = count;
        }
    }

    file.close();
    return votes;
}

/**
 * Validates the votes against the saved votes.
 *
 * @param votes The map containing the candidate names and their vote counts.
 */
void validateVotes(const std::map<std::string, int>& votes) {
    try {
        std::map<std::string, int> savedVotes = readVotes();
        if (votes == savedVotes) {
            std::cout << "Votes validated." << std::endl;
        }
        else {
            std::cout << "Votes mismatched with the saved votes." << std::endl;
            std::cout << "Saving the current vote count to the file..." << std::endl;
            try {
                saveVotes(votes);
                std::cout << "Current vote count saved successfully." << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "An error occurred while saving votes: " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred while reading saved votes: " << e.what() << std::endl;
    }
}

/**
 * Gets the number of candidates from the user.
 *
 * @return The number of candidates.
 */
int getNumCandidates() {
    int numCandidates;
    while (true) {
        std::cout << "Enter the number of candidates: ";
        if (std::cin >> numCandidates && numCandidates > 0) {
            break;
        }
        else {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore newline character
    return numCandidates;
}

/**
 * Gets the names of the candidates from the user.
 *
 * @param numCandidates The number of candidates.
 * @return A vector containing the candidate names.
 */
std::vector<std::string> getCandidateNames(int numCandidates) {
    std::vector<std::string> candidates;
    candidates.reserve(numCandidates);
    for (int i = 0; i < numCandidates; ++i) {
        std::cout << "Enter the name of candidate " << (i + 1) << ": ";
        std::string name;
        std::getline(std::cin, name);
        if (name.empty()) {
            std::cout << "Candidate name cannot be empty. Please try again." << std::endl;
            --i; // Retry for the same candidate
            continue;
        }
        candidates.emplace_back(name);
    }
    return candidates;
}

/**
 * Displays the voting menu.
 *
 * @param candidates A vector containing the candidate names.
 */
void displayVotingMenu(const std::vector<std::string>& candidates) {
    std::cout << "\n===== Election Voting Menu =====" << std::endl;
    for (int i = 0; i < candidates.size(); ++i) {
        std::cout << (i + 1) << ". " << candidates[i] << std::endl;
    }
    std::cout << (candidates.size() + 1) << ". Display Vote Count" << std::endl;
    std::cout << (candidates.size() + 2) << ". Exit" << std::endl;
}

/**
 * Displays the current vote count.
 *
 * @param votes The map containing the candidate names and their vote counts.
 */
void displayVoteCount(const std::map<std::string, int>& votes) {
    std::cout << "\n===== Current Vote Count =====" << std::endl;
    for (const auto& pair : votes) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

/**
 * Records the vote based on the user's choice.
 *
 * @param votes The map containing the candidate names and their vote counts.
 * @param candidates A vector containing the candidate names.
 */
void vote(std::map<std::string, int>& votes, const std::vector<std::string>& candidates) {
    int choice;
   
    while (true) {
        clearScreen();
        displayVotingMenu(candidates);  // Display the menu
        std::cout << "\nEnter your choice: ";
        if (std::cin >> choice && choice >= 1 && choice <= candidates.size()) {
            votes[candidates[choice - 1]]++;
            std::cout << "Vote registered for " << candidates[choice - 1] << std::endl;
        }
        else if (choice == (candidates.size() + 1)) {
            clearScreen();
            displayVoteCount(votes);
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        }
        else if (choice == (candidates.size() + 2)) {
            clearScreen();
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

 }

/**
 * Runs the election voting process.
 */
void runElection() {
    clearScreen();
    int numCandidates = getNumCandidates();
    clearScreen();

    if (numCandidates == 0) {
        std::cout << "No candidates to vote for. Exiting the program." << std::endl;
        return;
    }

    std::vector<std::string> candidates = getCandidateNames(numCandidates);
    clearScreen();

    std::map<std::string, int> votes;

    for (const auto& candidate : candidates) {
        votes[candidate] = 0;
    }

    vote(votes, candidates);

    try {
        saveVotes(votes);
        std::cout << "Votes Saved to file\n";
        validateVotes(votes);
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        std::cout << "Unable to save votes. Displaying the current vote count:" << std::endl;
        displayVoteCount(votes);
    }
    
}

int main() {
    runElection();

    return 0;
}
