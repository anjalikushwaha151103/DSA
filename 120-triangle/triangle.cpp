class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> last(n,0);
        for(int j=0;j<n;j++){
            last[j]= triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            vector<int> temp(n,0);
            for(int j=i;j>=0;j--){
                int d= triangle[i][j]+last[j];
                int dg= triangle[i][j]+last[j+1];  

                temp[j]=min(d,dg);
            }
            last=temp;
        }

        return last[0];
    }

};