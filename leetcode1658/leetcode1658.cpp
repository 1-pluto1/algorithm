#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
            long long ans = INT_MIN, left = 0, sum = 0;
            for (auto num : nums) sum += num;
            long long target = sum - x;
            if (target < 0) return -1;
            long long temp = 0;
            for (int right = 0; right < nums.size(); right ++){
                temp += nums[right];
                while (temp > target)
                {
                    temp -= nums[left];
                    left ++;
                }
                if (temp == target){
                    ans = max(ans, right - left + 1);
                }
            }
            return ans == INT_MIN ? -1 : nums.size() - ans;
        }
    };