class Solution {
private:
    int helper(char t){
        if(t == 'I') return 1;
        else if(t == 'V') return 5;
        else if(t == 'X') return 10;
        else if(t == 'L') return 50;
        else if(t == 'C') return 100;
        else if(t == 'D') return 500;
        else if(t == 'M') return 1000;
        else return 0;
    }
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(i+1<s.size() && helper(s[i]) < helper(s[i+1])){
                ans += helper(s[i+1]) - helper(s[i]);
                i++;
            }
            else ans += helper(s[i]);
        }
        return ans;
    }
};