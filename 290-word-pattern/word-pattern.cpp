class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        unordered_set<string> words;
        stringstream ss(s);
        string s1;int i =0;
        for(;i<pattern.length() && ss>>s1;i++){
            if(map.contains(pattern[i])){
                if(map[pattern[i]] != s1){
                    return false;
                } 
            }
            else{
                if(words.contains(s1)) return false;
            }
            map[pattern[i]] = s1;
            words.insert(s1);
        }
        return i == pattern.length() && !(ss >> s1);
    }
};