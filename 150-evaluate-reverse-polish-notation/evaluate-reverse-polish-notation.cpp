class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int x = (int)s.top();
                s.pop();
                int y = (int)s.top();
                s.pop();
                if(tokens[i] == "+") s.push(x+y);
                else if(tokens[i] == "-") s.push(y-x);
                else if(tokens[i] == "*") s.push(x*y);
                else if(tokens[i] == "/") s.push(y/x);
            }
            else{
                s.push(stoi(tokens[i]));
            }
            
        }
        return s.top();
    }
};