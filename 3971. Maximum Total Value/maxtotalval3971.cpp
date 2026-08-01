/*
Here, Each Selection Takes The Next Term Of An Arithmetic Progression
We Can Use Greedy With Binary Search On Last Chosen Value 
Because Every Future Term Is Smaller Than Previous Terms In The Same Progression
And We Need Maximum Value
*/

typedef long long ll;

class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        const ll MOD=1e9+7;
        auto count=[&](ll x){ //Lambda Function To Count Valid Terms
            ll cnt=0;
            for(int i=0;i<value.size();i++){
                if(value[i]<x) continue;
                cnt+=(value[i]-x)/(ll)decay[i]+1;
            }
            return cnt;
        };
        ll totalpos=count(1);
        ll ans=0; //Maximum Value To Be Returned
        if(totalpos<=m){
            for(int i=0;i<value.size();i++){
                ll a=value[i];
                ll d=decay[i];
                ll k=(a-1)/d+1; //Terms Greater Than Threshold t
                ll last=a-(k-1)*d;
                __int128 sum=(__int128)k*(a+last)/2; //To Avoid Overflow __int128 Is Used
                ans=(ans+(ll)(sum%MOD))%MOD;
            }
            return (int)ans;
        }
        ll l=1,h=1e9;
        while(l<h){ //Binary Search
            ll mid=(l+h+1)/2;
            if(count(mid)>=m) l=mid;
            else h=mid-1;
        }
        ll t=l; //Threshold Value
        ll taken=0;
        for(int i=0;i<value.size();i++){
            ll a=value[i];
            ll d=decay[i];
            if(a<=t) continue; //Useless Terms 
                ll k=(a-(t+1))/d+1; //Terms Greater Than Threshold t
                taken+=k;
                ll last=a-(k-1)*d;
                __int128 sum=(__int128)k*(a+last)/2; //To Avoid Overflow __int128 Is Used
                ans=(ans+(ll)(sum%MOD))%MOD;
            }
        ll need=m-taken;
        ans=(ans+(need%MOD)*(t%MOD))%MOD;
        return (int)ans;
    }
};
