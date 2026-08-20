class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;string temp;
        while(ss>>temp){
            word = temp;
        }
        int ans = 0;
        for(int i = 0;i<word.size();i++)  ans++;
        return ans;
    }
};