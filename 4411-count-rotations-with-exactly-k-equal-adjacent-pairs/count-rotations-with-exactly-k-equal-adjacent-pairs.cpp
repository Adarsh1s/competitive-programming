class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();int ans = 0;
        if(n==0) return (k==0)?1:0;

        string s_s = s+s;int match = 0;
        for(int i = 1;i<n;i++){
            if(s[i]==s[i-1]) match++;
        }
        if(match==k) ans++;
        
        for(int i = 1;i<n;i++){
            if(s_s[i]==s_s[i-1]) match--;
            if(s_s[i+n-2]==s_s[i+n-1]) match++;
            if(match==k) ans++;
        }
        return ans;
    }
};