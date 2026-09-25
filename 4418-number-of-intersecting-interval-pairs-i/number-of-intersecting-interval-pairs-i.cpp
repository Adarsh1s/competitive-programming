class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // If interval j starts before or when interval i ends, they overlap
                if (intervals[j][0] <= intervals[i][1]) {
                    ans++;
                } else {
                    // Since intervals are sorted by start time, no subsequent interval 
                    // starting after intervals[j][0] can overlap with interval i
                    break;
                }
            }
        }
        
        return ans;
    }
};