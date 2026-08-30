class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,pair<int,int>>> q;

        //push rotten oranges into the queue

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({0,{i,j}});
            }
        }

        int t=0;
        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};
        while(!q.empty()){
            int i=q.front().second.first;
            int j=q.front().second.second;
            int time=q.front().first;
            q.pop();

            for(int k=0;k<4;k++){
                int row=i+dr[k];
                int col=j+dc[k];

                if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==1){
                    grid[row][col]=2;
                    q.push({time+1,{row,col}});
                }

                t=max(t,time);
            }
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        
        return t;
    }
};