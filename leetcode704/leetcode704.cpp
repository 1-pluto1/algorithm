#include<bits/stdc++.h>
using namespace std;

class Solution {
    int lower_bound(vector<int>& nums, int target){
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
    int search(vector<int>& nums, int target) {
        int ans = lower_bound(nums, target);
        if (ans == nums.size()) return -1;
        if (nums[ans] != target) return -1;
        return ans;
    }
};