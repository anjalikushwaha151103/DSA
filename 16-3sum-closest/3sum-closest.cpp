class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int min_diff=INT_MAX;

        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>target){
                    k--;
                }else if(sum<target){
                    j++;
                }else{
                    k--;
                    j++;
                }
                int diff=abs(target-sum);
                if(diff<min_diff){
                    ans=sum;
                    min_diff=diff;
                }    
            }

        }
        return ans;
    }
};