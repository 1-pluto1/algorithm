# dfs

# direction = [[0, 1], [1, 0], [0, -1], [-1, 0]]

# def dfs(grid, visited, x, y):
#     for i, j in direction:
#         next_x = x + i
#         next_y = y + j

#         if next_x < 0 or next_x >= len(grid) or next_y < 0 or next_y >= len(grid[0]):
#             continue
#         if not visited[next_x][next_y] and grid[next_x][next_y] == 1:
#             visited[next_x][next_y] = True
#             dfs(grid, visited, next_x, next_y)

# if __name__ == '__main__':
#     n, m = map(int, input().split())
#     grid = []
#     for i in range(n):
#         grid.append(list(map(int, input().split())))
#     visited = [[False] * m for _ in range(n)]

#     res = 0

#     for i in range(n):
#         for j in range(m):
#             if grid[i][j] == 1 and not visited[i][j]:
#                 res += 1
#                 visited[i][j] = True
#                 dfs(grid, visited, i, j)

#     print(res)

# bfs

from collections import deque
directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
def bfs(grid, visited, x, y):
    que = deque([])
    que.append([x,y])
    while que:
        cur_x, cur_y = que.popleft()
        for i, j in directions:
            next_x = cur_x + i
            next_y = cur_y + j
            if next_y < 0 or next_x < 0 or next_x >= len(grid) or next_y >= len(grid[0]):
                continue
            if not visited[next_x][next_y] and grid[next_x][next_y] == 1: 
                visited[next_x][next_y] = True
                que.append([next_x, next_y])

def main():
    n, m = map(int, input().split())
    grid = []
    for i in range(n):
        grid.append(list(map(int, input().split())))
    visited = [[False] * m for _ in range(n)]
    res = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1 and not visited[i][j]:
                res += 1
                bfs(grid, visited, i, j)
    print(res)

if __name__ == "__main__":
    main()