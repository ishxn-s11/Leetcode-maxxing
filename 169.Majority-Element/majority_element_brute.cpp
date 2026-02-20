class Solution {
public:
//Brute Force Approach
    int majorityElement(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]==nums[i]) c++;
            }
            if(c>(nums.size()/2)) return nums[i];
        }
        return {-1};
    }
};