# prim算法
# v, e = list(map(int, input().strip().split()))

# graph = [[10001] * (v + 1) for _ in range(v + 1)]

# for _ in range(e):
#     x, y, w = list(map(int, input().strip().split()))
#     graph[x][y] = w
#     graph[y][x] = w

# visited = [False] * (v + 1)
# minDist = [10001] * (v + 1)

# for _ in range(1, v + 1):
#     min_val = 10002
#     cur = -1
#     for j in range(1, v + 1):
#         if visited[j] == False and minDist[j] < min_val:
#             cur = j
#             min_val = minDist[j]
#     visited[cur] = True
#     for j in range(1, v + 1):
#         if visited[j] == False and minDist[j] > graph[cur][j]:
#             minDist[j] = graph[cur][j]

# ans = 0
# for i in range(2, v + 1):
#     ans += minDist[i]
# print(ans)

# kruskal

class Edge:
    def __init__(self, l, r, val):
        self.l = l
        self.r = r
        self.val = val

n = 10001
father = list()

def init():
    global father
    father = list(range(n))

def find(u):
    if u != father[u]:
        father[u] = find(father[u])
    return father[u]
def join(u, v):
    u = find(u)
    v = find(v)
    if u != v:
        father[v] = u
def kruskal(v, edges):
    edges.sort(key = lambda edge: edge.val)
    init()
    result_val = 0

    for edge in edges:
        x = find(edge.l)
        y = find(edge.r)
        if x != y:
            result_val += edge.val
            join(x, y)
    return result_val



v, e = list(map(int, input().strip().split()))

edges = []
for _ in range(e):
    v1, v2, val = map(int, input().strip().split())
    edges.append(Edge(v1, v2, val))

result_val = kruskal(v, edges)
print(result_val)