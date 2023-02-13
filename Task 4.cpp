#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
###############################################################################
#       The code of main problem by Greedy Algorithm "Task 4"                 #
###############################################################################
*/
void GreedyTask(int input)
{
  int counter = 0; // counter for the number of iterations
  cout << "the desired number is : " << input << endl;
  cout << "The distribution is: \n";
  if (input < 0)
  {
    cout << "please enter positive number to solve it" << endl;
    return;
  }
  if (input == 1)
  {
    cout << 1 << endl;
    return;
  }

  int n = log2(input) + 1; // number of boxes by an equation of boxes
  int arr[n] = {0};        // array of boxes initially with zeros
  arr[0] = input;          // store the input pennies in the first box

  for (int i = 0; i < n; i++)
  {
    while (arr[i] > 1)
    {                              // repeat if there is a pair in the box
      arr[i] = arr[i] - 2;         // decrease the number of pennies by a pair
      arr[i + 1] = arr[i + 1] + 1; // and store one more to the next one
      for (int j = 0; j < n; j++)
      { // for loop to print the updates of the boxes
        cout << arr[j];
        cout << "  ";
      }
      cout << "\n";
      counter++; // increase the counter by one after every iteration
      if (arr[i] <= 1)
      {
        break; // if there is no pairs then break and move to next box
      }
    }
  }
  cout << "Number of iterations = " << counter;
  cout << "\n \n";
}

/*
###############################################################################
#       The code of Comparison by Brute Foce Algorithm "Task 4"               #
###############################################################################
*/
vector<int> GreedyComparison(int n)
{
  vector<int> boxes;
  boxes.push_back(n);
  int position = 0;
  while (boxes[position] > 1)
  {
    if (boxes.size() == (position + 1))
      boxes.push_back(1);
    else
      boxes[position + 1]++;

    boxes[position] = boxes[position] - 2;

    if (boxes[position] < 2)
      position++;
  }
  return boxes;
}
/*
###############################################################################
#                        The code of print vecotr                             #
###############################################################################
*/
void printVector(vector<int> v1)
{
  cout << "[ ";
  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << " ";
  }
  cout << "]" << endl;
}

int main()
{

  cout << "Simulation of GreadyTask code " << endl;
  while (true)
  {
    cout << "please enter your input " << endl;
    int n;
    cin >> n;
    GreedyTask(n);
    cout << "if you want to continue the simulation enter 0 else -1 " << endl;
    int x;
    cin >> x;
    if (x == -1)
      break;
    if (x != -1 && x != 0)
    {
      cout << "please enter right number";
      break;
    }
  }

  cout << "Simulation of Gready code for comparison :) " << endl;
  vector<int> v;

  while (true)
  {
    cout << "please enter your input " << endl;
    int n;
    cin >> n;
    cout << "The Distribution is : " << endl;
    v = GreedyComparison(n);
    printVector(v);
    cout << "if you want to continue the simulation enter 0 else -1 " << endl;
    int x;
    cin >> x;
    if (x == -1)
      break;
    if (x != -1 && x != 0)
    {
      cout << "please enter right number";
      break;
    }
    }

  return 0;
}