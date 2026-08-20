class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;int j = s.size()-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        /*for(int i = s.size()-1;i>=0;i--){
            s.push_back(s[i]);
            s.erase(s.begin() + i);
        }*/
    }
};