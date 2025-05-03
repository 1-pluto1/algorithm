#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int divisorSubstrings(int num, int k) {
            string s = to_string(num);
            int ans = 0;
            for (int i = k; i <= s.size(); i++){
                int x = stoi(s.substr(i - k, k));
                if (x > 0 && num % x == 0){
                    ans ++;
                }
            }
            return ans;
        }
    };