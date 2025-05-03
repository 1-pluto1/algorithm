class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rows = len(matrix)
        columns = len(matrix[0])
        visit = [[False]*columns for _ in range(rows)]
        res = [0] * (rows * columns)
        row, column = 0, 0
        directions = [[0,1],[1,0],[0,-1],[-1,0]]
        index = 0
        for i in range(rows * columns):
            res[i] = matrix[row][column]
            visit[row] [column] = True
            nextRow = row + directions[index][0]
            nextColumn = column + directions[index][1]
            if nextRow < 0 or nextRow >= rows or nextColumn < 0 or nextColumn >= columns or visit[nextRow][nextColumn]:
                index = (index + 1) % 4
            row += directions[index][0]
            column += directions[index][1]
        return res
        