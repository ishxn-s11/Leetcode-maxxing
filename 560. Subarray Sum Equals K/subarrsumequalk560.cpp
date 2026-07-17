class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=1;
        int total=0,c=0;
        for(int n:nums){
            total+=n;
            if(m.find(total-k)!=m.end()) c+=m[total-k];
            m[total]++;
        }
        return c;   
    }
};
