#include <iostream>
#include <vector>
#include <map>
#include <fstream>

auto getNameCount()
{
    std::cout << "How many names would you like to enter? ";
    int length{};
    std::cin >> length;

    return length;
}

void getNames(std::vector<std::string>& names, auto length)
{
    for (auto i{ 0 }; i < length; ++i)
    {
        std::string tempName {};
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, tempName);
        names.push_back(tempName);


    }
}

auto getCandidate()
{
	auto length {getNameCount()};
	std::vector<std::string> names {};
	getNames(names, length);
	return names;
}
auto printVector(const std::vector<std::string>& vector)
{
    auto x {1};
    for (const auto& i : vector)
    {
        std::cout << x << ": " << i << '\n';
        ++x;
    }
}

auto initVotes(std::vector<std::string>& names)
{
    std::map<std::string_view, int> votes {};
    for (const auto& item : names )
    {
        std::pair<std::string_view, int> initialCandidateVote {item, 0};
        votes.insert(initialCandidateVote);
    }
    return votes;
}

auto outToFile(std::map<std::string_view, int>& votes)
{
    std::ofstream of ;
    of.open("file.log");

    if (of.fail() || of.bad() || !of.is_open())
    {
        std::cout << "Failed opening file\n";
        return;
    }
    for (const auto& i : votes)
    {
        of << i.first << ": "<< i.second;
    }
    of.close();
    std::cout << "Successfully saved data\n";
}
void displayMenu()
{
    std::vector<std::string> candidate {getCandidate()};
    std::map<std::string_view, int> votes {initVotes(candidate)};
    while (true)
    {
        int choice {};
        std::cout << "ELECTION\n";
        printVector(candidate);
        std::cin >> choice;
        if (choice == 1000)
        {
            for (const auto& i : votes)
            {
                std::cout << i.first << ": "<< i.second;
                std::cout << '\n';
            }
            break;
        } else if (choice == 69)
        {
            std::cout << "Outputting to file\n";
            outToFile(votes);
            continue;

        }
        if (choice <= static_cast<int>(votes.size()))
        {
            ++votes[candidate.at(choice - 1)];
        }
        else
        {
            std::cout << "Illegal Choice, try again\n";
            continue;
        }
    }
}


int main()
{
    displayMenu();
    return 0;
}