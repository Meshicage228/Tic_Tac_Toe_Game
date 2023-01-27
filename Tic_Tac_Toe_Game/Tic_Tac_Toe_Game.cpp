#include <iostream>
using namespace std;
char board[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
const char PLAYER = 'X';
const char COMPUTER = '0';
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkwinner();
void printWinner(char);

int main()
{
    setlocale(0, "rus");
    char winner = ' ';
    resetBoard();
    while (winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();
        playerMove();
        winner = checkwinner();
        if (winner != ' ' || !checkFreeSpaces()) break;

        computerMove();
        winner = checkwinner();
        if (winner != ' ' || !checkFreeSpaces()) break;
    }
    printBoard();
    printWinner(winner);
    return 0;
}
void resetBoard() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard() {
    printf(" \t %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n\t---|---|---\n");
    printf("\t %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n\t---|---|---\n");
    printf("\t %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpaces() {
    int space = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                space--;
            }
        }
    }
    return space;
}
void playerMove() {
    int x;
    int y;
    do {
        cout << "Введите координату x 1-3: ";
        cin >> x;
        x--;
        cout << "Введите координату y 1-3: ";
        cin >> y;
        y--;
        if (board[x][y] != ' ')
        {
            cout << "Неверный ход! Попробуйте еще раз!\n";
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}
void computerMove() {
    srand(time(0));
    int x;
    int y;
    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}
char checkwinner() {
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}
void printWinner(char win) {
    if (win == PLAYER)
    {
        cout << "Победа!! ";
    }
    else if (win == COMPUTER)
    {
        cout << "Поражение!!";
    }
    else
    {
        cout << "Ничья!!";
    }
}