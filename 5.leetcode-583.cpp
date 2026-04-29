#include<iostream>
using namespace std;
// Given two strings s1 and s2, return the minimum number 
// of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.
                    //AND//
/*  Given two strings s1 and s2. The task is to remove or insert the 
minimum number of characters from/in s1 to transform it into s2.
 It could be possible that the same character needs to be removed 
 from one point of s1 and inserted into another point.*/
class Solution {
public:
    int minDistance(string s1, string s2) {
       int m=s1.length();
       int n=s2.length();
       vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return (m+n-2*dp[m][n]);
    }
};

