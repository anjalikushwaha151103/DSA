class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        int target=image[sr][sc];
        if(target == color) return image;
        bfs(sr,sc,image,target,color);

        return image;

    }

    void bfs(int i, int j,vector<vector<int>>& image,int target,int color){
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        image[i][j]=color;

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
                    if(image[row][col]== target){
                        image[row][col]=color;
                        q.push({row,col});
                    }
                }
            }
            
        }
    }
};