class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 || j==1) dp[i][j]=1;
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }

    int f(int i,int j, vector<vector<int>> &dp){
        if(i==1 || j==1) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=f(i,j-1,dp)+f(i-1,j,dp);
    }
};