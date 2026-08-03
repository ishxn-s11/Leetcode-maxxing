/*
Frequency Counting 

Count The Frequency Once
Then Compute min(b,a,l/2,o/2,n)

Time Complexity:O(n)
Space Complexity:O(1) -> 26 Letters 
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);
        for(char i:text) freq[i-'a']++;
        return min({freq['b'-'a'],
        freq['a'-'a'],
        freq['l'-'a']/2,
        freq['o'-'a']/2,
        freq['n'-'a']
        });
    }
};
