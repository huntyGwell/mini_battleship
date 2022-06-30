#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unsigned int i = 0;
unsigned int j = 0;

void PrintGuess1 (vector<string>& p2Coord);

void PrintGuess2 (vector<string>& p1Coord);

void PrintCompareP1GuessToP2Coordinates (string p1Guess, vector<string>& p2Coord);

void PrintCompareP2GuessToP1Coordinates (string p2Guess, vector<string>& p1Coord);

void PrintP1Coord(vector<string>& p1Coord);

void PrintP2Coord(vector<string>& p2Coord);


int main() {

    const int VECT_SIZE = 6;

    vector<string> player1Coordinates(VECT_SIZE);

    vector<string> player2Coordinates(VECT_SIZE);

    string guess1;
    string guess2;


    cout << "Enter Player 1's chosen coordinates: " << endl;
    for (i = 0; i < player1Coordinates.size(); i++) {
        cin >> player1Coordinates.at(i);
    }


    cout << "Enter Player 2's chosen coordinates: " << endl;
    for (i = 0; i < player2Coordinates.size(); i++) {
        cin >> player2Coordinates.at(i);
    }

    while (!player1Coordinates.empty() && !player2Coordinates.empty()) {

        PrintGuess1(player2Coordinates);

        if (player2Coordinates.empty()) {
            break;
        }

        PrintGuess2(player1Coordinates);

    }

    if (player1Coordinates.empty()) {
        cout << "Player 2 is the winner. Their unsunk ships were at: ";
        PrintP2Coord(player2Coordinates);
        cout << endl;
    }

    if (player2Coordinates.empty()) {
        cout << "Player 1 is the winner. Their unsunk ships were at: ";
        PrintP1Coord(player1Coordinates);
        cout << endl;
    }

    return 0;
}

void PrintCompareP1GuessToP2Coordinates (string p1Guess, vector<string>& p2Coord) {
    bool hit;
    for (j = 0; j < p2Coord.size(); j++) {
        for (i = 0; i <p2Coord.size(); i++) {
            if (p1Guess == p2Coord.at(i)) {
                hit = true;
                cout << p2Coord.at(i) << " was a hit!";
                p2Coord.erase(p2Coord.begin() + i);
                break;
            }
        }
    }
    if (!hit) {
        cout << p1Guess << " was a miss.";
    }
}

void PrintCompareP2GuessToP1Coordinates (string p2Guess, vector<string>& p1Coord) {
    bool hit;
    for (j = 0; j < p1Coord.size(); j++) {
        for (i = 0; i < p1Coord.size(); i++) {
            if (p2Guess == p1Coord.at(i)) {
                hit = true;
                cout << p1Coord.at(i) << " was a hit!";
                p1Coord.erase(p1Coord.begin() + i);
                break;
            }
        }
    }
    if (!hit) {
        cout << p2Guess << " was a miss.";
    }
}

void PrintGuess1 (vector<string>& p2Coord) {
    string guess1;
    cout << "\nIt is player 1's turn. Enter a guess: ";
    cin >> guess1;
    PrintCompareP1GuessToP2Coordinates(guess1, p2Coord);
}

void PrintGuess2 (vector<string>& p1Coord) {
    string guess2;
    cout << "\nIt is player 2's turn. Enter a guess: ";
    cin >> guess2;
    PrintCompareP2GuessToP1Coordinates(guess2, p1Coord);
}
void PrintP1Coord(vector<string>& p1Coord) {
    for (i = 0; i < p1Coord.size(); i++) {
        cout << p1Coord.at(i) << " ";
    }
}

void PrintP2Coord(vector<string>& p2Coord) {
    for (i = 0; i < p2Coord.size(); i++) {
        cout << p2Coord.at(i) << " ";
    }
}
