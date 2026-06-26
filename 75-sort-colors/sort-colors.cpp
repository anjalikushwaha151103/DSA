class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zeros=0;
        int ones=0;
        int twos=0;

        for(int a:nums){
            if(a==0) zeros++;
            else if(a==1) ones++;
            else twos++;
        }
        
        int i=0;
        while(zeros--){
            nums[i++]=0;
        }

        while(ones--){
            nums[i++]=1;
        }

        while(twos--){
            nums[i++]=2;
        }
    }
};