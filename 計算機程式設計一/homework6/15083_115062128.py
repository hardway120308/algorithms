dp = {}
MODULE = (int)(1e9 + 7)


def L(x: int) -> int:
    if dp.get(x, -1) != -1:
        return dp[x]
    if x == 0:
        return 1
    else:
        x_div_57 = L(x // 57) % MODULE
        x_div_67 = L(x // 67) % MODULE
        x_div_77 = L(x // 77) % MODULE
        ans = (x_div_57 + x_div_67 + x_div_77) % MODULE
        dp[x] = ans
        return dp[x]


t = int(input())
for _ in range(t):
    x = int(input())
    print(L(x))
