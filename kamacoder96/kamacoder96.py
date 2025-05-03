#  Bellman_ford算法
n, m = map(int, input().split())
edges = []
for _ in range(m):
    p1, p2, val = map(int, input().split())
    edges.append([p1, p2, val])

src, dst, k = map(int, input().split())
minDist = [float('inf')] * (n + 1)
minDist[src] = 0
minDist_copy = []

for i in range(1, k + 2):
    minDist_copy[:] = minDist[:]
    for p1, p2, val in edges:
        if minDist_copy[p1] != float('inf') and minDist_copy[p1] + val < minDist[p2]:
            minDist[p2] = minDist_copy[p1] + val
    
if minDist[dst] == float('inf'):
    print("unreachable")
else:
    print(minDist[dst])