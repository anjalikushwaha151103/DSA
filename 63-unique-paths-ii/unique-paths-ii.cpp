class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return f(m-1,n-1,obstacleGrid,dp);
    }

    int f(int i,int j,vector<vector<int>>& grid ,
    vector<vector<int>>& dp){
        if(i>=0 && j>=0 && grid[i][j]==1) return dp[i][j]= 0;
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return dp[i][j]=1;

        if(dp[i][j]!=-1) return dp[i][j];

        int up=0;
        int left=0;
        if(i-1>=0) up+=f(i-1,j,grid,dp);
        if(j-1>=0) left+=f(i,j-1,grid,dp);
        return dp[i][j]= up+left;
    }
};