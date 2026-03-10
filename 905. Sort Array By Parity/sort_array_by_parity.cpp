class Solution {
public:
    //Two Pointers
    vector<int> sortArrayByParity(vector<int>& nums) {
        //Result Array
        vector<int>res(nums.size());
        int l=0,r=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                res[l]=nums[i];
                l++;
            }else{
                res[r]=nums[i];
                r--;
            }
        }
        return res;
    }
};
