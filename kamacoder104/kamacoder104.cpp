// dfs
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int n, m;
int count;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark){
    if (visited[x][y] || grid[x][y] == 0) return;
    visited[x][y] = true;
    grid[x][y] = mark;
    count ++;
    for (int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];

        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
            continue;
        }

        dfs(grid, visited, nextx, nexty, mark);
    }
}

int main(){
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }


    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_map<int, int> gridNum;
    int mark = 2;
    bool isAllGrid = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 0) isAllGrid = false;
            if (!visited[i][j] && grid[i][j] == 1){
                count = 0;
                dfs(grid, visited, i, j, mark);
                gridNum[mark] = count;
                mark++;
            }
        }
    }

    if (isAllGrid){
        cout << n * m << endl;
        return 0;
    } 

    int result = 0;
    unordered_set<int> vistedGrid;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            count = 1;
            vistedGrid.clear();
            if (grid[i][j] == 0){
                for (int k = 0; k < 4; k++){
                    int neari = i + dir[k][0];
                    int nearj = j + dir[k][1];

                    if (neari < 0 || nearj < 0 || neari >= n || nearj >= m) continue;

                    if (vistedGrid.count(grid[neari][nearj])) continue;

                    count += gridNum[grid[neari][nearj]];

                    vistedGrid.insert(grid[neari][nearj]);
                }
            }
            result = max(result, count);
        }
    }
    cout << result << endl;
}




// bfs
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
int n, m;
int count;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark){
    if (visited[x][y] || grid[x][y] == 0) return;
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    grid[x][y] = mark;
    count = 1;
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 4; i++){
            int nextx = cur_x + dir[i][0];
            int nexty = cur_y + dir[i][1];

            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
                continue;
            }

            if (grid[nextx][nexty] != 1) continue;
            que.push({nextx, nexty});
            visited[nextx][nexty] = true;
            grid[nextx][nexty] = mark;
            count ++;
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


    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_map<int, int> gridNum;
    int mark = 2;
    bool isAllGrid = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 0) isAllGrid = false;
            if (!visited[i][j] && grid[i][j] == 1){
                count = 0;
                bfs(grid, visited, i, j, mark);
                gridNum[mark] = count;
                mark++;
            }
        }
    }

    if (isAllGrid){
        cout << n * m << endl;
        return 0;
    } 

    int result = 0;
    unordered_set<int> vistedGrid;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            count = 1;
            vistedGrid.clear();
            if (grid[i][j] == 0){
                for (int k = 0; k < 4; k++){
                    int neari = i + dir[k][0];
                    int nearj = j + dir[k][1];

                    if (neari < 0 || nearj < 0 || neari >= n || nearj >= m) continue;

                    if (vistedGrid.count(grid[neari][nearj])) continue;

                    count += gridNum[grid[neari][nearj]];

                    vistedGrid.insert(grid[neari][nearj]);
                }
            }
            result = max(result, count);
        }
    }
    cout << result << endl;
}