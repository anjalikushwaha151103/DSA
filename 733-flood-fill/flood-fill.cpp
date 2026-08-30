class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});

        int old=image[sr][sc];
        if(old==color) return image;
        image[sr][sc]=color;

        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int row=i+dr[k];
                int col=j+dc[k];

                if(row>=0 && row<m && col>=0 && col<n && image[row][col]==old){
                    image[row][col]=color;
                    q.push({row,col});
                }

            }

        }

        return image;
    }
};