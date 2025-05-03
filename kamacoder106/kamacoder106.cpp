#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int result = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1){
                for (int k = 0; k < 4; k++){
                    int x = i + direction[k][0];
                    int y = j + direction[k][1];

                    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0){
                        result++;
                    }
                }
            }
        }
    } 
    cout << result << endl;
}