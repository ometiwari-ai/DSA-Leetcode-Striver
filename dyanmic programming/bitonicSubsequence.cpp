#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LongestBitonicSequence(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> LIS_dp(n, 1);  

        int maxLen = 0;

        for(int i = 0; i < n; i++) {

            for(int prev = 0; prev < i; prev++) {
                
                /* If the element at index i can be
                 included in the LIS ending at prev index */
                if(arr[prev] < arr[i] && LIS_dp[i] < LIS_dp[prev] + 1) {
                    LIS_dp[i] = LIS_dp[prev] + 1; // Update the DP value
                }
            }
        }
    
        // LDS_dp[i] stores the length of LDS starting from index i
        vector<int> LDS_dp(n, 1);  
        

        for(int i = n-1; i >= 0; i--) {

            for(int prev = n-1; prev > i; prev--) {
                
                /* If the element at index i can be
                 included in the LIS ending at prev index */
                if(arr[prev] < arr[i] && LDS_dp[i] < LDS_dp[prev] + 1) {
                    LDS_dp[i] = LDS_dp[prev] + 1; // Update the DP value
                }
            }
            
            // Update the maximum possible length of Longest Bitonic Sequence
            maxLen = max(maxLen, LIS_dp[i] + LDS_dp[i] - 1);
        }
        
        return maxLen;
    }
};


int main() {
    vector<int> arr = {5, 1, 4, 2, 3, 6, 8, 7};
    
    Solution sol;
    
    int lengthOfLongestBitonicSequence = sol.LongestBitonicSequence(arr);
    
    cout << "The length of the Longest Bitonic Sequence is: " << lengthOfLongestBitonicSequence << endl;
    
    return 0;
}