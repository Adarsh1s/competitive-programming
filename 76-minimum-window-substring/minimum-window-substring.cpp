class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";

        unordered_map<char,int> map;
        for(int i = 0;i<t.size();i++) map[t[i]]++;

        unordered_map<char,int> map1;
        int formed = 0;

        int size = INT_MAX;int left=0;
        int start=0;int required = map.size();
        
        for(int right = 0;right<s.size();right++){
            map1[s[right]]++;
            if(map.count(s[right]) && map1[s[right]]==map[s[right]])
                formed++;
            
            while(formed==required){
                if((right-left+1)<size){
                    start=left;
                    size=right-left+1;
                }
                map1[s[left]]--;
                if(map.count(s[left]) && map1[s[left]]<map[s[left]]) formed--;
                left++;
            }
        }
        return size == INT_MAX ? "" : s.substr(start,size);
    }
};