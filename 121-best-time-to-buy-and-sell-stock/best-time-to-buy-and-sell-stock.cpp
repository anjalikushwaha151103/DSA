class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int max_p=0;

        for(int i=1;i<n;i++){
            int diff=prices[i]-mini;
            mini=min(mini,prices[i]);
            max_p=max(max_p,diff);
        }

        return max_p;
        
    }
};