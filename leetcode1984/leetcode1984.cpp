#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumDifference(vector<int>& nums, int k) {
            int ans = INT32_MAX;
            int temp = INT32_MAX;
            sort(nums.begin(), nums.end());
            for (int i = k - 1; i < nums.size(); i++){
                temp = nums[i] - nums[i - k + 1];
                ans = min(temp, ans);
            }
            return ans;
        }
    };