# dfs

def dfs(graph, key, visited):
    if visited[key]:
        return
    visited[key] = True
    for neighbor in graph[key]:
        dfs(graph, neighbor, visited)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    m = int(data[1])

    graph = [[] for _ in range(n + 1)]

    index = 2
    for _ in range(m):
        s = int(data[index])
        t = int(data[index + 1])
        graph[s].append(t)
        index += 2
    
    visited = [False] * (n + 1)
    
    dfs(graph, 1, visited)

    for i in range(1, n + 1):
        if not visited[i]:
            print(-1)
            return
    
    print(1)

if __name__ == "__main__":
    main()


# bfs
from collections import deque
def bfs(graph, key, visited):
    if visited[key]:
        return
    que = deque()
    que.append(key)
    visited[key] = True
    while que:
        key = que.popleft()
        keys = graph[key]
        for key in keys:
            if not visited[key]:
                que.append(key)
                visited[key] = True
    
def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    m = int(data[1])

    graph = [[] for _ in range(n + 1)]

    index = 2
    for _ in range(m):
        s = int(data[index])
        t = int(data[index + 1])
        graph[s].append(t)
        index += 2
    
    visited = [False] * (n + 1)
    
    bfs(graph, 1, visited)

    for i in range(1, n + 1):
        if not visited[i]:
            print(-1)
            return
    
    print(1)

if __name__ == "__main__":
    main()