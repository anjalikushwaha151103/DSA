class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int start=-1;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                if(start==-1) start=i;
                else return false;
            }
        }

        if(start==-1) return true;

        for(int i=0;i<n-1;i++){
            if((nums[(i+start)%n])>(nums[(i+1+start)%n])){
                return false;
            }
        }

        return true;
    }
};