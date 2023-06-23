class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stc;
        for (string &s:tokens)
        {
            if ((s=="*" || s=="+" || s=="-" || s=="/")){
                int num2 = stc.top();
                stc.pop();
                int num1 = stc.top();
                stc.pop();
                int result = 0;
                if (s == "+") {
                    result = num1 + num2;
                } else if (s == "-") {
                    result = num1 - num2;
                } else if (s == "*") {
                    result = num1 * num2;
                } else {
                    result = num1 / num2;
                }
                stc.push(result);
            }
            else{
                int x = stoi(s);
                stc.push(x);
            }
        }
        return stc.top();
    }
};