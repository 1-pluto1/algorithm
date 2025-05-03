#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int ans = 0, left = 0;
            unordered_map<int, int> cnt;
            for (int right = 0; right < nums.size(); right ++){
                cnt[nums[right]] ++;
                while (cnt[0] > k)
                {
                    cnt[nums[left]] --;
                    if (cnt[nums[left]] == 0) cnt.erase(nums[left]);
                    left ++;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };

