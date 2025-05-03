// prim算法

// #include<iostream>
// #include<vector>
// #include<climits>

// using namespace std;

// int main(){
//     int v, e;
//     int x, y, k;
//     cin >> v >> e;
    
//     vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));
//     while (e--)
//     {
//         cin >> x >> y >> k;
//         grid[x][y] = k;
//         grid[y][x] = k;
//     }
    
//     vector<int> minDist(v + 1, 10001);
//     vector<bool> isInTree(v + 1, false);

//     for (int i = 1; i < v; i++){
//         int cur = -1;
//         int minVal = INT_MAX;
//         for (int j = 1; j <= v; j++){
//             if (!isInTree[j] && minDist[j] < minVal){
//                 minVal = minDist[j];
//                 cur = j;
//             }
//         }
//         isInTree[cur] = true;


//         for (int j = 1; j <= v; j++){
//             if (!isInTree[j] && grid[cur][j] < minDist[j]){
//                 minDist[j] = grid[cur][j];
//             }
//         }
//     }
//     int result = 0;
//     for (int i = 2; i <= v; i++){
//         result += minDist[i];
//     }
//     cout << result << endl;
// }


// kruskal算法

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge
{
    int l, r, val;
};
int n = 10001;
vector<int> father(n, -1);

void init(){
    for (int i = 0; i < n; i++){
        father[i] = i;
    }
}

int find(int u){
    return u == father[u] ? u : father[u] = find(father[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}

int main(){
    int v, e;
    int v1, v2, val;
    vector<Edge> edges;
    int result_val = 0;
    cin >> v >> e;
    while (e--)
    {
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.val < b.val;
    });

    init();

    for (Edge edge : edges){
        int x = find(edge.l);
        int y = find(edge.r);

        if (x != y) {
            result_val += edge.val;
            join(x, y);
        }
    }
    cout << result_val << endl;
    return 0;
}