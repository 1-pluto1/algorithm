class Solution:
    def isHappy(self, n: int) -> bool:
        def get_sum(n):
            _sum = 0
            while n > 0:
                _sum += (n % 10) ** 2
                n //= 10
            return  _sum
        
        set1 = set()
        while True:
            total_sum = get_sum(n)
            if total_sum == 1:
                return True
            if total_sum in set1:
                return False
            else:
                set1.add(total_sum)
            n = total_sum