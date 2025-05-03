#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isAnagram(string s, string t) {
            int cnt[26] = {0};
            for (char c: s)
            {
                cnt[c - 'a'] += 1;
            }
            for (char c: t)
            {
                cnt[c - 'a'] -= 1;
            }
            for (int num: cnt){
                if (num != 0){
                    return false;
                }
            }
            return true;
        }
    };