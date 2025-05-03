# dfs
direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]

def dfs(grid, visited, x, y):
    if visited[x][y]:
        return 
    
    visited[x][y] = True

    for i, j in direction:
        next_x = x + i
        next_y = y + j
        if next_x < 0 or next_y < 0 or next_y >= len(grid[0]) or next_x >= len(grid):
            continue
        if grid[next_x][next_y] < grid[x][y]:
            continue
        dfs(grid, visited, next_x, next_y)

n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(map(int, input().split())))


firstvisited = [[False] * m for _ in range(n)]
secondvisited = [[False] * m for _ in range(n)]

for i in range(n):
    dfs(grid, firstvisited, i, 0)
    dfs(grid, secondvisited, i, m - 1)

for j in range(m):
    dfs(grid, firstvisited, 0, j)
    dfs(grid, secondvisited, n - 1, j)


for i in range(n):
    for j in range(m):
        if firstvisited[i][j] and secondvisited[i][j]:
            print(f"{i} {j}")



# bfs
from collections import deque
direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]

def bfs(grid, visited, x, y):
    if visited[x][y]:
        return 
    que = deque()
    que.append((x, y))
    visited[x][y] = True

    while que:
        cur_x, cur_y = que.popleft()
        for i, j in direction:
            next_x = cur_x + i
            next_y = cur_y + j
            if next_x < 0 or next_y < 0 or next_y >= len(grid[0]) or next_x >= len(grid):
                continue
            if grid[next_x][next_y] < grid[cur_x][cur_y] or visited[next_x][next_y]:
                continue
            que.append((next_x, next_y))
            visited[next_x][next_y] = True
    return

n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(map(int, input().split())))

firstvisited = [[False] * m for _ in range(n)]
secondvisited = [[False] * m for _ in range(n)]

for i in range(n):
    bfs(grid, firstvisited, i, 0)
    bfs(grid, secondvisited, i, m - 1)

for j in range(m):
    bfs(grid, firstvisited, 0, j)
    bfs(grid, secondvisited, n - 1, j)

for i in range(n):
    for j in range(m):
        if firstvisited[i][j] and secondvisited[i][j]:
            print(f"{i} {j}")
