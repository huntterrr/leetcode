#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char &i : s)
        {
            if (i=='(' or i=='[' or i=='{'){
                stk.push(i);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                char breaket = stk.top();
                if (breaket=='(' and i==')')
                {
                    stk.pop();
                }
                else if(breaket=='[' and i==']'){
                    stk.pop();
                }
                else if(breaket=='{' and i=='}'){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};