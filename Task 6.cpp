#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int count = 0;
int* dynamic = nullptr;

void TowersOfHanoi(int n, int r, char at, char to, char arr)
{
    if (n > 0) {
        count++;
        TowersOfHanoi(n - 1, r, at, arr, to);
        cout << "Move disk " << n + r << " at rod " << at << " to rod " << to << endl;
        TowersOfHanoi(n - 1, r, arr, to, at);
    }
}
void TowersOfHanoi_using_4pegs(int n, char  at, char to, char arr, char arr2)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        count++;
        cout << "Move disk 1 at rod " << at << " to rod " << to << endl;
        return;
    }

    TowersOfHanoi_using_4pegs(n - 2, at, arr, arr2, to);

    count += 3;

    cout << "Move disk " << n - 1 << " at rod " << at << " to rod " << arr2 << endl;
    cout << "Move disk " << n << " at rod " << at << " to rod " << to << endl;
    cout << "Move disk " << n - 1 << " at rod " << arr2 << " to rod " << to << endl;

    TowersOfHanoi_using_4pegs(n - 2, arr, to, at, arr2);

}
void OptimumSolutionPuzzle(int n, char at, char to, char arr, char arr2) // OPTIMUM SOLUTION
{
    int k = n - floor(sqrt(2 * n) + 0.5);
    cout << "-> A has " << n << " pegs" << endl;
    cout << "-> B is our destination" << endl << endl;
    TowersOfHanoi_using_4pegs(k, at, arr2, to, arr);
    TowersOfHanoi(n - k, k, at, to, arr);
    TowersOfHanoi_using_4pegs(k, arr2, to, at, arr);
    cout << endl;
    cout << "-> Total Amount of moves: " << count << endl;

}
void TowersOfHanoi_using_4pegs(int disc, int n, char at, char to, char arr, char arr2) {
    if (n == 0) {
        return;
    }
    if (n == 1)
    {
        cout << "Move disk 1 at rod " << at << " to rod " << to << endl;
        return;
    }
    TowersOfHanoi_using_4pegs(disc, n - 2, at, arr, arr2, to);


    if (dynamic == nullptr) {
        int x = (disc < 3) ? 3 : disc;
        dynamic = new int[x + 1];
        dynamic[0] = 0;
        dynamic[1] = 1;
        dynamic[2] = 3;
        dynamic[3] = 5;
    }

    if (n > 3)
    {
        dynamic[n] = (2 * (dynamic[n - 2])) + 3;
    }


    cout << "Move disk " << n - 1 << " at rod " << at << " to rod " << arr2 << endl;
    cout << "Move disk " << n << " at rod " << at << " to rod " << to << endl;
    cout << "Move disk " << n - 1 << " at rod " << arr2 << " to rod " << to << endl;

    TowersOfHanoi_using_4pegs(disc, n - 2, arr, to, at, arr2);

}
int main() {
    OptimumSolutionPuzzle(8, 'A', 'B', 'C', 'D');
    cout << endl << endl;
    TowersOfHanoi_using_4pegs(8, 8, 'A', 'B', 'C', 'D');
    cout << dynamic[8];
    free(dynamic);
}
