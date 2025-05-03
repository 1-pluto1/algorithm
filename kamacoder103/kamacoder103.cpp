// dfs
#include<iostream>
#include<vector>

using namespace std;

int n, m;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    if (visited[x][y]) return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >=m) continue;

        if (grid[x][y] > grid[nextx][nexty]) continue;

        dfs(grid, visited, nextx, nexty);
    }
    return;
}

int main(){
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }


    vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
    vector<vector<bool>> secondBorder(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++){
        dfs(grid, firstBorder, i, 0);
        dfs(grid, secondBorder, i, m - 1);
    }

     for (int j = 0; j < m; j++){
        dfs(grid, firstBorder, 0, j);
        dfs(grid, secondBorder, n - 1, j);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (firstBorder[i][j] && secondBorder[i][j]) cout << i << " " << j << endl;
        }
    }
}


// bfs
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    if (visited[x][y]) return;
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    while (!que.empty())
    {
        pair<int, int> cur = que.front();que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (int i = 0; i < 4; i++){
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nextx >= n || nexty < 0 || nexty >=m) continue;

            if (grid[curx][cury] > grid[nextx][nexty] || visited[nextx][nexty]) continue;
            que.push({nextx, nexty});
            visited[nextx][nexty] = true;
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }


    vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
    vector<vector<bool>> secondBorder(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++){
        bfs(grid, firstBorder, i, 0);
        bfs(grid, secondBorder, i, m - 1);
    }

     for (int j = 0; j < m; j++){
        bfs(grid, firstBorder, 0, j);
        bfs(grid, secondBorder, n - 1, j);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (firstBorder[i][j] && secondBorder[i][j]) cout << i << " " << j << endl;
        }
    }
}