class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int w = words[0].size();
        int m = words.size();
        int totalLen = m * w;
        if((int)s.size()<totalLen) return result;

        unordered_map<string, int>target;
        for(auto& word:words) target[word]++;
        int distinctWords = target.size();

        for(int k = 0;k<w;k++){
            unordered_map<string,int> seen;
            int matchCount = 0;
            int left = k;

            for(int right=k;right+w<=(int)s.size();right +=w){
                string rightword = s.substr(right,w);

                if(target.count(rightword)) {
                    seen[rightword]++;
                    if(seen[rightword] == target[rightword]) matchCount++;
                    else if (seen[rightword] == target[rightword] +1) matchCount--;
                }
                if(right-left >= totalLen){
                    string leftword = s.substr(left,w);
                    if(target.count(leftword)) {
                        if(seen[leftword] == target[leftword]) matchCount--;
                        seen[leftword]--;
                        if(seen[leftword] == target[leftword]) matchCount++;
                    }
                    left += w;
                }
                if(matchCount == distinctWords) result.push_back(left);
            }
        }
        return result;
    }
};