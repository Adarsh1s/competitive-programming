class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxleft = values[0]+0;
        int maxscore = 0;

        for(int i=1;i<values.size();i++){
            maxscore = max(maxscore,maxleft + values[i]-i);
            maxleft = max(maxleft,values[i]+i);
        }
        return maxscore;
    }
};