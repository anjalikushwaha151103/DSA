class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int curpos=nums[0];
        int curneg=nums[0];

        for(int i =1;i<n;i++){
            int x=nums[i];
            int a=max(x,max(curpos*x,curneg*x));
            curneg=min(x,min(curpos*x,curneg*x));
            curpos=a;
            ans=max(ans,curpos);
        }
        return ans;
    }
};