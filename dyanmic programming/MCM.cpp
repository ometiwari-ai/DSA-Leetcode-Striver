#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // APPROACH 1: Memoization (Top-Down)
    // tc:  O(N^3)
    // sc: O(N^2) + O(N)

    int matrixChainOrderMemo(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;
        for (int k = i; k < j; k++) {
            // Cost of multiplying resulting matrices (A[i..k] and A[k+1..j])
            int cost = arr[i - 1] * arr[k] * arr[j];
            
            // Recursive cost for left and right partitions
            int cost2 = matrixChainOrderMemo(arr, i, k, dp) + matrixChainOrderMemo(arr, k + 1, j, dp);
            
            int totcost = cost + cost2;

            mini = min(mini, totcost);
        }

        return dp[i][j] = mini;
    }

    // APPROACH 2: Tabulation (Bottom-Up)
    // tc:  O(N^3)
    // sc: O(N^2)

    int matrixChainOrderTabu(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        //base case
        for(int i=0; i<n; i++){
            dp[i][i] = 0;
        }

        for(int i = n-1; i>=1; i--){
            for(int j = i+1; j<n; j++){
                int mini = 1e9;
                for(int k = i; k<j; k++){
                    int cost = arr[i-1] * arr[k] * arr[j];
                    int cost2 = dp[i][k] + dp[k+1][j];
                    
                    int tot = cost + cost2;
                    mini = min(mini, tot);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30}; 
    int n = arr.size();

    // 2D DP table initialized to -1 for memoization
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "Minimum number of multiplications (Memoization): "
         << sol.matrixChainOrderMemo(arr, 1, n - 1, dp) << endl;

    cout << "Minimum number of multiplications (Tabulation): "
         << sol.matrixChainOrderTabu(arr) << endl;
         
    return 0;
}
