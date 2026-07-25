#include<iostream>
#include<vector>
using namespace std;
int uniquep(vector<vector<int>>&dp,int m,int n){
    if(m==1 || n==1) return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    dp[m][n] = uniquep(dp,m,n-1)+uniquep(dp,m-1,n);
    return dp[m][n];
}
int uniquePaths(int m, int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    uniquep(dp,m,n);
    // for(int i=1; i<=m; i++){
    //     for(int j=1; j<=n; j++){
    //         if(i==1 && j==1)  continue;
    //         dp[i][j]=dp[i-1][j]+dp[i][j-1];
    //     }
    // }
    for(int i=0; i<=m; i++){
        for(int x:dp[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
}
int main(){
    cout<<endl<<uniquePaths(3,2)<<endl;
}