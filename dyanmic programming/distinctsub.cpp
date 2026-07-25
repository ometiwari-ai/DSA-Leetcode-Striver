#include <bits/stdc++.h>
using namespace std;
int distinctsub(int i,int j,string&s1,string &s2){
  if(i<0 || j<0) return 0;
  if(j==0 && s1[i]==s2[j]) return 1;
  int nottake = distinctsub(i-1,j,s1,s2);
  int take =0;
  if(s1[i]==s2[j]) take = distinctsub(i-1,j-1,s1,s2)+distinctsub(i-1,j,s1,s2);
  return take+nottake; 
}
int main(){
  string s1 = "babgbag",s2="bag";
  cout<<distinctsub(6,2,s1,s2)<<endl;
}