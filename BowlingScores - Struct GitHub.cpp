#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// The purpose of this program is to collect the names and scores of bowlers from BowlingScores.txt and then calculate the average score for each bowler based on 5 game plays. Finally, the program will print out the names, scores, and calculated averages for each player. This program is a modified version of the original to include a structure.

// Constants - the number of rows and columns will not change, nor will the txt file that is being imported.
const string STATS = ("BowlingScores - GitHub.txt");
const int ROW = 10;
const int COL = 5;

// Define structure to hold data on players' stats
struct BowlerStats
{
    string bNames;
    int bScores[5] = { 0 };
    double bAvg = 0.0;
};

// Parameters for GetBowlingData include the txt file and the empty arrays for the bowlers' names and scores.
int GetBowlingData(string STATS, BowlerStats bowlers[ROW]) {
    // Import txt file
    ifstream fs;
    fs.open(STATS, ios::in);
    // Error message in case there is an issue with opening the file
    if (!fs) {
        cout << "File couldn't open" << endl;
        return -1;
    }

    // Nested for loop to collect names and scores from file

    for (int i = 0; i < ROW; i++) {
        fs >> bowlers[i].bNames;
        for (int x = 0; x < COL; x++) {
            // bScores is 2 dimensional, so it has 2 variables in place to locate each score
            fs >> bowlers[i].bScores[x];
        }
    }
    return 0;
}

// Function used to find average score for each player
void GetAverageScore(BowlerStats bowlers[ROW]) {
    double avg;

    // Another nested for loop to sum up scores by each bowler and calculate the average.
    for (int i = 0; i < ROW; i++) {
        int sum = 0;
        for (int x = 0; x < COL; x++) {
            sum += bowlers[i].bScores[x];
        }
        avg = sum / 4;
        // Averages are loaded into bAvg array
        bowlers[i].bAvg = avg;
    }
}

// Function designed to print the collected and calculated data from above functions
void PrettyPrintResults(const BowlerStats bowlers[ROW]) {

    // Nested for loop to print out data by player
    for (int i = 0; i < ROW; i++) {
        // Bowler name printed out first to identify who the scores and average belong to. Dashes added for distinction.
        cout << bowlers[i].bNames << " -- ";
        for (int x = 0; x < COL; x++) {
            // Bowler's 4 scores printed after dashes
            cout << bowlers[i].bScores[x] << " ";
        }
        // The word AVERAGE is printed to differentiate the following number from the rest of the scores
        cout << "AVERAGE: " << bowlers[i].bAvg << endl;
    }
}

int main()
{

    BowlerStats bowlers[ROW] =
    {
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0},
        {"", {0,0,0,0,0}, 0}
    };

    // Call functions with appropriate arguments
    GetBowlingData(STATS, bowlers);
    GetAverageScore(bowlers);
    PrettyPrintResults(bowlers);
}

