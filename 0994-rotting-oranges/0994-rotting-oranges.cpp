class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),fresh=0,t=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()&&fresh){
            int s=q.size();
            while(s--){
                auto [r,c]=q.front();q.pop();
                for(auto &x:d){
                    int a=r+x[0],b=c+x[1];
                    if(a>=0&&a<m&&b>=0&&b<n&&grid[a][b]==1)
                        grid[a][b]=2,fresh--,q.push({a,b});
                }
            }
            t++;
        }
        return fresh?-1:t;
    }
};