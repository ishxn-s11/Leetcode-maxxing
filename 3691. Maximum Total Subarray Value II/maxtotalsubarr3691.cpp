class SegTree{
    vector<int>minvec,maxvec;
    int n;
    public:
        SegTree(vector<int>&nums){
            n=nums.size();
            maxvec.resize(n*4);
            minvec.resize(n*4);
            build(1,0,n-1,nums);
        }
        void build(int node,int l,int r,vector<int>&nums){
            if(l==r){
                maxvec[node]=minvec[node]=nums[l];
                return;
            }
            int mid=(l+r)/2;
            build(node*2,l,mid,nums);
            build(node*2+1,mid+1,r,nums);
            maxvec[node]=max(maxvec[node*2],maxvec[node*2+1]);
            minvec[node]=min(minvec[node*2],minvec[node*2+1]);
        }
        int max_query(int node,int l,int r,int ql,int qr){
            if(ql<=l && r<=qr) return maxvec[node];
            int mid=(l+r)/2;
            int res=INT_MIN;
            if(ql<=mid) res=max(res,max_query(node*2,l,mid,ql,qr));
            if(qr>mid) res=max(res,max_query(node*2+1,mid+1,r,ql,qr));
            return res;
        }
        int min_query(int node,int l,int r,int ql,int qr){
            if(ql<=l && r<=qr) return minvec[node];
            int mid=(l+r)/2;
            int res=INT_MAX;
            if(ql<=mid) res=min(res,min_query(node*2,l,mid,ql,qr));
            if(qr>mid) res=min(res,min_query(node*2+1,mid+1,r,ql,qr));
            return res;
        }
};
class Solution {
    public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        SegTree sgt(nums);
        priority_queue<tuple<int,int,int>>pq;
        for(int i=0;i<n;i++){
            pq.emplace(sgt.max_query(1,0,n-1,i,n-1)-sgt.min_query(1,0,n-1,i,n-1),i,n-1);
        }
        long long ans=0;
        while(k--){
            auto [val,l,r]=pq.top();
            pq.pop();
            ans+=val;
            if(r>l){
                pq.emplace(sgt.max_query(1,0,n-1,l,r-1)-sgt.min_query(1,0,n-1,l,r-1),l,r-1);
            }
        }
        return ans;
    }
};
