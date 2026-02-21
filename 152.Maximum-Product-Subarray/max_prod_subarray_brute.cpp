class Solution {
public:
    int maxProduct(vector<int>& nums){
        int prod=0;
        int mult=1,n=nums.size();
        for(int i=0;i<n;i++){
            mult*=nums[i];
            if(mult>prod) prod=mult;
            if(mult<1) mult=1;
        }
        return prod;
        
    }
};