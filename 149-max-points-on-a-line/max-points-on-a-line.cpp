class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3) return n;
        int result = 2;
        for(int i = 0;i<n;i++){
            map<pair<int,int>,int> slopemax;
            int temp=0; 
            for(int j = 0;j<n;j++){
                if(j==i) continue;
                int dx = points[j][1]-points[i][1];
                int dy = points[j][0]-points[i][0];
                int g = __gcd(abs(dy) , abs(dx));
                dx /= g;
                dy /= g;

                if(dx<0){
                    dy = -dy;
                    dx = -dx;
                }
                else if(dx==0) dy = abs(dy);
    
                slopemax[{dy,dx}]++;
                temp = max(temp,slopemax[{dy,dx}]);
            }
            result = max(result,temp+1);
        }
        return result;      
    }
};