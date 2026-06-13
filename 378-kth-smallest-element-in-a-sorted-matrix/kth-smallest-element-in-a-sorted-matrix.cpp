class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s = n*m;
        priority_queue<int> pq;
        for(int i = 0;i<s;i++){
            pq.push(matrix[i/m][i%m]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};