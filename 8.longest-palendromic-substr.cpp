#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string t=s;
        
        reverse(t.begin(),t.end());
        int n=s.length();
        int ans=0;
        int endind;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>ans  && (i - dp[i][j] == n - j)){
                        ans=dp[i][j];
                        
                        endind=i;
                    }
                    
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return s.substr(endind-ans,ans);
      
    }
};
int main(){
    Solution s;
    string str="dfjajfarchittihcra";
    cout<<s.longestPalindrome(str)<<endl;
    return 0;
}

