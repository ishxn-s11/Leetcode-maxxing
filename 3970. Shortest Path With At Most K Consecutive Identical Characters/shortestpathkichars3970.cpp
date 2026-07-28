/*
For Moving Further, We Only Need The Current Node,Last Character And The 
Length Of Streak

Pattern Is Similar To Dijkstra 

So, We Can Think Of The Current Streak Is The Part Of Shortest Path State
*/

typedef long long ll;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>g(n);
        for(auto &e:edges) g[e[0]].push_back({e[1],e[2]});
        const ll INF=1e18;
        vector<vector<ll>>dist(n,vector<ll>(k+1,INF));
        priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<>>pq;
        dist[0][1]=0;
        pq.push({0,0,1}); //Cost,Node,Streak
        while(!pq.empty()){
            auto[d,u,streak]=pq.top();
            pq.pop();
            if(d!=dist[u][streak]) continue;
            for(auto &[v,w]:g[u]){
                int newstk;
                if(labels[v]==labels[u]){
                    newstk=streak+1;
                    if(newstk>k) continue;
                }else newstk=1;
                ll nd=d+w;
                if(nd<dist[v][newstk]){
                    dist[v][newstk]=nd;
                    pq.push({nd,v,newstk});
                }   
            }
        }
        ll ans=INF;
        for(int i=1;i<=k;i++) ans=min(ans,dist[n-1][i]);
        return ans==INF?-1:ans;
    }
};
