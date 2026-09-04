class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> safe(m,vector<int>(n,0));

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==m-1||j==n-1 ||i==0 ||j==0) && (board[i][j]=='O')){
                    q.push({i,j});
                    safe[i][j]=1;
                }
            }
        }

        vector<int> dr={0,0,-1,1};
        vector<int> dc={-1,1,0,0};

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;

            q.pop();

            for(int k=0;k<4;k++){
                int row=i+dr[k];
                int col=j+dc[k];

                if(row>=0 && row<m && col>=0 && col<n && board[row][col]=='O' && 
                !safe[row][col] ){
                    safe[row][col]=1;
                    q.push({row,col});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !safe[i][j]){
                    board[i][j]='X';
                }
            }
        }
        
    }
};