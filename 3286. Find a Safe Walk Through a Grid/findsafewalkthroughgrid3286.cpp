/*
Compute Start Health
Initialise best With -1 To Store Maximum Remaining Health
Initialise queue And Push start
While !q.empty{
    pop
    if Destination Is Reached return True
    For Every Neighbor{
        Compute New Health
        If Health Is <=0 Continue
        Update Health If New Health>Health
        Push
    }
}
Return False

*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
        int start=health-grid[0][0];
        if(start<=0) return false;
        vector<vector<int>> best(m,vector<int>(n,-1));
        queue<tuple<int,int,int>>q;
        best[0][0]=start;
        q.push({0,0,start});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto [r,c,h]=q.front();
            q.pop();
            if(r==m-1 && c==n-1) return true;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                int nh=h-grid[nr][nc];
                if(nh<=0) continue;
                if(nh>best[nr][nc]){
                    best[nr][nc]=nh;
                    q.push({nr,nc,nh});
                }
            }
        }
        return false;
    }
};
