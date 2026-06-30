class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        string ans = {};
        for(char c : s){
            map[c]++;
        }
        vector<vector<char>> buckets(s.size()+1);
        for(auto& a: map){
            buckets[a.second].push_back(a.first);
        }
        for(int i = s.size();i>0;i--){
            for(char c : buckets[i]){
                ans.append(i,c);
            }
        }

        return ans;
    }
};