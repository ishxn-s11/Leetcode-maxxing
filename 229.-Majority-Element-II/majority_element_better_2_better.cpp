class Solution {
public:
//Better Approach
    vector<int> majorityElement(vector<int>& nums){
        int lmax=(nums.size()/3)+1;
        vector<int>l;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]==lmax) l.push_back(nums[i]);
        }
        return l;
    }
};