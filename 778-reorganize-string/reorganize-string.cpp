class Solution {
public:
    string reorganizeString(string s) {
        string ans(s.size(),' ');
        int freq[26] ={}; int maxfreq = 0, maxchar = 0;
        for(char c: s) {
            freq[c - 'a']++;
            if(freq[c-'a']>maxfreq){
                maxfreq = freq[c-'a'];
                maxchar = c - 'a';
            }
        }
        if(maxfreq > (s.size()+1)/2) return "";
        int index = 0;
        while(freq[maxchar]>0){
            ans[index] = (char)(maxchar + 'a');
            freq[maxchar]--;
            index += 2;
        }
        for(int i = 0;i<26;i++){
            while(freq[i]>0){
                if(index>=s.size()) index=1;
                ans[index] = (char)(i+'a');
                freq[i]--;
                index+=2;
            }
        }
        return ans;
    }
};