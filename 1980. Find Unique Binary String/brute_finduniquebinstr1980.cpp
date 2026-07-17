/*
    Brute Force Approach:- Generation Of Every Possible Binary String And Comparing 
                           It With The Array. 
                           Time Complexity :O(n*2^n)
    Better Approach:-Cantor's Diagonal Arguement 

    Assume There Exists A Matrix (n x n) With Row Being The Bits Of The String 
    And Column Being The Length Of The String. On Traversing Diagonally, To What Bit 
    We Encounter, We Append The Opposite Bit In The Result String So That It Must     
    Differ At The Diagonal Position For Every String.
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        for(int i=0;i<nums.size();i++){
            if(nums[i][i]=='0') ans+='1';
            else ans+='0';
        }
        return ans;
    }
};
