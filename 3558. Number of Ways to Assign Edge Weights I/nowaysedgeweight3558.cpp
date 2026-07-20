//BFS And Expoentiation
typedef long long ll;
class Solution {
public:
    static const int MOD=1e9+7;
    ll exp(ll a,ll b){
        ll ans=1;
        while(b>0){
            if(b&1) ans=(ans*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int,int>> q; //{Node,Depth}
        vector<bool> visit(n+1,false);
        q.push({1,0});
        visit[1]=true;
        int max_depth=0;
        while(!q.empty()){
            auto [n,d]=q.front();
            q.pop();
            max_depth=max(max_depth,d);
            for(int i:adj[n]){
                if(!visit[i]){
                    visit[i]=true;
                    q.push({i,d+1});
                }
            }
        }
        return (int)exp(2,max_depth-1);
    }
};
