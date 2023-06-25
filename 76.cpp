#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> main;
        for (char &it : t) {
            main[it]++;
        }
        
        int counter = main.size();
        int l = 0;
        int left_index = -1, right_index = -1;

        for (int r = 0; r < s.size(); r++) {
            if (main.count(s[r])) {
                main[s[r]]--;
                if (main[s[r]]==0) {
                    counter--;
                }
            }
            while (counter == 0) {
                if (left_index==-1 || right_index-left_index > r - l) {
                    left_index = l;
                    right_index = r;
                }
                if (main.count(s[l])) {
                    main[s[l]]++;
                    if (main[s[l]] > 0) {
                        counter++;
                    }
                }
                l++;
            }
            while (l < s.size() && !main.count(s[l])) {
                l++;
            }
        }
        if (left_index==-1)
        {
            return "";
        }
        return s.substr(left_index, right_index-left_index+1);
    }
};
