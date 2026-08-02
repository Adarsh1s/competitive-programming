class Solution {
public:
    int countValidPrefixes(string s) {
        int ct0=0,ct1=0;
        int ans=0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='0') ct0++;
            else ct1++;
            if(abs(ct1-ct0)<=1) ans++;
        }
        return ans;
    }
};