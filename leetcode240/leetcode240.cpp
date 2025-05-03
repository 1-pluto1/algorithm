#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int  m = matrix.size();
            int n = matrix[0].size();
            if(target < matrix[0][0] || target > matrix[m - 1][n - 1]){
                return false;
            }
            int i = m - 1, j = 0;
            while(i >= 0 && j < n){
                if (matrix[i][j] > target){
                    i --;
                }else if (matrix[i][j] < target)
                {
                    j++;
                }else{
                    return true;
                }
            }
            return false;
    }
};