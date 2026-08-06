/*
Matrix Exponentiation With DP

Initialise m=r-l+1
Create 2*m States
Build Transition Matrix 
Build Initial Vector For Length 2 : up And down
Compute The Exponential Matrix: T^(n-2)
Multiply Inital Vector 
Sum All The Vectors
*/

typedef long long ll;
static constexpr ll MOD=1e9+7;
using mat=vector<vector<ll>>;
class Solution {
public:
    mat mult(mat& a,mat& b){
        int n=a.size();
        mat c(n,vector<ll>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0) continue;
                for (int k=0;k<n;k++){
                    if(b[j][k]==0) continue;
                    c[i][k]=(c[i][k]%MOD+(a[i][j]%MOD*b[j][k]%MOD)%MOD)%MOD;
                }
            }
        }
        return c;
    }
    mat pow(mat base,ll exp){
        int n=base.size();
        mat res(n,vector<ll>(n,0));
        for(int i=0;i<n;i++) res[i][i]=1;
        while(exp){
            if(exp&1) res=mult(res,base);
            base=mult(base,base);
            exp>>=1;
        }
        return res;
    }
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        int s=2*m;
        auto up=[&](int x){return x-1;};
        auto down=[&](int x){return m+(x-1);};
        mat T(s,vector<ll>(s,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<i;j++) T[up(i)][down(j)]=1;
            for(int j=i+1;j<=m;j++) T[down(i)][up(j)]=1;
        }
        vector<ll>dp(s,0);
        for(int i=1;i<=m;i++){
            dp[up(i)]=i-1;
            dp[down(i)]=m-i;
        }
        mat p=pow(T,n-2);
        vector<ll>dp2(s,0);
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++) dp2[i]=(dp2[i]+p[i][j]*dp[j])%MOD;
        }
        ll ans=0;
        for(ll x:dp2)ans=(ans+x)%MOD;
        return ans;
    }
};
