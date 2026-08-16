class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = INT_MAX;int index = INT_MAX;
        for(int i = 0;i<drones.size();i++){
            int t = abs(drones[i][0]-target[0]) + 
            abs(drones[i][1]-target[1]);
            
            if(t<=drones[i][2]){
                //int d = drones[i][2]-t;
                if(t<ans){
                    ans = t;
                    index = i;
                }
                else if(t==ans) index=min(index,i);
                
            }
                
        }
        return index==INT_MAX?-1:index;
    }
};