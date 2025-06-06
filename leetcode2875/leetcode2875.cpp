#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minSizeSubarray(vector<int>& nums, int target) {
            long long total = reduce(nums.begin(), nums.end(), 0LL);
            int n = nums.size();
            int ans = INT_MAX;
            int left = 0;
            long long sum = 0;
            for (int right = 0; right < n * 2; right++) {
                sum += nums[right % n];
                while (sum > target % total) {
                    sum -= nums[left++ % n];
                }
                if (sum == target % total) {
                    ans = min(ans, right - left + 1);
                }
            }
            return ans == INT_MAX ? -1 : ans + target / total * n;
        }
    };
    
