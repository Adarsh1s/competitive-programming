class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i = 0;i<operations.size();i++){
            if(operations[i]=="C"){
                s.pop();
            }
            else if(operations[i]=="D"){
                s.push(s.top()*2);
            }
            else if(operations[i]=="+"){
                int temp = s.top();
                s.pop();
                int sum_temp = s.top()+temp;
                s.push(temp);
                s.push(sum_temp);
            }
            else s.push(std::stoi(operations[i]));
        }
        int sum=0;
        while(!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};