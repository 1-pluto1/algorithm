// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int result =  INT32_MAX;
//         int sum = 0;
//         int i = 0;
//         int subLenth = 0;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             sum += nums[j];
//             while (sum >= target)
//             {
//                 subLenth = j - i + 1;
//                 result = result < subLenth ? result : subLenth;
//                 sum -= nums[i];
//                 i ++;
//             }
//         }
//         return result == INT32_MAX ? 0 : result;
//     }
// };

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans =  INT32_MAX;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left ++;
            }

        }
        return ans == INT32_MAX ? 0 : ans;
    }
};