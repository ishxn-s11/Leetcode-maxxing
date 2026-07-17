class Solution {
public:
    //Optimal Approach
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size();
        int m=nums2.size();
        int low=0,high=n;
        while(low<=high){
            int i=(low+high)/2;
            int j=(n+m+1)/2-i;
            int l1=(i==0)?INT_MIN:nums1[i-1];
            int r1=(i==n)?INT_MAX:nums1[i];
            int l2=(j==0)?INT_MIN:nums2[j-1];
            int r2=(j==m)?INT_MAX:nums2[j];
            //Checking The Condition For Partition
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
                else return max(l1,l2);
            }
            //Adjusting The Binary Search
            else if(l1>r2) high=i-1;
            else low=i+1;
        }
        return 0.0;
    }
};
