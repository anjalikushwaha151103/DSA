class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        
        double max_sum=sum;
        int l=0;
        int r=k;
        while(r<n){
            sum=sum+nums[r]-nums[l];
            l++;
            r++;
            max_sum=max(max_sum,sum);
        }
        return max_sum/k;
    }
};