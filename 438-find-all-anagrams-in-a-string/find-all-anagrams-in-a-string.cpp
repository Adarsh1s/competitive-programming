class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.size()<p.size()) return result;
        vector<int> pcount(26,0); vector<int> temp(26,0); 
        for(int i = 0;i<p.size();i++){
            pcount[p[i]-'a']++;
            temp[s[i]-'a']++;
        }
        if(pcount == temp) result.push_back(0);
        for(int i = p.size();i<s.size();i++){
            temp[s[i]-'a']++;
            temp[s[i-p.size()]-'a']--;
            if(pcount == temp) result.push_back(i-p.size()+1);
        }
        return result;
    }
};