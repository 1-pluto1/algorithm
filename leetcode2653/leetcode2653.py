class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        ans = [0] * (n - k + 1)
        cnt = [0] *  101
        for num in nums[:k - 1]:
            cnt[num] += 1
        for i, (in_, out) in enumerate(zip(nums[k - 1:], nums)):
            cnt[in_] += 1
            left = x
            for j in range(-50, 0):
                left -= cnt[j]
                if left <= 0:
                    ans[i] = j
                    break
            cnt[out] -= 1
        return ans