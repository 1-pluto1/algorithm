# dfs
import collections

directions = [[-1, 0], [0, 1], [0, -1], [1, 0]]
area = 0

def dfs(i, j, grid, visited, num):
    global area
    
    if visited[i][j]:
        return
    
    visited[i][j] = True
    grid[i][j] = num  # 标记岛屿号码
    area += 1
    
    for x, y in directions:
        new_x = i + x
        new_y = j + y
        if (
            0 <= new_x < len(grid)
            and 0 <= new_y < len(grid[0])
            and grid[new_x][new_y] == "1"
        ):
            dfs(new_x, new_y, grid, visited, num)



def main():
    global area
    
    N, M = map(int, input().strip().split())
    grid = []
    for i in range(N):
        grid.append(input().strip().split())
    visited = [[False] * M for _ in range(N)]
    rec = collections.defaultdict(int)
    
    cnt = 2
    for i in range(N):
        for j in range(M):
            if grid[i][j] == "1":
                area = 0
                dfs(i, j, grid, visited, cnt)
                rec[cnt] = area  # 纪录岛屿面积
                cnt += 1
    
    res = 0
    for i in range(N):
        for j in range(M):
            if grid[i][j] == "0":
                max_island = 1  # 将水变为陆地，故从1开始计数
                v = set()
                for x, y in directions:
                    new_x = i + x
                    new_y = j + y
                    if (
                        0 <= new_x < len(grid)
                        and 0 <= new_y < len(grid[0])
                        and grid[new_x][new_y] != "0"
                        and grid[new_x][new_y] not in v  # 岛屿不可重复
                    ):
                        max_island += rec[grid[new_x][new_y]]
                        v.add(grid[new_x][new_y])
                res = max(res, max_island)

    if res == 0:
        return N * M  # 无水的情况
    return res
    
if __name__ == "__main__":
    print(main())



# bfs
import collections

directions = [[-1, 0], [0, 1], [0, -1], [1, 0]]
area = 0

def bfs(i, j, grid, visited, num):
    global area
    
    if visited[i][j] or grid[i][j] == "0":
        return
    que = collections.deque()
    que.append((i, j))    
    visited[i][j] = True
    grid[i][j] = num  # 标记岛屿号码
    area = 1
    while que:
        cur_x, cur_y = que.popleft()
        for i, j in directions:
            new_x = i + cur_x
            new_y = j + cur_y

            if new_x < 0 or new_y < 0 or new_y >= len(grid[0]) or new_x >= len(grid):
                continue
            if grid[new_x][new_y] != "1":
                continue
            que.append((new_x, new_y))
            visited[new_x][new_y] = True
            grid[new_x][new_y] = num
            area += 1
    return

def main():
    global area
    
    N, M = map(int, input().strip().split())
    grid = []
    for i in range(N):
        grid.append(input().strip().split())
    visited = [[False] * M for _ in range(N)]
    rec = collections.defaultdict(int)
    
    cnt = 2
    for i in range(N):
        for j in range(M):
            if grid[i][j] == "1":
                area = 0
                bfs(i, j, grid, visited, cnt)
                rec[cnt] = area  # 纪录岛屿面积
                cnt += 1
    
    res = 0
    for i in range(N):
        for j in range(M):
            if grid[i][j] == "0":
                max_island = 1  # 将水变为陆地，故从1开始计数
                v = set()
                for x, y in directions:
                    new_x = i + x
                    new_y = j + y
                    if (
                        0 <= new_x < len(grid)
                        and 0 <= new_y < len(grid[0])
                        and grid[new_x][new_y] != "0"
                        and grid[new_x][new_y] not in v  # 岛屿不可重复
                    ):
                        max_island += rec[grid[new_x][new_y]]
                        v.add(grid[new_x][new_y])
                res = max(res, max_island)

    if res == 0:
        return N * M  # 无水的情况
    return res
    
if __name__ == "__main__":
    print(main())


