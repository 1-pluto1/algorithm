#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            // 在s2维护一个长度为s1的滑动窗口，窗口有所有s1的字符返回true,否则返回false
            multiset<char> pt, t;
            for (auto & ch : s1) pt.insert(ch);
            int k = s1.size();
            for (int i = 0; i < s2.size(); i++){
                t.insert(s2[i]);
                if (i < k - 1) continue;
                if (pt == t) return true;
                auto it = t.find(s2[i - k + 1]);
                t.erase(it);
            }
            return false;
        }
    };