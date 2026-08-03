#include <bits/stdc++.h>
using namespace std;


/** 
 * @brief Bubble Sort Implementation
 * 
 * Time Complexity: 
 *   - Worst/Average Case: O(N^2) due to nested loops scanning all pairs.
 *   - Best Case: O(N) when optimized with an 'swapped' flag on an already sorted array.
 * Space Complexity: O(1) Auxiliary (In-place sorting).
 * Practice Problem: https://www.geeksforgeeks.org/problems/bubble-sort/1
*/
void bubbleSort(vector<int> &arr) {
  int n = arr.size();
  bool swapped;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
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

  bubbleSort(arr);

  for (int x : arr) {
    cout << x << " ";
  }

  return 0;
}
