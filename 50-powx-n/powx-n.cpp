class Solution {
public:
    double myPow(double x, int n) {

        long long n1=n;
        if(n1<0) n1=-1*n1;
        double ans=1.0;

        while(n1>0){
            if(n1%2==1){
                ans=ans*x;
            }
            x=x*x;
            n1=n1/2;
        }

        if(n<0) return (1/ans);
        else return ans;
        
    }
};