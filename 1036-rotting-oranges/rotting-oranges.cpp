class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>visited (m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
            }
        }

        vector<int> dr={0,0,-1,1};
        vector<int> dc={-1,1,0,0};

        int ans=0;
        while(!q.empty()){
            pair node=q.front().first;
            int t=q.front().second;

            int i=node.first;
            int j=node.second;

            q.pop();

            for(int k=0;k<4;k++){
                int row=i+dr[k];
                int col=j+dc[k];

                if(row>=0 && row<m && col>=0 && col<n){
                    if(visited[row][col]!=2 && grid[row][col]==1){
                        visited[row][col]=2;
                        q.push({{row,col},t+1});
                    }
                }

            }

            ans=max(ans,t);
            
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==0) return -1;
            }
        }

        return ans;
    }
};