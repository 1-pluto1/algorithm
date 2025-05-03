#include<bits/stdc++.h>
using namespace std;

class Solution {
    int lower_bound(vector<char>& letters, char target){
        int left = 0, right = letters.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] >= target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            int ans = lower_bound(letters, target + 1);
            if (ans == letters.size()) return letters[0];
            return letters[ans];
        }
    };