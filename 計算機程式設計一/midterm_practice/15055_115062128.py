def rev(x):
    # reverse x
    # [::step] 爲設定間隔爲 -1 的切片，也就是說python會倒序讀取這個字串，然後再轉換成整數
    ans = str(x)[::-1]
    return int(ans)


t = int(input())

for _ in range(t):
    N, k = map(int, input().split())
    for _ in range(k):
        N = N + rev(N)
    if N == rev(N):
        print(N, "Yes")
    else:
        print(N, "No")
