class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int write=0;
        for(int i = 0;i<s.size();i++){
            if(s[i] != ' '){
                if(write>0) s[write++]=' ';
                int wordstart = write;
                while(i<s.size() && s[i]!=' '){
                    s[write++]=s[i++]; 
                }
                reverse(s.begin()+wordstart,s.begin()+write);
            }
        }
        s.resize(write);
        return s;
    }
};