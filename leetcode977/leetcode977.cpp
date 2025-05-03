#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for (int i = 0, j = k; i <= j;)
        {
            if (nums[j] * nums[j] > nums[i] * nums[i]){
                result[k] = nums[j] * nums[j];
                j--;
            }
            else{
                result[k] = nums[i] * nums[i];
                i++;
            }
            k--;
        }
        return result;
        
    } 
};