#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
            int ans = 0;
            int a = capacityA, b = capacityB;
            int left  = 0, right = plants.size() - 1;
            while (left < right)
            {
                if (a < plants[left]){
                    ans ++;
                    a = capacityA;
                }
                a -= plants[left];
                left += 1;

                if (b < plants[right]){
                    ans ++;
                    b = capacityB;
                }
                b -= plants[right];
                right -= 1;
            }
            if (left == right && max(a, b) < plants[left]) ans ++;
            return ans;
        }
    };