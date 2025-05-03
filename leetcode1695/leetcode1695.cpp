#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {
            int ans = 0, left = 0, sum = 0;
            unordered_map<int, int> cnt;
            for (int right = 0; right < nums.size(); right ++){
                sum += nums[right];
                cnt[nums[right]] ++;
                while (cnt[nums[right]] > 1)
                {
                    sum -= nums[left];
                    cnt[nums[left]]--;
                    if (cnt[nums[left]] == 0) cnt.erase(nums[left]);
                    left ++;
                }
                ans = max(ans, sum);
            }
            return ans;
        }
    };