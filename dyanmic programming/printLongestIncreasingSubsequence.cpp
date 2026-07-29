#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to construct and return the Longest Increasing Subsequence
    // tc - O(N^2)  sc - O(N)
    vector<int> getLongestIncreasingSubsequence(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // dp[i] stores the length of LIS ending at index i
        vector<int> dp(n, 1);
        
        // hash[i] stores the previous index of element in LIS ending at index i
        vector<int> hash(n);

        int maxLen = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i; // Initialize parent pointer to self
            for (int prev_index = 0; prev_index < i; prev_index++) {
                if (nums[prev_index] < nums[i] && 1 + dp[prev_index] > dp[i]) {
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }

            // Track the maximum length and the index where LIS ends
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the LIS using the hash array
        vector<int> lis;
        lis.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            lis.push_back(nums[lastIndex]);
        }

        // Reverse to get the LIS in original order
        reverse(lis.begin(), lis.end());

        return lis;
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution obj;
    vector<int> lis = obj.getLongestIncreasingSubsequence(nums);

    cout << "Original Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\n\n";

    cout << "Length of Longest Increasing Subsequence: " << lis.size() << endl;
    cout << "Longest Increasing Subsequence elements: ";
    for (int x : lis) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
