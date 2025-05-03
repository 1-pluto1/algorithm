#include <bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
    public:
        string shortestBeautifulSubstring(string s, int k) {
            if (count(s.begin(), s.end(), '1') < k) return "";
            string ans = s;
            int cnt = 0, left = 0;
            for (int right = 0; right < s.size(); right++){
                cnt += s[right] - '0';
                while (cnt > k || s[left] == '0')
                {
                    cnt -= s[left] - '0';
                    left ++;
                }
                if (cnt == k){
                    string t = s.substr(left, right - left + 1);
                    if (t.size() < ans.size() || t.size() == ans.size() && t < ans){
                        ans = t;
                    }
                }
            }
            return ans;
        }
        
    };