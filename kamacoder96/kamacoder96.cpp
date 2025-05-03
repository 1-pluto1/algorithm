// 单源有限最短路
#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

int main() {
    int src, dst,k ,p1, p2, val ,m , n;
    
    cin >> n >> m;

    vector<vector<int>> grid;

    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid.push_back({p1, p2, val});
    }

    cin >> src >> dst >> k;

    vector<int> minDist(n + 1 , INT_MAX);
    minDist[src] = 0;
    vector<int> minDist_copy(n + 1); // 用来记录上一次遍历的结果
    for (int i = 1; i <= k + 1; i++) {
        minDist_copy = minDist; // 获取上一次计算的结果
        for (vector<int> &side : grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            // 注意使用 minDist_copy 来计算 minDist 
            if (minDist_copy[from] != INT_MAX && minDist[to] > minDist_copy[from] + price) {  
                minDist[to] = minDist_copy[from] + price;
            }
        }
    }
    if (minDist[dst] == INT_MAX) cout << "unreachable" << endl; // 不能到达终点
    else cout << minDist[dst] << endl; // 到达终点最短路径

}



// spfa
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
using namespace std;

struct Edge { //邻接表
    int to;  // 链接的节点
    int val; // 边的权重

    Edge(int t, int w): to(t), val(w) {}  // 构造函数
};


int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<list<Edge>> grid(n + 1); // 邻接表

    // 将所有边保存起来
    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        // p1 指向 p2，权值为 val
        grid[p1].push_back(Edge(p2, val));
    }
    int start, end, k;
    cin >> start >> end >> k;

    k++;

    vector<int> minDist(n + 1 , INT_MAX);
    vector<int> minDist_copy(n + 1); // 用来记录每一次遍历的结果

    minDist[start] = 0;

    queue<int> que;
    que.push(start); // 队列里放入起点

    int que_size;
    while (k-- && !que.empty()) {

        minDist_copy = minDist; // 获取上一次计算的结果
        que_size = que.size(); // 记录上次入队列的节点个数
        while (que_size--) { // 上一轮松弛入队列的节点，这次对应的边都要做松弛
            int node = que.front(); que.pop();
            for (Edge edge : grid[node]) {
                int from = node;
                int to = edge.to;
                int price = edge.val;
                if (minDist[to] > minDist_copy[from] + price) {
                    minDist[to] = minDist_copy[from] + price;
                    que.push(to);
                }
            }

        }
    }
    if (minDist[end] == INT_MAX) cout << "unreachable" << endl;
    else cout << minDist[end] << endl;

}
