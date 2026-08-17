class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
       int currpos=nums[0];
       int currneg=nums[0];
       int ans=nums[0];

        for(int i=1;i<n;i++){
            int a=nums[i];
            if(a==0){
                currpos=0;
                currneg=0;
                ans=max(ans,0);

            }
            else{
                int temp=max(currpos*a,max(currneg*a,a));
                currneg=min(currpos*a,min(currneg*a,a));
                currpos=temp;
                ans=max(ans,currpos);
            }
        }

        return ans;
    }
};