class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        long long ct = 0;
        if(k == 0)
            if( k<=r && k>=l){ 
            return 1;
            }
            else {
                return int(0);
            }
                
        if(k==1){
            ct = r-l+1;
            return ct>1000000009?1:ct;
        }
        
        for(int i = 0;i<INT_MAX;i++){
            int power=pow(i,k);
            if(power>=l && power<=r)ct++;
            else if(power>r) break;
        }
        return ct>1000000009?1:ct;
    }
};