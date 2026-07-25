#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int longestcommonsubsequenc(vector<int>&arr1,vector<int>&arr2,int n,int m){
    if(n==0 || m==0) return 0;
    if(arr1[n-1]==arr2[m-1]){
        return 1+longestcommonsubsequenc(arr1,arr2,n-1,m-1);
    }else{
        return max(longestcommonsubsequenc(arr1,arr2,n-1,m),longestcommonsubsequenc(arr1,arr2,n,m-1));
    }
}

int longestcommonsubsequencememo(vector<int>&arr1,vector<int>&arr2,int n,int m,vector<vector<int>>&dp){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(arr1[n-1]==arr2[m-1]){
        dp[n][m] = 1+longestcommonsubsequencememo(arr1,arr2,n-1,m-1,dp);
    }else{
        dp[n][m]= max(longestcommonsubsequencememo(arr1,arr2,n-1,m,dp),longestcommonsubsequencememo(arr1,arr2,n,m-1,dp));
    }
    return dp[n][m];
}
int longestcommonsubsequence(vector<int>&arr1,vector<int>&arr2){
    vector<vector<int>>dp(arr1.size()+1,vector<int>(arr2.size()+1,0));
    int n=arr1.size(),m=arr2.size();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr1[i-1]==arr2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    vector<int>arr1 = {50,3,10,7,40,80};
    unordered_set<int>s(arr1.begin(),arr1.end());
    vector<int>arr2(s.begin(),s.end());
    sort(arr2.begin(),arr2.end());
    // vector<vector<int>>dp(arr1.size()+1,vector<int>(arr2.size()+1,-1));
    cout<<longestcommonsubsequence(arr1,arr2);
}