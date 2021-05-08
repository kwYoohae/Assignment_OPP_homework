#include <iostream>

using namespace std;

char moveM(char M[][5], char temp[][5] , int moveX , int moveY) {
    char move;
    char end = 'END';
    cout << "Command :";
    cin >> move;

    M[0][0] = 'a';
    if (move == 'a') {
        moveY--;
        if (moveX < 0 || M[moveX][moveY] == 'a') {
            cout << "end";
            return 0;
        }
    }
    else if (move == 'w') {
        moveX--;
        if (moveY < 0 || M[moveX][moveY] == 'a') {
            cout << "end";
            return 0;
        }
    }
    else if (move == 'd') {
        moveY++;
        if (moveX > 4 || M[moveX][moveY] == 'a') {
            cout << "end";
            return 0;
        }
    }
    else if (move == 's') {
        moveX++;
        if (moveX > 4 || M[moveX][moveY] == 'a') {
            cout << "end";
            return 0;
        }
    }
    else {
        cout << "ERROR!";
        return moveM(M,temp,moveX,moveY);
    }

    M[moveX][moveY] = 'a';
}

int main() {
    char M[5][5] = { {} };
    char temp[5][5] = { {} };
    int moveX = 0;
    int moveY = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            M[i][j] = '0';
        }
    }


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << M[i][j];
        }
        cout << endl;
    }

    while (1) {
        moveM(M,temp,moveX,moveY);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << M[i][j];
            }
            cout << endl;
        }
    }


}