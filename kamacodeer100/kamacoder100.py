# dfs
direction = [[0, 1], [0, -1], [1, 0], [-1, 0]]
count = 0

def dfs(grid, visited, x, y):
    global count
    for i, j in direction:
        next_x = x + i
        next_y = y + j
        if next_x < 0 or next_x >= len(grid) or next_y < 0 or next_y >= len(grid[0]):
            continue
        if not visited[next_x][next_y] and grid[next_x][next_y] == 1:
            visited[next_x][next_y] = True
            count += 1
            dfs(grid, visited, next_x, next_y)

n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(map(int, input().split())))
visited = [[False] * m for _ in range(n)]

result = 0

for i in range(n):
    for j in range(m):
        if not visited[i][j] and grid[i][j] == 1:
            visited[i][j] = True
            count = 1
            dfs(grid, visited, i, j)
            result = max(result, count)

print(result)


# bfs

from collections import deque

direction = [[0, 1], [0, -1], [1, 0], [-1, 0]]
count = 0

def bfs(grid, visited, x, y):
    global count
    que = deque()
    que.append([x, y])
    while que:
        cur_x, cur_y = que.popleft()
        for i, j in direction:
            next_x = cur_x + i
            next_y = cur_y + j
            if next_x < 0 or next_x >= len(grid) or next_y < 0 or next_y >= len(grid[0]):
                continue
            if not visited[next_x][next_y] and grid[next_x][next_y] == 1:
                visited[next_x][next_y] = True
                count += 1
                que.append([next_x, next_y])
                




n, m = map(int, input().split())
grid = []
result = 0
for i in range(n):
    grid.append(list(map(int, input().split())))

visited = [[False] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if grid[i][j] == 1 and not visited[i][j]:
            count = 1
            visited[i][j] = True
            bfs(grid, visited, i, j)
            result = max(result, count)
print(result)


