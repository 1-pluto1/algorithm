#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int takeCharacters(string s, int k) {
            int cnt[3]{};
            for (char c : s){
                cnt[c - 'a'] ++;
            }
            if (cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;
            int ans = 0, left = 0;
            for (int right = 0; right < s.size(); right++){
                cnt[s[right] - 'a'] --;
                while (cnt[s[right] - 'a'] < k)
                {
                    cnt[s[left] - 'a'] ++;
                    left ++;
                }
                ans = max(ans, right - left + 1);
            }
            return s.size() - ans;
        }
    };