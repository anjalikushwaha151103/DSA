class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> nz;
        for(int a:nums){
            if(a!=0) nz.push_back(a);
        }
        for(int i=0;i<nz.size();i++){
            nums[i]=nz[i];
        }
        if(nz.size()!=nums.size()){
            for(int j=nz.size();j<n;j++){
                nums[j]=0;
            }
        }
    }
};