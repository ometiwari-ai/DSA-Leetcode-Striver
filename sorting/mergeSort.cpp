#include <bits/stdc++.h>
using namespace std;



/**
 * @brief Merge Sort Implementation (Divide and Conquer)
 * 
 * Time Complexity: O(N log N) guaranteed across Best, Average, and Worst cases.
 * Space Complexity: O(N) Auxiliary space due to temporary sub-array creation.
 * Practice Link: https://leetcode.com/problems/merge-sorted-array/
 */
void merge(vector<int> &arr, int low, int mid, int high) {
  int i = low, j = mid + 1;
  vector<int> temp;

  while (i <= mid && j <= high) {
    if (arr[i] < arr[j])
      temp.push_back(arr[i++]);
    else
      temp.push_back(arr[j++]);
  }
  while (i <= mid)
    temp.push_back(arr[i++]);
  while (j <= high)
    temp.push_back(arr[j++]);

  for (int k = low; k <= high; k++) {
    arr[k] = temp[k - low];
  }
}

void mergeSort(vector<int> &arr, int low, int high) {
  if (low >= high)
    return;

  int mid = low + (high - low) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  merge(arr, low, mid, high);
}

int main() {
  int n;
  // cin >> n;

  // vector<int> arr(n);

  // for (int i = 0; i < n; i++) {
  //     cin >> arr[i];
  // }

  vector<int> arr = {3, 2, 8, 5, 1, 4, 23};

  mergeSort(arr, 0, arr.size() - 1);

  for (int x : arr) {
    cout << x << " ";
  }

  return 0;
}
