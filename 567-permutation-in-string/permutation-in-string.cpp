class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> sfreq(26,0),temp(26,0);
        for(int i = 0;i<s1.size();i++){
            sfreq[s1[i]-'a']++;
            temp[s2[i]-'a']++;
        }
        if(sfreq==temp) return true;
        for(int i = s1.size();i<s2.size();i++){
            temp[s2[i]-'a']++;
            temp[s2[i-s1.size()]-'a']--;
            if(sfreq==temp) return true;
        }
        return false;
    }
};