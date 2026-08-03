#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Selection Sort Implementation
 * 
 * Time Complexity: O(N^2) across Best, Average, and Worst cases.
 * Space Complexity: O(1) Auxiliary (In-place sorting).
 * Practice Link: https://www.codechef.com/learn/course/college-design-analysis-algorithms/CPDAA01/problems/DAA005
 */
void selectionSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      swap(arr[i], arr[min_idx]);
    }
  }
}

int main() {
  // int n;
  // cin >> n;

  // vector<int> arr(n);

  // for (int i = 0; i < n; i++) {
  //     cin >> arr[i];
  // }

  vector<int> arr = {3, 2, 8, 5, 1, 4, 23};

  selectionSort(arr);

  for (int x : arr) {
    cout << x << " ";
  }

  return 0;
}
