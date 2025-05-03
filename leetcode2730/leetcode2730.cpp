#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestSemiRepetitiveSubstring(string s) {
            int left = 0, ans = 1, same = 0;
            for (int right = 1; right < s.size(); right ++){
                same += (s[right] == s[right - 1]);
                if (same > 1)
                {
                    left ++;
                    while (s[left] != s[left - 1])
                    {
                        left ++;
                    }
                    same = 1;
                    // 记得复位same
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };