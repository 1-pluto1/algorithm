#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> map;
            for(int i = 0; i < nums.size(); i++){
                auto iter = map.find(target - nums[i]);
                if(iter != map.end()){
                    return {i, iter->second};
                }
                map.insert({nums[i], i});
            }
            return {};
        }
    };
    
    
// 灵神题单 常用数据结构 枚举


#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); i++){
                auto iter = map.find(target - nums[i]);
                if (iter != map.end()){
                    return {i, iter->second};
                }
                map.insert({nums[i], i});
            }
            return {};
        }
    };