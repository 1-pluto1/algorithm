# dfs

direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
count = 0

def dfs(grid, x, y):
    grid[x][y] = 0
    global count
    count += 1

    for i, j in direction:
        next_x = x + i
        next_y = y + j
        if next_x < 0 or next_y < 0 or next_y >= len(grid[0]) or next_x >= len(grid):
            continue
        if grid[next_x][next_y] == 0:
            continue
        dfs(grid, next_x, next_y)

n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(map(int, input().split())))

for i in range(n):
    if grid[i][0] == 1:
        dfs(grid, i, 0)
    if grid[i][m - 1] == 1:
        dfs(grid, i, m - 1)

for j in range(m):
    if grid[0][j] == 1:
        dfs(grid, 0, j)
    if grid[n - 1][j] == 1:
        dfs(grid, n - 1, j)

count = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 1:
            dfs(grid, i, j)
print(count)


# bfs
from collections import deque
direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
count = 0

def bfs(grid, x, y):
    que = deque()
    que.append((x, y))
    grid[x][y] = 0
    global count
    count += 1
    while que:
        cur_x, cur_y = que.popleft()
        for i, j in direction:
            next_x = cur_x + i
            next_y = cur_y + j
            if next_x < 0 or next_y < 0 or next_y >= len(grid[0]) or next_x >= len(grid):
                continue
            if grid[next_x][next_y] == 0:
                continue
            que.append((next_x, next_y))
            grid[next_x][next_y] = 0
            count += 1

n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(map(int, input().split())))

for i in range(n):
    if grid[i][0] == 1:
        bfs(grid, i, 0)
    if grid[i][m - 1] == 1:
        bfs(grid, i, m - 1)

for j in range(m):
    if grid[0][j] == 1:
        bfs(grid, 0, j)
    if grid[n - 1][j] == 1:
        bfs(grid, n - 1, j)

count = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 1:
            bfs(grid, i, j)
print(count)
