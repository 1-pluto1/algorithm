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
        int maximumCount(vector<int>& nums) {
            int index1 = lower_bound(nums, 1);
            int pos = nums.size() - index1;
            int index2 = lower_bound(nums, 0);
            int neg = index2;
            return max(pos, neg);
        }
    };