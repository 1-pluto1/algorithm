#include<bits/stdc++.h>
using namespace std;


// 第一种方法，使用辅助数组
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // [i][j] -> [j][n - 1 - i]
        int n = matrix.size();
        vector<vector<int>>& temp = matrix;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                matrix[j][n - 1 - i] = temp[i][j];
            }
        }
    }
};

// 第二种方法，原地旋转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // [i][j] -> [j][n - 1 - i]
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < (n + 1) / 2; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};