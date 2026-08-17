class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,visited,grid);
                }
            }
        }

        return cnt;
    }


    void bfs(int i,int j,vector<vector<int>> &visited, vector<vector<char>> &grid){
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;

        vector<int> dr={0,0,-1,1};
        vector<int> dc={-1,1,0,0};

        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;

            q.pop();


            for(int k=0;k<4;k++){
                int row=a+dr[k];
                int col=b+dc[k];

                if(row>=0 && row<m && col>=0 && col<n){
                    if(visited[row][col]==0 && grid[row][col]=='1'){
                        visited[row][col]=1;
                        q.push({row,col});   
                    }
                }

            }
        }

    }
};