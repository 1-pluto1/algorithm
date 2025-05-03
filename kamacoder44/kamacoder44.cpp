#include<iostream>
#include<cmath>
using namespace std;
const int N = 110;
int s[N][N];
int n, m;
int ans = 1e9;
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    
    for (int i = 1; i < n; i++){
        int x = abs(s[n][m] - 2 * s[i][m]);
        ans = min(ans, x);
    }
    for (int j = 1; j < m; j++){
        int x = abs(s[n][m] - 2 * s[n][j]);
        ans = min(ans, x);
    }
    cout << ans;
}
int main(){
    cin >> n >> m;
    solve();
    return 0;
}