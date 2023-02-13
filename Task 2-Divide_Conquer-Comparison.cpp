#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> // hashtable using c++
using namespace std;

bool One_Peg(int arr[], int n){
    int constant = 0;
    for (int i = 0; i < n && constant < 2; i++) if (arr[i] == 1)  constant++;
    return (constant == 1);
}

vector<int*> Move(int arr[], int n){ // [ [0, 2], [2, 4] ] => [1, 1, 0, 1, 1]
    vector<int*> x;
    for(int i = 0; i < n - 2; i++){
        if(arr[i] == 1 - arr[i + 2] && arr[i + 1] == 1) 
            x.push_back(new int[2]{i, i+2});
    }
    return x;
}

int* move(int arr[], int n, int solit, int erre){
    int* new_arr = new int[n];
    for (int i = 0; i < n; i++){
        if(i >= solit && i <= erre) new_arr[i] = 1 - arr[i];
        else new_arr[i] = arr[i];
    }
    return new_arr;
}

int* PegSolitaire(int arr[], int n){ 
    //case 1: check if arr has 1 peg only and res is 0 
    if (One_Peg(arr, n) == true){
        return arr; 
    }
    //case 2: check if there is available moves using pegs
    if (Move(arr, n).size() == 0){ // && One_Peg(arr) == false
        int* arr =  new int[1]{-1}; 
        return arr;
    }


    //recursive case 2^n [1, 1, 0, 1, 1, 1, 1]
    int solit, erre;
    vector<int*> move_availabe;
    move_availabe = Move(arr, n); // [ [0, 1], [2, 4] ]
    // vector<int> 
    for (int i = 0; i < move_availabe.size(); i++){
        //update move
        solit = move_availabe[i][0];
        erre = move_availabe[i][1];
        int* new_arr = move(arr, n, solit, erre);
        int *output = PegSolitaire(new_arr, n);
        if (output[0] == -1){  // or [-1]
            continue;
        }
        else{
            return output;
        }
    }
    int* result_bad =  new int[1]{-1}; //[-1]
    return result_bad; 
}

int main(){
    int arr[10] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}; //1, 4, 5, 8
    int* output = PegSolitaire(arr, 10);
    if (output[0] == -1){
        cout << "Not existing " << endl;
    }
    else{
        for (int i = 0; i < 10; i++){
            cout << output[i] << ' ';
        }
    }
    
}