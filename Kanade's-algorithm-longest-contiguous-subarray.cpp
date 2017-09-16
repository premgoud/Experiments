// Given an array containing both negative and positive integers. 
// Find the contiguous sub-array with maximum sum.
#include<iostream>
using namespace std;

int main() {
  int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n = sizeof(a)/sizeof(a[0]);

  int curr, start, end;

  int max_so_far = a[0];
  int max_ending_here = a[0];
  for (int i=1; i<n; i++) {
    if (a[i] > max_ending_here+a[i]) {
      curr = i;
    }
    max_ending_here = max(a[i], max_ending_here+a[i]);
    if (max_ending_here > max_so_far) {
      max_so_far = max_ending_here;
      start = curr;
      end = i;
    }
  }

  cout << "Starting: " << start << ", Ending: " << end << endl;
  cout << "Max sum: " << max_so_far << endl;
  return 0;
}