class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int cycle = 2*numRows-2;
        if(numRows==1 || numRows>=(int)s.size()) return s;
        for(int r = 0;r<numRows;r++){
            for(int i =0;i+r<s.size();i+=cycle){
                ans+=s[i+r];
                if(r>0 && r<numRows-1 && i+cycle-r<(int)s.size()){
                    ans+=s[i+cycle-r];                
                }
            }
        }
        return ans;
    }
};

