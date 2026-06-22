class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count[26] = {0};
        for(char x : text) count[x - 'a']++;

        int result = count['b' - 'a'];
        result = min(result,count['a'-'a']);
        result = min(result,count['l'-'a']/2);
        result = min(result,count['o'-'a']/2);
        result = min(result,count['n'-'a']);
        //result = min(result,count['s'-'a']);
        return result;
    }
};