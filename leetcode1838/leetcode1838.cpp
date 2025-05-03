#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            int left = 0, ans = 1;
            long long cost = 0;
            vector<int> diff(nums.size());
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); i++) diff[i] = nums[i] - nums[i - 1];
            
            for (int right = 1; right < nums.size(); right ++){
                cost += (long long)diff[right] * (right - left);
                while (cost > k)
                {
                    cost -= (nums[right] - nums[left]);
                    left ++;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };