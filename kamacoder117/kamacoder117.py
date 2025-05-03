from collections import deque, defaultdict

def topoligical_sort(n, edges):
    inDegree = [0] * n
    umap = defaultdict(list)

    for s, t in edges:
        inDegree[t] += 1
        umap[s].append(t)
    
    queue = deque([i for i in range(n) if inDegree[i] == 0])

    result = []

    while queue:
        cur = queue.popleft()
        result.append(cur)
        for file in umap[cur]:
            inDegree[file] -= 1
            if inDegree[file] == 0:
                queue.append(file)
    
    if len(result) == n:
        print(" ".join(map(str, result)))
    else:
        print(-1)

if __name__ == "__main__":
    n, m = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(m)]
    topoligical_sort(n, edges)