class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        //THese Methods Return Pointers So We're Converting Back
        long long min=*min_element(nums.begin(),nums.end());
        long long max=*max_element(nums.begin(),nums.end());
        return  (max-min)*k;  
    }
};
