#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> set;
            int n = s.size();
            int right = -1;
            int res = 0;
            for(int i = 0; i < n; ++i){
                if(i != 0){
                    set.erase(s[i - 1]);
                } 
                while(right + 1 < n && !set.count(s[right + 1])){
                    set.insert(s[right + 1]);
                    ++right;
                }
                res = max(res, right - i + 1);
            }
            return res;
        }
    };