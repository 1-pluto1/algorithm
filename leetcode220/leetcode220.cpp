#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
            int n = nums.size();
            set<int> rec;
            for (int i = 0; i < n; i++){
                auto iter = rec.lower_bound(max(nums[i], INT_MIN + valueDiff) - valueDiff);
                if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - valueDiff) + valueDiff){
                    return true;
                }
                rec.insert(nums[i]);
                if (i >= indexDiff){
                    rec.erase(nums[i - indexDiff]);
                }
            }
            return false;
        }
    };