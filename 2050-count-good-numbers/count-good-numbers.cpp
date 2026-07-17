class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ans=1;
        long long odd=n/2;
        long long even=n/2;
        if(n%2==1) even++;

        long long mod = 1e9 + 7;

        ans= (myPow(5,even,mod) * myPow(4,odd,mod))% mod;

        return ans;
    }

    long long myPow(long long x, long long n, long long mod){
        if(n==0) return 1;
        if(n%2==0){
            long long half=myPow(x,n/2,mod);
            return (half*half)%mod;
        }
        return (x* myPow(x,n-1,mod)) %mod;
    }
};