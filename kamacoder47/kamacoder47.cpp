// 朴素dijkstra
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);

    minDist[start] = 0;
    for (int i = 1; i <= n; i++){
        int minVal = INT_MAX;
        int cur = 1;

        for (int v = 1; v <= n; v++){
            if (!visited[v] && minDist[v] < minVal){
                minVal = minDist[v];
                cur = v;
            }
        }

        visited[cur] = true;

        for (int v = 1; v <= n; v++){
            if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]){
                minDist[v] = minDist[cur] + grid[cur][v];
            }
        }
    }

    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;
}

// dijkstra堆优化版本

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>

using namespace std;

class mycomparison{
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
        return lhs.second > rhs.second;
    }
};

struct Edge
{
    int to;
    int val;
    Edge(int t, int w): to(t), val(w) {}
};

int main(){
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<list<Edge>> grid(n + 1);

    for (int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2, val));
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n + 1, INT_MAX);

    vector<bool> visited(n + 1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;

    pq.push(pair<int, int>(start, 0));

    minDist[start] = 0;

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (visited[cur.first]) continue;

        visited[cur.first] = true;

        for (Edge edge : grid[cur.first]){
            if (!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]){
                minDist[edge.to] = minDist[cur.first] + edge.val;
                pq.push(pair<int, int>(edge.to, minDist[edge.to]));
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;
}