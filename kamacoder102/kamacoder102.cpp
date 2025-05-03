// dfs
#include<iostream>
#include<vector>
using namespace std;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

void dfs(vector<vector<int>>& grid, int x, int y){
    grid[x][y] = 6;
    for (int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
        if (grid[nextx][nexty] == 0 || grid[nextx][nexty] == 6) continue;
        dfs(grid, nextx, nexty);
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        if (grid[i][0] == 1) dfs(grid, i, 0);
        if (grid[i][m - 1] == 1) dfs(grid, i, m - 1);
    }

    for (int j = 0; j < m; j++){
        if (grid[0][j] == 1) dfs(grid, 0, j);
        if (grid[n - 1][j] == 1) dfs(grid, n - 1, j);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1) grid[i][j] = 0;
            if (grid[i][j] == 6) grid[i][j] = 1;
        }
    }

     for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}




// bfs
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void bfs(vector<vector<int>>& grid, int x, int y){
    queue<pair<int, int>> que;
    que.push({x, y});
    grid[x][y] = 6;
    while(!que.empty()){
        pair<int, int> cur = que.front();que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (int i = 0; i < 4; i++){
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
                continue;
            }
            if (grid[nextx][nexty] == 1){
                que.push({nextx, nexty});
                grid[nextx][nexty] = 6;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        if (grid[i][0] == 1) bfs(grid, i, 0);
        if (grid[i][m - 1] == 1) bfs(grid, i, m - 1);
    }
    for (int j = 0; j < m; j++){
        if (grid[0][j] == 1) bfs(grid, 0, j);
        if (grid[n - 1][j] == 1) bfs(grid, n - 1, j);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1) grid[i][j] = 0;
            if (grid[i][j] == 6) grid[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}