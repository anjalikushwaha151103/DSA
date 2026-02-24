class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        
        string res="";
        sort(strs.begin(),strs.end()) ; 

        string first=strs[0];
        string last=strs[n-1];

        int cnt=0;

        for(int i=0;i<min(first.length(),last.length());i++){
            if(first[i]==last[i]) cnt++;
            else{
                break;
            }
        }
        if(cnt==0) return "";
        else return first.substr(0,cnt);
    }
    
};