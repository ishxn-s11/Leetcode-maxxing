/*
    Not The Optimal One But Works 
    Backtracking/DFS
    Generating Binary String Bit By Bit
*/

class Solution {
public:
    string ans;
    unordered_set<string>st;
    int n;
    bool dfs(string s){
        if(s.size()==n){  //Base Case
            if(st.count(s)==0){ //Checks If The String Doesn't Exists In The Set
                ans=s;
                return true;
            }
            return false;
        }
        if(dfs(s+"0")) return true;
        if(dfs(s+"1")) return true;
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();
        st=unordered_set<string>(nums.begin(),nums.end());
        dfs("");
        return ans;
    }
};
