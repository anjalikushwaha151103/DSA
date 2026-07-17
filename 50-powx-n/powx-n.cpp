class Solution {
public:
    double myPow(double x, int n) {
        if(n<0 && n>INT_MIN){
            n=abs(n);
            x=1/x;
        }

        if(n==0) return 1;
        if(n%2==0){
            double half=myPow(x,n/2);
            return half*half;
        }
        return x* myPow(x,n-1);

        

    }
};