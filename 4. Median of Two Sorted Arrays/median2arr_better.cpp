class Solution {
public:
    //Better Approach
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int median=(n+m)/2;
        int i=0,j=0,c=0;
        int prev=0,curr=0; //Tracks Last Two Elements During Merging
        while(c<=median){
            prev=curr;
            //Choosing Smaller Element For Merging And Updating curr With It
            if(i<n && (j>=m || nums1[i]<nums2[j])) curr=nums1[i++];
            else curr=nums2[j++];
            c++;
        }
        if((n+m)%2==1) return curr;
        return (prev+curr)/2.0;
    }
};
