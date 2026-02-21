class Solution {
public:
//Optimal Approach 
//Kadane's Algorithm
    int maxProduct(vector<int>& nums){
        int prod=nums[0],minmult=nums[0],maxmult=nums[0],key=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(maxmult,minmult);
            maxmult=max(nums[i],maxmult*nums[i]);
            minmult=min(nums[i],minmult*nums[i]);
            key=max(key,maxmult);
        }
        return key;
        
    }
};