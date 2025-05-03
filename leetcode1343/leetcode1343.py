class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        ans = _sum = 0
        for i, num in enumerate(arr):
            _sum += num
            if i < k - 1:
                continue
            if _sum >= k * threshold:
                ans += 1
            _sum -= arr[i - k + 1]
        return ans