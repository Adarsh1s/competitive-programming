class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        map<tuple<int,int,long long>, vector<pair<int,int>>> groups;
        for(int i = 0;i<points.size();i++){
            for(int j = i+1;j<points.size();j++){
                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                long long dist = dx * dx + dy *  dy;

                groups[{mx,my,dist}].push_back({i,j});
            } 
        }
        double minArea = DBL_MAX;
        bool found = false;
        for(auto& [key,pairs] : groups){
            for(int a = 0;a<(int)pairs.size();a++){
                for(int b = a+1;b<(int)pairs.size();b++){
                    int i = pairs[a].first, j = pairs[a].second;
                    int k = pairs[b].first;
                    double s1x = points[k][0] - points[i][0];
                    double s1y = points[k][1] - points[i][1];
                    double s2x = points[j][0] - points[i][0];
                    double s2y = points[j][1] - points[i][1];
                    double area = abs(s1x * s2y - s1y * s2x);
                    if(area>0){
                        found = true;
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        return found ? minArea:0.0;
    }
};