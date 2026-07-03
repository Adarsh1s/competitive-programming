class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        queue<pair<int,int>> temp;
        for(int i=0;i<tickets.size();i++) temp.push({tickets[i],i});
        while(!temp.empty()) {
            auto current = temp.front();
            temp.pop();
            current.first--;
            ans++;
            if(current.first == 0 && current.second == k) return ans;
            if(current.first > 0) temp.push(current);
        }
        return ans;
    }
};