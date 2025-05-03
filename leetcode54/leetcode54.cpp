#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }

        vector<vector<int>> diretions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res(matrix.size() * matrix[0].size());
        vector<vector<bool>> visit(matrix.size(), vector<bool>(matrix[0].size()));
        int index = 0;
        int row = 0;
        int col = 0;
        int cnt = 0; 
        while (cnt < matrix.size() * matrix[0].size()){
            res[cnt] = matrix[row][col];
            visit[row][col] = true;
            cnt ++;

            int nextRow = row + diretions[index][0];
            int nextCol = col + diretions[index][1];

            if(nextRow < 0 || nextRow >= matrix.size() || nextCol < 0 || nextCol >= matrix[0].size()){
                index = (index + 1) % 4;
            }

            row = row + diretions[index][0];
            col = col + diretions[index][1];
        }
        return res;
    }
};




class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int index = 0;
        int cnt = 0;
        vector<vector<bool>> visit(matrix.size(),vector<bool>(matrix[0].size()));
        vector<int> res(matrix.size() * matrix[0].size());
        int row = 0;
        int column = 0;
        while(cnt < matrix.size()*matrix[0].size()){
            res[cnt] = matrix[row][column];
            visit[row][column] = true;
            cnt ++ ;

            int nextRow = row + directions[index][0];
            int nextColumn = column + directions[index][1];
            if(nextRow < 0 || nextRow >= matrix.size() || nextColumn < 0 || nextColumn >= matrix[0].size() || visit[nextRow][nextColumn]){
                index = (index + 1) % 4;
            } 
            row = row + directions[index][0];
            column = column + directions[index][1];
        }
        return res;
    }
};