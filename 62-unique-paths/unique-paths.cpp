class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        vector<int> prev(n+1,1);
        // for(int i=1;i<=n;i++) dp[1][i]=1;
        // for(int i=1;i<=m;i++) dp[i][1]=1;

        for(int i=2;i<=m;i++){
            vector<int> temp(n+1,0);
            temp[1]=1;           
            for(int j=2;j<=n;j++){
                temp[j]=prev[j]+temp[j-1];
            }
            prev=temp;
        }
        return prev[n];
    }

    
};