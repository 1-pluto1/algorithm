# floyd多源最短路问题

# 三维数组

max_int = 10005
n, m = map(int, input().split())

grid = [[[max_int] * (n + 1) for _ in range(n + 1)] for _ in range(n + 1)]

for _ in range(m):
    p1, p2, val = map(int, input().split())
    grid[p1][p2][0] = val
    grid[p2][p1][0] = val

# floyd
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k][k - 1] + grid[k][j][k - 1])

z = int(input())
for _ in range(z):
    start, end = map(int, input().split())

    if grid[start][end][n] == max_int:
        print(-1)
    else:
        print(grid[start][end][n])

# 二维数组

max_int = 10005

n, m = map(int, input().split())
grid = [[max_int] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    p1, p2, val = map(int, input().split())
    grid[p1][p2] = val
    grid[p2][p1] = val

# floyd启动
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j])

z = int(input())
for _ in range(z):
    start, end = map(int, input().split())
    if grid[start][end] == max_int:
        print(-1)
    else:
        print(grid[start][end])