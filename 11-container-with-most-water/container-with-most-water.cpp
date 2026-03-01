class Solution {
public:
    int maxArea(vector<int>& h) {
        int maxi=INT_MIN;
        int n=h.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int ans=0;
            if(h[i]>h[j]){
                ans=(h[j]*(j-i));
                j--;
            }
            else if(h[i]<h[j]){
                ans=(h[i]*(j-i));
                i++;
            }
            else{
                ans=(h[i]*(j-i));
                i++;
                j--;
            }
            maxi=max(maxi,ans);
        }
        return maxi;    
    }

};