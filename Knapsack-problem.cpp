/* 
  Given weights and values of n items, 
  put these items in a knapsack of capacity W 
  to get the maximum total value in the knapsack.

  Also given an integer W which represents knapsack capacity, 
  find out the maximum value subset of val[] such that sum of 
  the weights of this subset is smaller than or equal to W. 
  You cannot break an item, either pick the complete item, 
  or don’t pick it (0-1 property).
*/

#include<iostream>
using namespace std;
int knapSack(int W, int wt[], int val[], int n) {
  int K[W+1][n+1];

  for (int i=0; i<=n; i++) {
    for (int w=0; w<=W; w++) {
      if (i==0 || w==0) {
        K[w][i] = 0;
      } else if (w >= wt[i-1]) {
        K[w][i] = max(K[w][i-1], K[w-wt[i-1]][i-1] + val[i-1]);
      } else {
        K[w][i] = K[w][i-1];
      }
      cout << K[w][i] << "\t";
    }
    cout << endl;
  }

  return K[W][n];
}

int main() {
  int val[] = {60, 100, 120};
  int wt[] = {1, 2, 3};
  int W = 5;
  int n = sizeof(val)/sizeof(val[0]);
  cout << knapSack(W, wt, val, n) << endl;
  return 0;
}