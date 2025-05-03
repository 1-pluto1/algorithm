n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(map(int, input().split())))

direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
result = 0

for i in range(n):
    for j in range(m):
        if grid[i][j] == 1:
            for x, y in direction:
                next_x = i + x
                next_y = j + y
                if next_x < 0 or next_y < 0 or next_y >= len(grid[0]) or next_x >= len(grid) or grid[next_x][next_y] == 0:
                    result += 1

print(result)