class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> se;
        int curSum = 0,maxSum = 0;
        int left=0;
        for(int right = 0;right<s.size();right++){
            while(se.find(s[right]) != se.end()){
                se.erase(s[left]);
                left++;
                curSum--;
            }
            se.insert(s[right]);
            curSum++;
            maxSum = max(curSum,maxSum);
        }
        return maxSum;
    }
};