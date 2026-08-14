class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i = 0;i<tasks.size();i++) freq[tasks[i]-'A']++;
        sort(freq.begin(),freq.end());
        int time = 0;
        while(freq[25]>0){
            int i = 0;
            for(int i = 0;i<=n;i++){
                if(freq[25]==0) break;
                if(i<26 && freq[25-i]>0) freq[25-i]--;
                time++;
            }
            sort(freq.begin(),freq.end());
        }
        return time;
    }
};