n = int(input())
preSum = [0] * n
for i in range(n):
    num = int(input())
    if i == 0:
        preSum[i] = num
    else:
        preSum[i] = preSum[i - 1] + num
while True:
    try:
        a, b = map(int, input().split())
        if a == 0:
            print(preSum[b])
        else:
            print(preSum[b] - preSum[a - 1])
    except:
        break