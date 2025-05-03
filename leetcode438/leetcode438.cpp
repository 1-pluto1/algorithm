#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> ans;
            array<int, 26> cnt_p{};
            array<int, 26> cnt_s{};
            for (char c : p){
                cnt_p[c - 'a'] ++;
            }
            for (int right = 0; right < s.size(); right ++){
                cnt_s[s[right] - 'a'] ++;
                if (right < p.size() - 1){
                    continue;
                }
                if (cnt_s == cnt_p){
                    ans.push_back(right - p.size() + 1);
                }
                cnt_s[s[right - p.size() + 1] - 'a'] --;
            }
            return ans;
        }
    };
    
    