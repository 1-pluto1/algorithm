#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] > 0) return res;
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while(right > left){
                    int sum = nums[i] + nums[left] + nums[right];
                    if(sum > 0) right --;
                    if(sum < 0) left ++;
                    if(sum == 0){
                        res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        while(right > left && nums[left] == nums[left + 1]) left ++;
                        while(right > left && nums[right] == nums[right - 1]) right --;
                        left ++;
                        right --;
                    }
                }
            }
            return res;
        }
    };