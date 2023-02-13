// six_knights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int** invert(int** arr);
int** divide(int** arr, int count);


int main()
{
    int** board = new int*[4];

    for (int i = 0; i < 4; ++i)
    {
        board[i] = new int[3];
    }
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        board[0][i] = 1;
    }
    for (int i = 0; i < 3; i++) {
        board[3][i] = 2;
    }
    for (int i = 0; i < 4; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "\t";
        }
    }
    cout << endl;
    board = divide(board,0);
    for (int i = 0; i < 4; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] <<"\t";
        }
    }

}


int** divide(int** arr, int count) {   
    if (count == 2) {
        return arr;
    }
    count++;
    arr[1][2] = arr[0][0];
    arr[0][0] = 0;
    arr[2][0] = arr[1][2];
    arr[1][2] = 0;
    arr[1][2] = arr[3][1];
    arr[3][1] = 0;
    arr[0][0] = arr[1][2];
    arr[1][2] = 0;
    if (count == 1) {
        arr[1][0] = arr[0][2];
        arr[0][2] = 0;
        arr[3][1] = arr[1][0];
        arr[1][0] = 0;
    }

    for (int i = 0; i < 4; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
    }
    cout << endl;

    arr = invert(arr);
    divide(arr, count);

    for (int i = 0; i < 4; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
    }
    cout << endl;

    if (count != 1) {
        return arr;
    }
    arr[0][2] = arr[1][0];
    arr[1][0] = 0;
    arr[1][2] = arr[2][0];
    arr[2][0] = 0;
    arr[2][0] = arr[3][2];
    arr[3][2] = 0;
    arr[0][1] = arr[2][0];
    arr[2][0] = 0;
    arr[2][0] = arr[1][2];
    arr[1][2] = 0;
    arr[3][2] = arr[2][0];
    arr[2][0] = 0;
    return arr;
}

int** invert(int** arr) {
    for (int i = 0; i < 3; i++) {
        int t = arr[0][i];
        arr[0][i] = arr[3][i];
        arr[3][i] = t;
        int s = arr[1][i];
        arr[1][i] = arr[2][i];
        arr[2][i] = s;
    }
    return arr;
}