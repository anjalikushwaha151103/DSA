class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int max_len=0;
        int index=0;
        for(int i=0;i<n;i++){
            int odd=fn(s,i,i);
            int even=fn(s,i,i+1);
            int maxi=max(odd,even);
            if(maxi>max_len){
                max_len=maxi;
                index = i - (max_len - 1) / 2;
;
            }
        }
        if(max_len==0) return "";
        else{
            return s.substr(index,max_len);
        }
    }

    int fn(string str , int left , int right){
        while(left>=0 && right<str.length() && str[left]==str[right] ){
            left--;
            right++;
        }
        return right-left-1;
    }
};