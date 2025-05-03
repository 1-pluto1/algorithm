#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            sort(potions.begin(), potions.end());
            for (int &x : spells){
                long long target = (success - 1) / x;
                if (target < potions.back()){
                    x = potions.end() - upper_bound(potions.begin(), potions.end(), (int)target);
                } else {
                    x = 0;
                }
            }
            return spells;
        }
    };