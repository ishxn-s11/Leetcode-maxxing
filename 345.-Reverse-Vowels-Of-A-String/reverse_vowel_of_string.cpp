class Solution {
public:
    bool vowelfind(char ch){
        return (ch=='A'|| ch=='a'|| ch=='E'|| ch=='e'|| ch=='I'|| ch=='i'|| ch=='O'
            || ch=='o'|| ch=='U'|| ch=='u');
    }
    string reverseVowels(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(!vowelfind(s[i])) i++;
            else if(!vowelfind(s[j])) j--;
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
