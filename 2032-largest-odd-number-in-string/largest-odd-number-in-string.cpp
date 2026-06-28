class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        int max_o=0;
        string ans="";
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2==1){
                ans=num.substr(0,i+1);
                break;
            }
        }
        return ans;    
    }
};