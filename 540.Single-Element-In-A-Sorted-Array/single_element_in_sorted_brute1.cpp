class Solution {
public:
//Linear Search 
    int singleNonDuplicate(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            int n=nums[i],c=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==n)c++;
            }
            if(c==1) return n;
        }
        return -1;
    }
};