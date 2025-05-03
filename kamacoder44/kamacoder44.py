data = input().strip().split()
n, m = int(data[0]), int(data[1])

matrix = [[None] * m for _ in range(n)]
for i in range(n):
    row = input().split()
    for j in range(m):
        matrix[i][j] = int(row[j])

N = 100
s = [[0] * (N + 10) for _ in range(N + 10)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] +  matrix[i - 1][j - 1]


ans = float('inf')

for i in range(1, n):
    x = abs(s[n][m] - 2 * s[i][m])
    ans = min(ans, x)
    
for j in range(1, m):
    x = abs(s[n][m] - 2 * s[n][j])
    ans = min(ans, x)

print(ans)