class Solution {
public:
    int countPrimes(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int size = n/2;
        if(n<=2) return 0;
        vector<char> ans(size,true);
        int prime_count = 1;

        ans[0]=false;
        for(int i = 1;2*i+1<n;i++){
            if(ans[i]){
                prime_count++;
                long long p = 2*i+1;
                for(long long j = (p*p)/2;j<size;j+=p) ans[j]=false;
            }
        }
        

        return prime_count;
    }
};