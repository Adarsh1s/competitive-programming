class Solution {
public:
    bool isValid(const string &s, int left,int right){
        while(left<right){
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0,j = s.size()-1,temp =0;
        while(i<j){
            if(s[i]!=s[j]) {
                return isValid(s,i+1,j)||isValid(s,i,j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};