#  Bellman_ford算法
n, m = map(int, input().split())
edges = []
for _ in range(m):
    p1, p2, val = map(int, input().split())
    edges.append([p1, p2, val])

minDist = [float('inf')] * (n + 1)
minDist[1] = 0

for i in range(1, n):
    update = False
    for p1, p2, val in edges:
        if minDist[p1] != float('inf') and minDist[p1] + val < minDist[p2]:
            minDist[p2] = minDist[p1] + val
            update = True
    if not update:
        break
if minDist[-1] == float('inf'):
    print("unconnected")
else:
    print(minDist[-1])


# spfa
import collections

def main():
    n, m = map(int, input().strip().split())
    edges = [[] for _ in range(n + 1)]
    for _ in range(m):
        src, dest, weight = map(int, input().strip().split())
        edges[src].append([dest, weight])
    
    minDist = [float("inf")] * (n + 1)
    minDist[1] = 0
    que = collections.deque([1])
    visited = [False] * (n + 1)
    visited[1] = True
    
    while que:
        cur = que.popleft()
        visited[cur] = False
        for dest, weight in edges[cur]:
            if minDist[cur] != float("inf") and minDist[cur] + weight < minDist[dest]:
                minDist[dest] = minDist[cur] + weight
                if visited[dest] == False:
                    que.append(dest)
                    visited[dest] = True
    
    if minDist[-1] == float("inf"):
        return "unconnected"
    return minDist[-1]

if __name__ == "__main__":
    print(main())