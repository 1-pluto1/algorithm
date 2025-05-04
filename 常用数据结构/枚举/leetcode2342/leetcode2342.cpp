#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int ans = -1;
            int mx[90] {};
            for (int num: nums){
                int s = 0;
                for (int x = num; x != 0; x /= 10){
                    s += x % 10;
                }
                if (mx[s]){
                    ans = max(ans, mx[s] + num);
                }
                mx[s] = max(mx[s], num);
            }
            return ans;

        }
    };