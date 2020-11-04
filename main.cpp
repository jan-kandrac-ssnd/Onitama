#include <iostream>
#include <vector>

using namespace std;

const int boardWidth = 5;
const int boardHeight = 5;

const int scoreWhiteMaster = 10;
const int scoreWhiteStudent = 1;
const int scoreBlackMaster = -10;
const int scoreBlackStudent = -1;

/**
 * Štruktúra kartičky doslova kopírujúca zadanie úlohy:
 * 4 dvojice súradníc, ktoré definujú deltu od úvodnej pozície
 *
 * Teda napr. aplikovanie dx1=-1 a dx2=2 na pozíciu [2,1] má
 * vo výsledku [1,3]
 */
struct Card {
    int id;
    int dx1, dy1, dx2, dy2;
    int dx3, dy3, dx4, dy4;
};

struct Move {
    Card card;
    int x1, y1, x2, y2;
};

/**
 * Jednoduché otočenie kartičky podľa stredu
 *
 * @param card kartička na otočenie
 * @return nová otočená kartička
 */
Card rotatedCard(Card card) {
    return Card {
        card.id,
        -card.dx1, -card.dy1, -card.dx2, -card.dy2,
        -card.dx3, -card.dy3, -card.dx4, -card.dy4
    };
}


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
