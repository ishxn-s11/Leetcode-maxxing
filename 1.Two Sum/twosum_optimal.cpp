class Solution {
public:
//Optimal Approach
    vector<int>twoSum(vector<int>&nums,int target) {
        int l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum>target) r--;
            else if(sum<target) l++;
            else return {l,r};
        }
        return {-1};
    }
};