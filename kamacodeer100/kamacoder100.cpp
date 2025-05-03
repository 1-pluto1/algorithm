// dfs版本一

// #include<vector>
// #include<iostream>

// using namespace std;

// int count;
// int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

// void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
//     for (int i = 0; i < 4; i++){
//         int nextx = x + dir[i][0];
//         int nexty = y + dir[i][1];

//         if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
//             continue;
//         }
//         if (!visited[nextx][nexty] && grid[nextx][nexty] == 1){
//             visited[nextx][nexty] = true;
//             count++;
//             dfs(grid, visited, nextx, nexty);
//         }

//     }
// }

// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> grid(n, vector<int>(m, 0));
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cin >> grid[i][j];
//         }
//     }

//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     int result = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             if (!visited[i][j] && grid[i][j] == 1){
//                 count = 1; 
//                 visited[i][j] = true;
//                 dfs(grid, visited, i, j);
//                 result = max(result, count);
//             }
//         }
//     }

//     cout << result << endl;
// }


// dfs版本二

// #include<iostream>
// #include<vector>
// using namespace std;

// int count;
// int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
// void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
//     if (visited[x][y] || grid[x][y] == 0) return;
//     visited[x][y] = true;
//     count++;
//     for (int i = 0; i < 4; i++){
//         int nextx = x + dir[i][0];
//         int nexty = y + dir[i][1];
//         if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
//         dfs(grid, visited, nextx, nexty);
//     }
// }


// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> grid(n, vector<int>(m, 0));
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cin >> grid[i][j];
//         }
//     }

//    vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
//     int result = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             if (!visited[i][j] && grid[i][j] == 1){
//                 count = 0;
//                 dfs(grid, visited, i, j);
//                 result = max(result, count);
//             }
//         }
//     }
//     cout << result << endl;
// }



// bfs
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
private:
    int count;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
        queue<int> que;
        que.push(x);
        que.push(y);
        visited[x][y] = true;
        count ++;
        while (!que.empty())
        {
            int xx = que.front();
            que.pop();
            int yy = que.front();
            que.pop();
            for (int i = 0; i < 4; i++){
                int nextx = xx + dir[i][0];
                int nexty = yy + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
                    continue;
                }
                if (!visited[nextx][nexty] && grid[nextx][nexty] == 1){
                    visited[nextx][nexty] = true;
                    count++;
                    que.push(nextx);
                    que.push(nexty);
                }
            }
        }
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int result = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!visited[i][j] && grid[i][j] == 1){
                    count = 0;
                    bfs(grid, visited, i, j);
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};