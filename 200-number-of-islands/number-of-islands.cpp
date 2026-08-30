class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> visited(m,vector<int> (n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,visited,m,n,grid);
                    
                }
            }
        }
        return cnt;
    }

    void dfs(int i,int j,vector<vector<int>> &visited,int m,int n,vector<vector<char>> &grid){
        visited[i][j]=1;
        vector<int> dr={0,0,-1,1};
        vector<int> dc={-1,1,0,0};

        for(int k=0;k<4;k++){
            int row=i+dr[k];
            int col=j+dc[k];

            if(row>=0 && row<m && col>=0 && col<n && grid[row][col]=='1' && visited[row][col]==0 ){
                dfs(row,col,visited,m,n,grid);
            }
        }
        
    }
};