class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();

        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>& a, const       vector<int>& b) {
            return a[1] > b[1];
        });

        int max_p=0;
        for(int i=0;i<n;i++){
            if(boxTypes[i][0]<=truckSize){
                max_p+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }else{
                max_p+=truckSize *boxTypes[i][1];
                return max_p;
            }
        }
        return max_p;
    }
};