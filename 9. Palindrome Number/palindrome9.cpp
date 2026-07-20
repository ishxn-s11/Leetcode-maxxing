class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp=x;
        long rev,rem;
        while(temp>0){
            rem=temp%10;
            rev=(rev*10)+rem;
            temp/=10;
        }
        if(rev==x)return true;
        return false;
    }
};
