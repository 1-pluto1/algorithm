#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numIdenticalPairs(vector<int>& nums) {
            int ans = 0;
            unordered_map<int, int> cnt;
            for (int x : nums){
                ans += cnt[x];
                cnt[x] ++;
            }
            return ans;
        }
    };


// 灵神题单 常用数据结构 枚举

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numIdenticalPairs(vector<int>& nums) {
            int ans = 0;
            unordered_map<int, int> cnt;
            for (int x : nums){
                ans += cnt[x];
                cnt[x] ++;
            }
            return ans;
        }
};