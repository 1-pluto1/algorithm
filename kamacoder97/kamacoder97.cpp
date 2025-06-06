// floyd多源最短路问题

// 三维数组

#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(){
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<vector<int>>> grid(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10005)));

    for (int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1][p2][0] = val;
        grid[p2][p1][0] = val;
    }

    // floyd开始
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k][k - 1] + grid[k][j][k - 1]);

            }
        }
    }

    int z, start, end;
    cin >> z;
    while (z--)
    {
        cin >> start >> end;
        if (grid[start][end][n] == 10005) cout << -1 << endl;
        else cout << grid[start][end][n] << endl;
    }
    
}


// 二维数组

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 10005));

    for (int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
        grid[p2][p1] = val;
    }

    // floyd启动
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            }
        }
    }

    int z, start, end;
    cin >> z;
    while (z--)
    {
        cin >> start >> end;
        if (grid[start][end] == 10005) cout << -1 << endl;
        else cout << grid[start][end] << endl;
    }
    
}