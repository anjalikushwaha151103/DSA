class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;

        //all 1's
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }

        //dr & dc

        vector<int> dr={0,0,-1,1};
        vector<int> dc={-1,1,0,0};

        //cal dist
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;

            int d=q.front().second;

            dist[i][j]=d;

            q.pop();

            for(int k=0;k<4;k++){
                int row=i+dr[k];
                int col=j+dc[k];

                if(row>=0 && row<m && col>=0 && col<n && !visited[row][col] ){
                    visited[row][col]=1;
                    q.push({{row,col},d+1});
                }
            }
        }

        return dist;
    }
};