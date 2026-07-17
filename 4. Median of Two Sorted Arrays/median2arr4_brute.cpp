class Solution {
public:
    //Brtue Force Approach
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vec;
        for(int x:nums1) vec.push_back(x);
        for(int x:nums2) vec.push_back(x);
        int n=vec.size();
        sort(vec.begin(),vec.end());
        if(n%2==1) return vec[n/2];
        return (vec[n/2]+vec[n/2-1])/2.0;
    }
};
