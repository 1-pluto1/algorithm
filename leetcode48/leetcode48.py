# 第一种方法
class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # (i, j ) - > (j, n - 1 - i)
        tmp = copy.deepcopy(matrix)
        n = len(matrix)
        for i in range(n):
            for j in range(n):
                matrix[j][n - 1 - i] = tmp[i][j]


# 第二种方法
class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # (i, j ) - > (j, n - 1 - i)
        n = len(matrix)
        for i in range(n // 2):
            for j in range((n + 1) // 2):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[n - 1 - j][i]
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
                matrix[j][n - 1 - i] = tmp