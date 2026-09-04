class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        if( f(n-1,coins,amount,dp)==1e9) return -1;
        else return  f(n-1,coins,amount,dp);
    }

    int f(int i,vector<int>& coins, int amount ,vector<vector<int>> &dp){
        if(amount<= 0) return 0;
        if(i==0){
            if(amount% coins[0]==0) return (amount/ coins[0]);
            else return 1e9;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int take=1e9;
        if(i>0 && amount>=coins[i]) take=1 + f(i,coins,amount-coins[i],dp);

        int nottake= f(i-1,coins,amount,dp);

        return dp[i][amount]=min(take,nottake);

    }

    
};