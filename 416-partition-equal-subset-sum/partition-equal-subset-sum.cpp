class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int it:nums) sum+=it;

        if(sum %2==1) return false;
        else return isSubsetSum(nums,sum/2,n);
    }

    bool isSubsetSum(vector<int>& arr, int sum,int n) {
        // int n=arr.size();
        vector<bool> prev(sum+1,0);
        
        prev[0]=true;
        
        if(sum>=arr[0]) prev[arr[0]]=true;
        
        for(int i=1;i<n;i++){
            vector<bool> curr(sum+1,0);
            curr[0]=true;
            for(int j=1;j<=sum;j++){
                bool nottake=prev[j];
                bool take=false;
                if(j>=arr[i]) take=prev[j-arr[i]];
                curr[j]=take||nottake;
            }
            prev=curr;
        }
        
        return prev[sum];
        
    }
};