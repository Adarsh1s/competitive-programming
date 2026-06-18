/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates(words.begin(),words.end());
        while(!candidates.empty()) {
            string bestguess = candidates[0];
            int bestgrp = candidates.size();
        for(const string& x : candidates){
            int grp[7] = {};
            for(const string& y : candidates){
                grp[match(x,y)]++;
            }
            int maxgrp = *max_element(grp,grp+7);
            if(maxgrp<bestgrp){
                bestgrp = maxgrp;
                bestguess = x;
            }
        }
        int matches = master.guess(bestguess);
        if(matches == 6) return;
        vector<string> filtered;
        for(const string& x : candidates){
            if(match(x,bestguess)==matches){
                filtered.push_back(x);
            }
        }
        candidates = filtered;
        }
    }
private:
    int match(const string& a, const string& b){
        int count = 0;
        for(int i = 0;i<6;i++){
            if(a[i] == b[i]) count ++;
        }
        return count;
    }
};