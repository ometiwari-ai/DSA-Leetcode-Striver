#include<iostream>
#include<vector>
using namespace std;
int napsack(vector<int>&val,vector<int>&wt,vector<vector<int>>&dp,int n,int W){
    if(W==0 || n==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(W-wt[n-1]>=0){
        dp[n][W] = max(napsack(val,wt,dp,n,W-wt[n-1])+val[n-1],napsack(val,wt,dp,n-1,W));
        return dp[n][W];
    }else dp[n][W]=napsack(val,wt,dp,n-1,W);
    return dp[n][W];
}
int main(){
    vector<int>val = {15,14,10,45,30};
    vector<int>wt = {2,5,1,3,4};
    int n = val.size(),W=7;
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    cout<<napsack(val,wt,dp,n,W);
}