class Solution {
public:
    int dist(vector<int>p,vector<int> q){
        return  (long long)(p[0]-q[0])*(p[0]-q[0]) +
                (long long)(p[1]-q[1])*(p[1]-q[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<long long> ans {
            dist(p1,p2), dist(p1,p3), dist(p1,p4),
            dist(p2,p3), dist(p2,p4), dist(p3,p4) };
        map<long long,int> freq;
        for(long long x: ans) freq[x]++;
        if(freq.size()!=2) return false;
        auto it = freq.begin();
        long long side = it->first;
        int sidecount = it->second;
        it++;
        long long diag = it->first;
        int diagcount = it->second;
        return side>0 && sidecount==4 && diagcount==2 && diag==side*2;
    }
};