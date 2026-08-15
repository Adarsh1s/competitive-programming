class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        vector<pair<double,int>> temp;
        for(int i = 0;i<quality.size();i++){
            double x = (double)wage[i]/quality[i];
            temp.push_back({x,i});
        }
        sort(temp.begin(),temp.end());
        priority_queue<int> heap;

        double ans = DBL_MAX;
        int sum = 0;
        for(auto& worker:temp){
            double rate = worker.first;
            int i = worker.second;

            heap.push(quality[i]);
            sum += quality[i];

            if((int)heap.size()>k){
                sum -= heap.top();
                heap.pop(); 
            }
            if((int)heap.size()==k){
                ans = min(ans,rate*sum);
            }
        }
        return ans;
    }
};