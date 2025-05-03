str1 = input()
ans = ""
for ss in str1:
    if ord("0") <= ord(ss) <= ord("9"):
        ans += "number"
    else:
        ans += ss
print(ans)