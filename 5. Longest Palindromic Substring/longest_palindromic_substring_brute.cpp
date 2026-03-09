class Solution {
public:
    bool ispalindrome(string str){
        int l=0,r=str.size()-1;
        while(l<r){
            if(str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int maxlen=1;
        string max_str=s.substr(0,1);
        for(int i=0;i<s.size();i++){
            for(int j=i+maxlen;j<=s.size();j++){
                if(j-i>maxlen && ispalindrome(s.substr(i,j-i))){
                    maxlen=j-i;
                    max_str=s.substr(i,j-i);
                }
            }
        }
        return max_str;
    }
};
