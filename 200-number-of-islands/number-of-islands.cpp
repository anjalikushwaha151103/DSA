class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void bfs(int i, int j,vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();


            for(int k=0;k<4;k++){
                int row=i+dr[k];
                int col=j+dc[k];
                if(row>=0 && row<n && col>=0 && col<m){
                    if(grid[row][col]=='1'&& vis[row][col]!=1){
                        q.push({row,col});
                        vis[row][col]=1;
                    }
                }
            }
            
        }
    }
};