class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        martix = [[0] * n for _ in range(n)]
        row, col = 0, 0
        index = 0
        for i in range(n * n):
            martix[row][col] = i + 1
            nextRow, nextCol = row + directions[index][0], col + directions[index][1]
            if nextRow < 0 or nextRow >= n or nextCol < 0 or nextCol >= n or martix[nextRow][nextCol] != 0:
                index = (index + 1) % 4
            row += directions[index][0]
            col += directions[index][1]
        return martix