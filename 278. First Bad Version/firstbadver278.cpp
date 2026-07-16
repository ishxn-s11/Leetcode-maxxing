// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    //Binary Search 
    int firstBadVersion(int n) {
        int l=0,r=n;
        int res=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            //Moves mid To Get Bad Version
            if(isBadVersion(mid)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    } 
};
