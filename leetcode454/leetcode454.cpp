#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            unordered_map<int,int> map;
            int res = 0;
            for(auto a : nums1){
                for(auto b : nums2){
                    map[a + b]++;
                }
            }
            for(auto a : nums3){
                for(auto b : nums4){
                    auto iter = map.find(0 - a - b);
                    if(iter != map.end()){
                        res += map[0 - a - b]; 
                    }
                }
            }
            return res;
        }
    };