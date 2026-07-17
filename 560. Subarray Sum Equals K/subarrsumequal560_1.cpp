class Solution {
public:
    //Prefix Sum {key:value}-->{pre_sum,count}
    int subarraySum(vector<int>&nums,int k) {
        map<int,int>m;
        m[0]=1; //Holds The Occurence Of 0s As pre_sum
        int pre_sum=0,c=0;
        for(int i=0;i<nums.size();i++){
            pre_sum+=nums[i];
            c+=m[pre_sum-k]; //Increments Subarrays Count
            m[pre_sum]++; //Increments The Occurence
        }
        return c;
    }
};
