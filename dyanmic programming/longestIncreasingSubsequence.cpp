#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-Down)
    // tc - O(N^2)  sc - O(N^2) + O(N) recursion stack space
    int lisUtil(vector<int>& nums, int ind, int prev_ind, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return 0;

        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int notTake = 0 + lisUtil(nums, ind + 1, prev_ind, dp);

        int take = 0;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            take = 1 + lisUtil(nums, ind + 1, ind, dp);
        }

        return dp[ind][prev_ind + 1] = max(notTake, take);
    }

    int lisMemo(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return lisUtil(nums, 0, -1, dp);
    }

    // 2. Tabulation (Bottom-Up)
    // tc - O(N^2)  sc - O(N^2)
    int lisTabulation(vector<int>& nums) {
        int n = nums.size();
        // dp table of size (n + 1) x (n + 1), initialized to 0
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int notTake = 0 + dp[ind + 1][prev_ind + 1];
                int take = 0;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    take = 1 + dp[ind + 1][ind + 1];
                }
                dp[ind][prev_ind + 1] = max(notTake, take);
            }
        }
        return dp[0][0];
    }

    // 3. Space Optimization (2-Row Approach / 1D DP)
    // tc - O(N^2)  sc - O(N)
    int lisSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextRow(n + 1, 0), curRow(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int notTake = 0 + nextRow[prev_ind + 1];
                int take = 0;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    take = 1 + nextRow[ind + 1];
                }
                curRow[prev_ind + 1] = max(notTake, take);
            }
            nextRow = curRow;
        }
        return nextRow[0];
    }

    // 4. Binary Search Approach (Patience Sorting)
    // tc - O(N log N)  sc - O(N)
    int lisBinarySearch(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> temp;
        temp.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                // Find position of element >= nums[i] and replace it
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return temp.size();
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution obj;

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\n\n";

    cout << "1. Memoization (Top-Down): " 
         << obj.lisMemo(nums) << endl;

    cout << "2. Tabulation (Bottom-Up): " 
         << obj.lisTabulation(nums) << endl;

    cout << "3. Space Optimization: " 
         << obj.lisSpaceOptimized(nums) << endl;

    cout << "4. Binary Search (O(N log N)): " 
         << obj.lisBinarySearch(nums) << endl;

    return 0;
}
