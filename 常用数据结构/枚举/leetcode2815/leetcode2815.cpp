#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSum(vector<int>& nums) {
            int ans = -1;
            vector<int> max_val(10, INT_MIN);
            for (int num : nums){
                int max_d = 0;
                for (int x = num; x != 0; x /= 10){
                    max_d = max(max_d, x % 10);
                }
                ans = max(ans, max_val[max_d] + num);
                max_val[max_d] = max(max_val[max_d], num);
            }
            return ans;

        }
    };