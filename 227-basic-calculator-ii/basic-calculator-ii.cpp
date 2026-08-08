class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int currentNum = 0;
        char prevOp = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            }

            // Process when we hit an operator or the end of string
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (prevOp == '+') {
                    stk.push(currentNum);
                } else if (prevOp == '-') {
                    stk.push(-currentNum);
                } else if (prevOp == '*') {
                    int top = stk.top(); stk.pop();
                    stk.push(top * currentNum);
                } else if (prevOp == '/') {
                    int top = stk.top(); stk.pop();
                    stk.push(top / currentNum);
                }
                prevOp = c;
                currentNum = 0;
            }
        }

        // Sum all values in the stack
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};