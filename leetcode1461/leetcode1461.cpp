#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool hasAllCodes(string s, int k) {
            if (s.size() < (1 << k) + k - 1){
                return false;
            }
            unordered_set<string> exists;
            for (int i = 0; i + k - 1 < s.size(); i++){
                exists.insert(s.substr(i, k));
            }
            return exists.size() == (1 << k);
        }
    };