class Solution {
public:
    //Better Approach
    //Memoization 
    int dp[1001][1001];
    bool palindromic(string &s,int l,int r){
        if(l>=r) return true;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]) return dp[l][r]=palindromic(s,l+1,r-1);
        return dp[l][r]=false;
    }
    string longestPalindrome(string s) {
        int maxlen=INT_MIN;
        int start=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(palindromic(s,i,j)){
                    if(j-i+1>maxlen){
                        start=i;
                        maxlen=j-i+1;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
