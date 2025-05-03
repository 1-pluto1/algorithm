#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minFlips(string s) {
            int len = s.size();
            string target="01";
            int cnt = 0;
            for (int i = 0; i < len; i++){
                cnt += (s[i] != target[i % 2]);
            }
            int ans = min(cnt, len - cnt);
            for (int i = 0; i < len; i ++){
                cnt -= (s[i] != target[i % 2]);
                cnt += (s[i] != target[(i + len) % 2]);
                ans = min({ans, len - cnt, cnt});
            }
            return ans;
        }
    };