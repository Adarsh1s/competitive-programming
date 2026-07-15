class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        int right[26]={};
        int rightfreq=0;
        for(char c:s){
            if(right[c-'a']==0) rightfreq++;
            right[c-'a']++;
        }
        int left[26] = {};
        int leftfreq = 0;
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            if(left[s[i]-'a']==0) leftfreq++;
            left[s[i]-'a']++;
            right[s[i]-'a']--;
            if(right[s[i]-'a']==0) rightfreq--;
            if(rightfreq==leftfreq) ans++;
        }
        return ans;
    }
};