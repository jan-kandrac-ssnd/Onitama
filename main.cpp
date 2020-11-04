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

// helper procedure for getPossibleMoves
void resolveMove(vector<Move>* moves, Card card, int dx, int dy, int x, int y) {
    if (!(dx == 0 && dy == 0)) {
        int newX = x + dx;
        int newY = y + dy;
        if (newX >= 0 && newX < boardWidth && newY >= 0 && newY < boardHeight) {
            moves->push_back(Move{card, x, y, newX, newY});
        }
    }
}

void getPossibleMoves(vector<Move>* moves, Card card, int x, int y) {
    resolveMove(moves, card, card.dx1, card.dy1, x, y);
    resolveMove(moves, card, card.dx2, card.dy2, x, y);
    resolveMove(moves, card, card.dx3, card.dy3, x, y);
    resolveMove(moves, card, card.dx4, card.dy4, x, y);
}

vector<Move> getPossibleMoves(char board[boardWidth][boardHeight], Card card1, Card card2, int player) {
    vector<Move> moves(0);
    for(int row = 0; row < boardHeight; row++) {
        for(int column = 0; column < boardWidth; column++) {
            if (player == 0 && tolower(board[column][row]) == 'w') {
                getPossibleMoves(&moves, card1 ,column, row);
                getPossibleMoves(&moves, card2 ,column, row);
            } else if (player == 1 && tolower(board[column][row]) == 'b') {
                getPossibleMoves(&moves, card1 ,column, row);
                getPossibleMoves(&moves, card2 ,column, row);
            }
        }
    }
    return moves;
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

    return 0;
}
