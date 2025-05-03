#include<bits/stdc++.h>
using namespace std;

class Solution {
    int low_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
    public:
        int searchInsert(vector<int>& nums, int target) {
            int ans = low_bound(nums, target);
            return ans;
        }
    };