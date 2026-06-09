class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s1;
        if(s.length() != t.length()) return 0;
        for(int i=0;i<s.length();i++){
            s1[s[i]]++;
            s1[t[i]]--;
        }
        for(auto pair : s1){
            if(pair.second != 0) return false ;
        }
        return true;

        /*for (int i = 0; i < s.length(); i++) {
            if (s[i] == t[i])
                continue;
            else{
                if (s1.contains(s[i])) s1.erase(s[i]);
                else s1[s[i]]++;
                if (s1.contains(t[i])) s1.erase(t[i]);
                else s1[t[i]]++;
            }
        }
        if(s1.size()>=1) return 0;
        else return 1;*/

    }
};