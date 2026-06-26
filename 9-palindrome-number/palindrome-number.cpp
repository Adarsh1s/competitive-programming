class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int first = 0,last = s.size()-1;
        while(first<last){
            if(s[first] != s[last]) return false;
            first++;
            last--;
        }
        return true;
    }
};