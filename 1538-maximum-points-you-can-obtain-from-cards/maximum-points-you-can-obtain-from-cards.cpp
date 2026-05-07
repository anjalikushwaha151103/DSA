class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=k-1;
        int r=n-1;

        int ans=0;

        for(int i = 0; i < k; i++){
            ans += cardPoints[i];
        }
        

        int sum=ans;
        while(l>=0){
            sum=sum+cardPoints[r]-cardPoints[l];
            l--;
            r--;
            ans=max(ans,sum);
        }

        return ans;
        
    }
};