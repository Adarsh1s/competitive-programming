class Solution {
public:
    int reverse(int x) {
        bool neg = x<0;
        string ans = to_string(abs((long long)x));
        std::reverse(ans.begin(),ans.end());
        long long temp = stoll(ans);
        if(neg) temp = -temp;
        if(temp < INT_MIN || temp > INT_MAX) return 0;
        return temp;
    }
};