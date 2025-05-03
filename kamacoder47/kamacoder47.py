# 朴素dijkstra算法
import sys
INT_MAX = sys.maxsize

n, m = map(int, input().split())
grip = [[INT_MAX] * (n + 1) for _ in range(n + 1)]

for i in range(m):
    p1, p2, val = map(int, input().split())
    grip[p1][p2] = val

start = 1
end = n

visited = [False] * (n + 1)
miniDist = [INT_MAX] * (n + 1)

miniDist[start] = 0

for i in range(1, n + 1):
    minVal = INT_MAX
    cur = 1
    for v in range(1, n + 1):
        if not visited[v] and miniDist[v] < minVal:
            minVal = miniDist[v]
            cur = v
    
    visited[cur] = True

    for v in range(1, n + 1):
        if not visited[v] and grip[cur][v] != INT_MAX and miniDist[cur] + grip[cur][v] < miniDist[v]:
            miniDist[v] = miniDist[cur] + grip[cur][v]
        

if miniDist[end] == INT_MAX:
    print(-1)
else:
    print(miniDist[end])


#  dijkstra堆优化版本

import heapq

class Edge:
    def __init__(self, to, val):
        self.to = to
        self.val = val

def dijkstra(n, m, edges, start, end):
    grid = [[] for _ in range(n + 1)]
    for p1, p2, val in edges:
        grid[p1][p2] = val
    
    miniDist = [float('inf')] * (n + 1)
    visited = [False] * (n + 1)

    pq = []
    heapq.heappush(pq, (0, start))
    miniDist[start] = 0

    while pq:
        cur_dist, cur_node = heapq.heappop(pq)

        if visited[cur_node]:
            continue
        visited[cur_node] = True

        for edge in grid[cur_node]:
            if not visited[edge.to] and cur_dist + edge.val < miniDist[edge.to]:
                miniDist[edge.to] = cur_dist + edge.val
                heapq.heappush(pq, (miniDist[edge.to], edge.to))
    return -1 if miniDist[end] == float('inf') else miniDist[end]

n, m = map(int, input().split())

edges = [tuple(map(int, input().split())) for _ in range(m)]
start = 1
end = n
result = dijkstra(n, m, edges, start, end)
print(result)