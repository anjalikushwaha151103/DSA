class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        for(int i = 0; i < n - 2; i += 3){
            if(nums[i] != nums[i + 1]){
                return nums[i];
            }
        }

        return nums[n - 1];

        

       return nums[n-1]; 
        
    }
};