#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long interchangeableRectangles(vector<vector<int>>& rectangles) {
            long long ans = 0;
            unordered_map<double, int> cnt;
            for (auto& rectangle : rectangles){
                ans += cnt[(double)rectangle[0] / rectangle[1]]++;
            }
            return ans;
        }
    };