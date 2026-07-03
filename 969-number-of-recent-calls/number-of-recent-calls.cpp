class RecentCounter {
    queue<int> vect;
public:
    RecentCounter() {}
    
    int ping(int t) {
        vect.push(t);
        while(vect.front()<t-3000){
            vect.pop();
        }
        return vect.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */