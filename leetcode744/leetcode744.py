class Solution:
    def low_bound(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if (nums[mid] >= target):
                right = mid - 1
            else:
                left = mid + 1
        return left
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        ans = self.low_bound(letters, chr(ord(target) + 1))
        if ans == len(letters): return letters[0]
        return letters[ans]
