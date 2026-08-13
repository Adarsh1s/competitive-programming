class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_cost=0;
        int total_fuel=0;
        for(int i = 0;i<n;i++){
            total_cost += cost[i];
            total_fuel += gas[i];
        }
        if(total_cost>total_fuel) return -1;

        int curr_index = 0;
        int curr_fuel = 0;

        for(int i = 0;i<n;i++){
           curr_fuel += gas[i]-cost[i];
           if(curr_fuel < 0){
            curr_index = i+1;
            curr_fuel = 0;
        }
        }
        
        return curr_index;
    }
};