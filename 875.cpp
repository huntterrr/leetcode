#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int f(vector<int>& piles, double k) {
        long long int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += ceil(piles[i] / k);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end()), k, answer = right;
        while (left <= right) {
            k = left + (right - left) / 2;
            if (f(piles, k) <= h) {
                answer = min(k, answer);
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return answer;
    }
};
