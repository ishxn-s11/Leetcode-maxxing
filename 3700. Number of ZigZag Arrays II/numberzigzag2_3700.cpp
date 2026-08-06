//From Yesterday's Solution

typedef long long ll;

class Solution {
public:
    static constexpr ll MOD=1e9+7;
    int zigZagArrays(int n, int l, int r) {
        ll m=r-l+1;
        if(n==1) return (m%MOD);
        vector<ll>up(m+1,0);
        vector<ll>down(m+1,0);
        for(int i=1;i<=m;i++){
            up[i]=i-1;
            down[i]=m-i;
        }
        for(int i=3;i<=n;i++){
            vector<ll>new_up(m+1,0);
            vector<ll>new_down(m+1,0);
            ll pfx=0;
            for(int j=1;j<=m;j++){
                new_up[j]=pfx;
                pfx=(pfx+down[j])%MOD;
            }
            ll sfx=0;
            for(int j=m;j>=1;j--){
                new_down[j]=sfx;
                sfx=(sfx+up[j])%MOD;
            }
            up=new_up;
            down=new_down;
        }
        ll ans=0;
        for(int i=1;i<=m;i++) ans=(ans+up[i]+down[i])%MOD;
        return ans;
    }
};
