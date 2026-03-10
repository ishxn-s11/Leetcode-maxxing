class Solution {
public:
    //Optimal Approach
    //Two-Pointer
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        for(int i=0;i<nums.size();i++) nums[i]*=nums[i];
        int l=0,r=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[l]>nums[r]){
                res[i]=nums[l];
                l++;
            }else{
                res[i]=nums[r];
                r--;
            }
        }
        return res;
    }
};
