class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(m>n) return "";

        int min_len=INT_MAX;
        int start=-1;
        int cnt=0;
        int l=0;
        int r=0;

        int arr[256]={0};
        for(int k=0;k<m;k++) arr[t[k]]++;

        while(r<n){
            if(arr[s[r]]>0) cnt++;
            arr[s[r]]--;
            
            while(cnt==m){
                if(min_len>(r-l+1)){
                  min_len=(r-l+1);
                  start=l;  
                }

                arr[s[l]]++;
                if(arr[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }

        if(start==-1) return "";
        return s.substr(start,min_len);   
    }
};