// dfs

// #include <iostream>
// #include<bits/stdc++.h>

// using namespace std;

// int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

// void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
//     for (int i = 0; i < 4; i++){
//         int nextx = x + dir[i][0];
//         int nexty = y + dir[i][1];

//         if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty > grid[0].size()){
//             continue;
//         }

//         if (!visited[nextx][nexty] && grid[nextx][nexty] == 1){
//             visited[nextx][nexty] = true;
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
//                 visited[i][j] = true;
//                 result ++;
//                 dfs(grid, visited, i, j);
//             }
//         }
//     }
//     cout << result << endl;
// }


// bfs

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; 
void bfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    while(!que.empty()) {
        pair<int ,int> cur = que.front(); que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (int i = 0; i < 4; i++) {
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 越界了，直接跳过
            if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
                que.push({nextx, nexty});
                visited[nextx][nexty] = true; 
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                result++; 
                bfs(grid, visited, i, j); 
            }
        }
    }

    cout << result << endl;
}