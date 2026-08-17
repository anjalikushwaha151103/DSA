class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>>visited (m,vector<int>(n,0));
        queue<pair<int,int>> q;


        //boundary values
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && visited[i][0]==0){
                visited[i][0]=1;
                q.push({i,0});
            }
            if(board[i][n-1]=='O' && visited[i][n-1]==0){
                visited[i][n-1]=1;
                q.push({i,n-1});
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && visited[0][j]==0){
                visited[0][j]=1;
                q.push({0,j});
            }
            if(board[m-1][j]=='O' && visited[m-1][j]==0){
                visited[m-1][j]=1;
                q.push({m-1,j});
            }
        }
        
        //bfs
        vector<int> dr={0,0,-1,1};
        vector<int> dc={-1,1,0,0};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int row=i+dr[k];
                int col=j+dc[k];

                if(row>=0 && row<m && col>=0 && col<n){
                    if(visited[row][col]==0 && board[row][col]=='O'){
                        visited[row][col]=1;
                        q.push({row,col});
                    }
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(visited[i][j]==0) board[i][j]='X';
            }
        }
           
    }
};