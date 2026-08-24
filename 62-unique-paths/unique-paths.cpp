class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<int> prev(n+1,0);
       for(int i=1;i<=m;i++){
            vector<int> temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(i==1 || j==1 ) temp[j]=1;
                else{
                    temp[j]=prev[j]+temp[j-1];
                }
            }
            prev=temp;
        }
       return prev[n];
    }

    
};