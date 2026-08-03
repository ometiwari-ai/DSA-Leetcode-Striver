#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Insertion Sort Implementation
 * 
 * Time Complexity: 
 *   - Worst/Average Case: O(N^2) when elements are in reverse order.
 *   - Best Case: O(N) when the input array is already or nearly sorted.
 * Space Complexity: O(1) Auxiliary (In-place sorting).
 * Practice Link:https://read.learnyard.com/dsa/insertion-sort-algorithm/ 
 */
void insertionSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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

  insertionSort(arr);

  for (int x : arr) {
    cout << x << " ";
  }

  return 0;
}
