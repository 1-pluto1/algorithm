class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        s = [0, 0]
        max_s1 = 0
        for i, (c, g) in enumerate(zip(customers, grumpy)):
            s[g] += c
            if i < minutes - 1:
                continue
            max_s1 = max(max_s1, s[1])
            if grumpy[i - minutes + 1] == 1:
                s[1] -= customers[i - minutes + 1]
        return s[0] + max_s1