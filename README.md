## Election Voting System

The Election Voting System is a C++ program that allows users to vote for candidates participating in an election. The system provides a user-friendly interface for voting, saves the vote counts to a file, and provides functionality to validate the votes.

### Prerequisites

The program requires a C++ compiler and the following standard libraries:

- `<iostream>`
- `<fstream>`
- `<string>`
- `<vector>`
- `<map>`
- `<limits>`
- `<sstream>`
- `<stdexcept>`

### Getting Started

1. Clone the repository or download the source code files.
2. Compile the C++ code using a C++ compiler.
3. Run the compiled program.

### Usage

1. When the program starts, it will prompt you to enter the number of candidates participating in the election.
2. Enter the number of candidates as a positive integer.
3. Next, you will be asked to enter the names of the candidates one by one.
4. Provide the name for each candidate. Empty names are not allowed, so make sure to enter valid names.
5. After entering the candidate names, the program will display the voting menu.
6. Choose a candidate by entering the corresponding number next to their name.
7. You can also choose the option to display the current vote count or exit the program.
8. Continue voting until you choose the exit option.
9. Upon exiting, the program will save the votes to a file named "votes.txt" and validate them against the saved votes.
10. Any errors that occur during the process will be displayed on the console.

### File Structure

- `main.cpp`: Contains the main program code.
- `votes.txt`: The file where the vote counts are saved.

### License

This project is licensed under the [MIT License](LICENSE).

### Contributing

Contributions are welcome! If you find any issues or want to enhance the program, please submit a pull request.

### Authors

The Election Voting System program was created by [chunkboi].
