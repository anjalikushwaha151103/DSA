class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arr(n+1,true);
        arr[0]=false;
        arr[1]=false;

        for(int p=2;p*p<n;p++){
            if(arr[p]){
                for(int i=p*p;i<=n;i=i+p){
                    arr[i]=false;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]) cnt++;
        }

        return cnt;
        
    }
};