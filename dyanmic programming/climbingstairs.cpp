#include <iostream>
#include <vector>

using namespace std;

int ways(int n) {
    if (n == 0 || n == 1) return 1;
    return ways(n - 1) + ways(n - 2);
}

int climbvar(int n, vector<int>& dp) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    if (dp[n] != -1) return dp[n];

    dp[n] = climbvar(n - 1, dp) + climbvar(n - 2, dp) + climbvar(n - 3, dp);
    return dp[n];
}

int main() {
    // cout << ways(5) << endl;
    vector<int> dp(6, -1);
    // dp[0] = 1, dp[1] = 1, dp[2] = 1;
    cout << climbvar(4, dp) << endl;

    return 0;
}