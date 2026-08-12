/*
Convert Array To +1/-1
Compute All Prefix Sums
Coordinate Compress All Prefix Sums
Initialise Fenwick Tree
Insert Prefix 0
For Every Prefix:
    Find Compressed Rank
    ans+=bit.query(rank-1)
    bit.update(rank,1)

Time Complexity: O(n*log(n)) 
*/
class Solution {
public:
    struct BIT{
        int n;
        vector<int>bit;
        BIT(int n): n(n),bit(n+1,0){}
        void update(int idx,int val){
            while(idx<=n){
                bit[idx]+=val;
                idx+=idx & (-idx);
            }
        }
        int query(int idx){
            int sum=0;
            while(idx>0){
                sum+=bit[idx];
                idx-=idx & (-idx);
            }
            return sum;
        }
    };
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>pfx(n+1,0);
        for(int i=0;i<n;i++) pfx[i+1]=pfx[i]+(nums[i]==target?1:-1);
        vector<int>vals=pfx;
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        BIT bit(vals.size());
        long long ans=0;
        for(int i:pfx){
            int rank=lower_bound(vals.begin(),vals.end(),i)-vals.begin()+1;
            ans+=bit.query(rank-1);
            bit.update(rank,1);
        }
        return ans;
    }
};
