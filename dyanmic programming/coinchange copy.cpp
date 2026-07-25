#include<iostream>
#include<vector>
using namespace std;
int coinchange(vector<int>&coins,int amount,int n){
    vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
    for(int i=0; i<=n; i++){
        dp[i][0]=1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=amount; j++){
            if(j>=coins[i-1]){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0; i<=n; i++){
        for(int x:dp[i])
            cout<<x<<" ";
        cout<<endl;
    }
    return dp[n][amount];
}
int main(){
    vector<int>coins = {1,2,5};
    int amount=5,n=coins.size();
    cout<<coinchange(coins,amount,n)<<endl;
}