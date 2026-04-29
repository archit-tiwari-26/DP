// //Given two sequences, find the length of longest subsequence present in both of them.
// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
// For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.

//recursive + memoization
#include<iostream>
using namespace std;
int main()
{
    
    return 0;
}
class Solution {
  public:
  int solve( string & s1, string & s2, int n, int m , vector<vector<int>>& dp){
      if(m==0 || n==0)return 0;
      if(dp[n][m]!=-1)return dp[n][m];
      if(s1[n-1]==s2[m-1]){
         return dp[n][m]= 1+ solve(s1,s2,n-1,m-1, dp);
      }
      else{
         return dp[n][m]=max(solve(s1,s2,n-1,m,dp), solve(s1,s2,n,m-1,dp)); 
      }
  }
    int lcs(string &s1, string &s2) {
      int n= s1.length();
      int m= s2.length();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return solve(s1,s2,n,m,dp);
        
    }
};


// tabulation

class Solution {
public:

   
    int longestCommonSubsequence(string s1, string s2) {
        int n= s1.length();
      int m= s2.length();
      vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
      }
      return dp[n][m];
    }
};
