class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el=-1;
        int cnt=0;

        for(int a:nums){
            if(cnt==0){
                el=a;
                cnt++;
            }
            else if(el==a) cnt++;
            else cnt--;
        }
        return el;
    }
};