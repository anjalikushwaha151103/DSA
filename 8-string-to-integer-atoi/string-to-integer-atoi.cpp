class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        bool neg=false;
        bool started=false;

        for(char ch:s){
            if(ch=='+' || ch=='-'|| ch==' '){
                if(started) break;
                else if(ch=='-'){
                    neg=true;
                    started=true;
                }else if(ch=='+') started=true;
            }
            else if(isdigit(ch)){
                started=true;
                ans=ans*10+ (ch-'0');
                if(!neg && ans>(long long)INT_MAX) return INT_MAX;
                if(neg && ans>(long long)INT_MAX+1) return INT_MIN;
            }else{
                if(started) break;
                else return 0;
            }

        }

       
        if(neg) return -1*ans;
        return ans;
    }
};