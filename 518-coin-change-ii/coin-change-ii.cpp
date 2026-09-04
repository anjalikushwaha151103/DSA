class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<long long> prev(amount+1,0);
        
        //amount 0
        prev[0]=1;

        //base case 
        for(int j=1;j<=amount;j++){
            if(j% coins[0]==0) prev[j]= 1;
            else prev[j]= 0;
        }

        //iteration
        for(int i=1;i<n;i++){
            vector<long long> temp(amount+1,0);
            temp[0]=1;
            for(int j=1;j<=amount;j++){  
                int take=0;
                if(j-coins[i]>=0) take= temp[j-coins[i]];
                int nottake=prev[j];

                temp[j]=(long long) take+nottake;
            }
            prev=temp;
        }
        return prev[amount];
    }

};