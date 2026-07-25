#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lcsubstr(string str1,string str2,int n,int m,int &ans){
    if(n==0 || m==0) return 0;
    int curr=0;
    if(str1[n-1]==str2[m-1]) {
        curr = lcsubstr(str1,str2,n-1,m-1,ans)+1;
        ans = max(ans,curr);
    }
    lcsubstr(str1,str2,n-1,m,ans);
    lcsubstr(str1,str2,n,m-1,ans);
    return curr;
}

int longestcommonsubstring(string &str1,string &str2){
    int ans=0;
    int n=str1.size(),m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1]==str2[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

int main(){
    string str1 = "abcde",str2="abgce";
    int ans=0;
    // cout<<lcsubstr(str1,str2,str1.size(),str2.size(),ans);
    cout<<longestcommonsubstring(str1,str2)<<endl;
    // cout<<ans<<endl;
}