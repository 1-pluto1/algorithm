#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int ans = 0;
            int cnt[10][10] = {};
            for (auto & d : dominoes){
                auto [a, b] = minmax(d[0], d[1]);
                ans += cnt[a][b];
                cnt[a][b] ++;
            }
            return ans;
        }
    };

/**
 * 
 * 在C++中，std::minmax 是一个标准库函数，它同时返回两个值中的最小值和最大值。
 * 这个函数定义在 <algorithm> 头文件中。它返回一个 std::pair，其中 first 成员是较小的值，second 成员是较大的值。
 */