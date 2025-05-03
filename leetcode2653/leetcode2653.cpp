#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
            const int BIAS = 50;
            int cnt[BIAS * 2 + 1]{};
            for(int i = 0; i < k - 1; i++){
                cnt[nums[i] + BIAS] ++;
            }
            int n = nums.size();
            vector<int> ans(n - k + 1);
            for (int i = k - 1; i < n; i++){
                cnt[nums[i] + BIAS] ++;
                int left = x;
                for (int j = 0; j < BIAS; j++){
                    left -= cnt[j];
                    if (left <= 0){
                        ans[i - k + 1] = j - BIAS;
                        break;
                    }
                }
                cnt[nums[i - k + 1] + BIAS] --;
            }
            return ans;
        }
    };