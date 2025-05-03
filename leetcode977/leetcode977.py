class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        k = len(nums)
        res = [0] * k
        i, j = 0, k - 1
        for p in range(k - 1, -1, -1):
            x = nums[i] * nums[i]
            y = nums[j] * nums[j]
            if x > y:
                res[p] = x
                i += 1
            else:
                res[p] = y
                j -= 1
        return res