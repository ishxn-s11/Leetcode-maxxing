/*
Sliding Window
Initialise l=0,r=0,freq[3]={0},ans=0
Expand r
Check For Valid Substring
While Valid{
    ans+=(n-r);
    Shrink l
}

Time Complexity: O(n)

*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int freq[3]={0};
        int l=0,ans=0;
        for(int r=0;r<n;r++){
            freq[s[r]-'a']++;
            while(freq[0]&&freq[1]&&freq[2]){
                ans+=(n-r);
                freq[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};
