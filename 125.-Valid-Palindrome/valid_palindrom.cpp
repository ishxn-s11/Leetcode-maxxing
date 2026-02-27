class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        vector<char>v;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])) v.push_back(tolower(s[i]));
        }
        int st=0;
        int en=v.size()-1;
        while(st<en){
            if(v[st]!=v[en]) return false;
            st++;
            en--;
        }
    return true;
    }
};