class Solution {
public:

    int findMaxSum(vector<int>& arr,int start,int end) {
        int prev1=arr[start];
        int prev2=0;
        
        for(int i=start+1;i<end;i++){
            int pick=arr[i]+prev2;
            int notpick=0+prev1;
            
            int curr=max(pick,notpick);
            
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
        
    }


    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(findMaxSum(nums,0,n-1),findMaxSum(nums,1,n));
    }


};