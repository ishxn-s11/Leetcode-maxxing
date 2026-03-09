class Solution {
public:
    //Better Approach
    //Two Pointer
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        auto expand=[&](int l,int r){
            while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
            }
            return s.substr(l+1,r-l-1);
        };
        string max_str=s.substr(0,1);
        for(int i=0;i<s.size()-1;i++){
            string odd=expand(i,i);
            string even=expand(i,i+1);
            if(odd.size()>max_str.size()) max_str=odd;
            if(even.size()>max_str.size()) max_str=even;
        }
        return max_str;
    }
};
