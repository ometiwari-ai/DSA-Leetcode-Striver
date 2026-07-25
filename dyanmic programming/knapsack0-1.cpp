#include<iostream>
#include<vector>
using namespace std;
int knapsackmax(vector<int>&vals,vector<int>&wt,int n,int w){
    if(n==0 || w<=0) return 0;
    int itemwt = wt[n-1];
    int itemval = vals[n-1];
    if(itemwt<=w){// valid
        // include
        int ans1 = knapsackmax(vals,wt,n-1,w-itemwt) + itemval;
        //exclude
        int ans2 = knapsackmax(vals,wt,n-1,w);
        return max(ans1,ans2);
    }else{
        return knapsackmax(vals,wt,n-1,w);
    }
}
int knapsackmemo(vector<int>&vals,vector<int>&wt,int n,int w,vector<vector<int>>&dp){
    if(n==0 || w<=0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    int itemwt = wt[n-1];
    int itemval = vals[n-1];
    if(itemwt<=w){// valid
        // include
        int ans1 = knapsackmemo(vals,wt,n-1,w-itemwt,dp) + itemval;
        
        //exclude
        int ans2 = knapsackmemo(vals,wt,n-1,w,dp);
        dp[n][w] = max(ans1,ans2);
        return dp[n][w];
    }else{
        dp[n][w]= knapsackmemo(vals,wt,n-1,w,dp);
        return dp[n][w];
    }
}

int knapsacktab(vector<int>&vals,vector<int>&wt,int n,int w){
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1; i<n+1; i++){
        int itemval = vals[i-1],itemwt = wt[i-1];
        for(int j=1; j<w+1; j++){
            if(itemwt<=j){
                dp[i][j] = max(dp[i-1][j-itemwt]+itemval,dp[i-1][j]);
            }else dp[i][j] = dp[i-1][j-1];
        }
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][w];

}
int main(){
    vector<int>vals={15,14,10,45,30};
    vector<int>wt = {2,5,1,3,4};
    int n=vals.size();
    int w=7;
    // vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    // cout<<knapsackmemo(vals,amount,5,7,dp);
    cout<<knapsacktab(vals,wt,n,w);
    // cout<<"dp matrix: "<<endl;
    // for(int i=0; i<n; i++){
    //     for(int x:dp[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
}