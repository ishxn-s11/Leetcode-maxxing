/*
For Every Distinct Number x Except 1
Initialise cur=x And len=0
while true{
    if(freq[cur]>=2){
        len+=2; <=Doubling The Length
        cur*cur; <=Squaring The Selecting Number
    }
    else if(freq[cur]==1){
        len+=1; //If The Number Doesn't Exist In nums
        break;
    }
    else{
        if(len>0) len--;
        break;
    }    
}

Time Complexity: O((Number Of Distinct Values)*log(log(Max Value Of The Subset)))
*/

typedef long long ll;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,int>freq;
        for(int i:nums) freq[i]++;
        int ans=1;
        //Edge Case=>1
        if(freq.count(1)){
            ans=freq[1];
            if(ans%2==0) ans--;
        }
        for(auto &[i,cnt]:freq){
            if(i==1) continue;
            ll cur=i;
            int len=0;
            while(true){
                if(!freq.count(cur)){
                    if(len>0) len--;
                    break;
                }
                if(freq[cur]>=2){
                    len+=2;
                    if(cur>1000000000LL/cur){
                        //Preventing Overflow
                        len--;
                        break;
                    }
                    cur*=cur;
                }else{
                    len++;
                    break;
                }
            }
            ans=max(ans,len);
        }
        return ans;
    }
};
