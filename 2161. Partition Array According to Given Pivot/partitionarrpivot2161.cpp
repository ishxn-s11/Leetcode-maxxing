//Two Pointer
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int r=0,l=n-1;
        for(int i=0,j=n-1;i<n;++i,--j){
            if(nums[i]<pivot) ans[r++]=nums[i];
            if(nums[j]>pivot) ans[l--]=nums[j];
        }
        while(r<=l) ans[r++]=pivot;
        return ans;
    }
};
