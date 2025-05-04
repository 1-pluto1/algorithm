// 灵神题单 常用数据结构 枚举
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int ans = 0;
            int minprice = prices[0];
            for (auto& price : prices){
                ans = max(ans, price - minprice);
                minprice = min(minprice, price);
            }
            return ans;
        }
    };

// 动态规划

// class Solution {
//     public:
//         int maxProfit(vector<int>& prices) {
//             int len = prices.size();
//             if (len == 0) return 0;
//             vector<vector<int>> dp(len, vector<int>(2));

//             dp[0][0] = -prices[0];
//             dp[0][1] = 0;
//             for (int i = 1; i < len; i++){
//                 dp[i][0] = max(dp[i - 1][0], -prices[i]);
//                 dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
//             }
//             return dp[len - 1][1];
//         }
//     };

