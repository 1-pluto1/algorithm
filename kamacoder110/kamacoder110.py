def judge(s1, s2):
    count = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            count += 1
    return count == 1


if __name__=='__main__':
    n = int(input())
    beginstr,endstr=map(str,input().split())
    if beginstr==endstr:
        print(0)
        exit()
    strlist=[]
    for i in range(n):
        strlist.append(input())

    visit = [False for _ in range(n)]

    queue = [[beginstr, 1]]
    while queue:
        str, step = queue.pop(0)
        if judge(str, endstr):
            print(step + 1)
            exit()
        for i in range(n):
            if visit[i] == False and judge(strlist[i], str):
                visit[i] = True
                queue.append([strlist[i], step + 1])
    print(0)