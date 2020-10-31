#include <iostream>

using namespace std;

const int boardWidth = 5;
const int boardHeight = 5;

const int scoreWhiteMaster = 10;
const int scoreWhiteStudent = 1;
const int scoreBlackMaster = -10;
const int scoreBlackStudent = -1;

/**
 * Funkcia, ktorá na štandardný výstup vypíše obsah poľa znakov 5x5
 * Funkcia toto pole nijako nemodifikuje
 *
 * @param board šachovnica, ktorú treba vypísať
 */
void printBoard(char board[boardWidth][boardHeight]) {
    for(int row = 0; row < boardHeight; row++) {
        for(int column = 0; column < boardWidth; column++) {
            cout << board[column][row];
        }
        cout << endl;
    }
}

/**
 * Funkcia, vyráta ohodnotenie šachovnice. Vyššie skóre znamená
 * viac bodov pre hráča W, nižšie znamená lepšie skóre pre hráča B
 *
 * @param board šachovnica, ktorú treba ohodnotiť
 * @return skóre šachovnice
 */
int scoreBoard(char board[boardWidth][boardHeight]) {
    int score = 0;
    for(int row = 0; row < boardHeight; row++) {
        for(int column = 0; column < boardWidth; column++) {
            switch ((board)[column][row]) {
                case 'W': score += scoreWhiteMaster; break;
                case 'w': score += scoreWhiteStudent; break;
                case 'B': score += scoreBlackMaster; break;
                case 'b': score += scoreBlackStudent; break;
            }
        }
    }
    return score;
}

int main() {

    char board[boardWidth][boardHeight];

    // Načítanie šachovnice
    // Šachovnica bude pootočená, aby som zavolaním board[x][y]
    // získal figúrku na pozícii [x,y]

    for(int row = 0; row < boardHeight; row++) {
        string rowText;
        cin >> rowText;
        for(int column = 0; column < boardWidth; column++) {
            board[column][row] = rowText[column];
        }
    }


    printBoard(board);
    cout << "Score is: " << scoreBoard(board) << endl;

    return 0;
}
