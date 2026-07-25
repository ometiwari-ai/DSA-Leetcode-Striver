#include<iostream>
#include<vector>
#include<string>
using namespace std;
// int lcsrecursion(string &str1,string &str2,int n,int m){
//     if(n==0 || m==0) return 0;
//     if(str1[n-1]==str2[m-1]){
//         return (1+lcsrecursion(str1,str2,n-1,m-1));
//     }else{
//         return max(lcsrecursion(str1,str2,n-1,m),lcsrecursion(str1,str2,n,m-1));
//     }
// }
int lcsrecursion(string str1,string str2){
    if(str1.size()==0 || str2.size()==0) return 0;
    int n = str1.size(),m=str2.size();
    if(str1[n-1]==str2[m-1]){
        return 1+lcsrecursion(str1.substr(0,n-1),str2.substr(0,m-1));
    }else{
        return max(lcsrecursion(str1.substr(0,n-1),str2),lcsrecursion(str1,str2.substr(0,m-1)));
    }
}
int lcsmemoization(string str1,string str2,vector<vector<int>>&dp){
    if(str1.size()==0 || str2.size()==0) return 0;
    int n=str1.size(),m = str2.size();
    if(dp[n][m]!=-1) return dp[n][m];
    if(str1[n-1]==str2[m-1]){
        dp[n][m] = 1+lcsmemoization(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }else{
        dp[n][m] = max(lcsmemoization(str1.substr(0,n-1),str2,dp),lcsmemoization(str1,str2.substr(0,m-1),dp));
    }
    return dp[n][m];
}

int lcstabulation(string str1,string str2){
    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));   
    int n = str1.size(),m=str2.size();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=0; i<=n; i++){
        for(auto x:dp[i])
        cout<<x<<" ";
        cout<<endl;
    }
    return dp[n][m];
}
int main(){
    string str1 = "abcd",str2 = "aceb",ans="";
    // cout<<lcsrecursion(str1,str2,str1.length(),str2.length())<<endl;
    // cout<<lcsrecursion(str1,str2)<<endl;
    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
    cout<<lcstabulation(str1,str2);
}