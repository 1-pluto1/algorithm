#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            int maxNum = n * n;
            int curNum = 1;
            vector<vector<int>> martix(n, vector<int>(n));
            int row = 0;
            int cloumn = 0;
            vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            int index = 0;
            while(curNum <= maxNum){
                martix[row][cloumn] = curNum;
                curNum ++;
                int nextRow = row + directions[index][0];
                int nextColumn = cloumn + directions[index][1];
    
                if(nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || martix[nextRow][nextColumn] != 0){
                    index = (index + 1) % 4;
                }
                row = row + directions[index][0];
                cloumn = cloumn + directions[index][1];
            }
            return martix;
        }
    };
