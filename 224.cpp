/*
	Author: Haciyev Huseyn
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calc(int i, string s){
        int res = 0;
        char op = 1;
        stack<pair<int, int>> stk;
        while(i<s.size()){
            if(isdigit(s[i])){
                int num = 0;
                while(i<s.size() and isdigit(s[i])){
                    num = num*10+(s[i]-'0');
                    i++;
                }
                i--;
                res+=num*op;
                op = 1;
            }
            else if(s[i]=='('){
                stk.push({res, op});
                res = 0;
                op = 1;
            }
            else if(s[i]==')'){
                auto it = stk.top();
                stk.pop();
                res = it.first+(it.second*res);
            }
            else if(s[i]=='-'){
                op = -1*op;
            }
            i++;
        }
        return res;
    }

    int calculate(string s) {
        int i = 0;
        return calc(i, s);
    }
};