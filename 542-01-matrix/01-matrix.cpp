class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>visited (m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        vector<vector<int>>ans (m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }


        vector<int> dr={0,0,-1,1};
        vector<int> dc={-1,1,0,0};

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
                    if(visited[row][col]!=1 && mat[row][col]==1){
                        visited[row][col]=1;
                        q.push({{row,col},t+1});
                        ans[row][col]=t+1;
                    }
                }

            }


        }
        return ans;
    }
};