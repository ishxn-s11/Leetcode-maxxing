class Solution {
public:
//Better Approach
//Hashing
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            set<int>hash;
            for(int j=i+1;j<nums.size();j++){
                int k=-(nums[i]+nums[j]);
                if(hash.find(k)!=hash.end()){
                    vector<int>temp={nums[i],nums[j],k};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                hash.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};