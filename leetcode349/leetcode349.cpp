#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> res;
        int hash[1010];
        for (int num : nums1) hash[num] = 1;
        for (int num: nums2){
            if (hash[num] == 1){
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());

    }
};