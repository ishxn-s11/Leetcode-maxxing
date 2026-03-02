class Solution {
public:
    //Brute Force Approach
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0,len=0;
        for(int i=0;i<nums.size();i++){
            int z=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==0) z++;
                if(z<=k){
                    len=j-i+1;
                    maxlen=max(len,maxlen);
                }
                else break;
            }
        }
        return maxlen;
    }
};