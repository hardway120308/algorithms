res = []
N = 0
forbidden = [False] * 25
graph = ["."] * 25


def can_place(i, choice):
    """
    只檢查放上去會不會違反規則，不放置
    檢查graph而不是forbidden, 因爲forbidden會含有因爲棋子而被禁止的空格子
    """
    r = i // 5
    c = i % 5
    if choice == "H":
        # 攻擊同一行，同一列
        for j in range(5):
            if graph[r * 5 + j] != "." or graph[j * 5 + c] != ".":
                return False
    elif choice == "K":
        # 攻擊同一個對角線者（（主要對角線、次要對角線）
        for j in range(25):
            nr = j // 5
            nc = j % 5
            # 行差 = 列差 iff 同在主或副對角線
            if abs(nr - r) == abs(nc - c) and graph[j] != ".":
                return False
    elif choice == "R":
        # 攻擊以i爲中心的3x3方格，以及同一行，同一列
        for j in range(5):
            if graph[r * 5 + j] != "." or graph[j * 5 + c] != ".":
                return False
        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < 5 and 0 <= nc < 5 and graph[nr * 5 + nc] != ".":
                    return False
    return True


def place(i, choice):
    """放置棋子, 並標記被攻擊的格子在forbidden中"""
    r = i // 5
    c = i % 5
    forbidden[i] = True
    if choice == "H":
        for j in range(5):
            forbidden[r * 5 + j] = True
            forbidden[j * 5 + c] = True
    elif choice == "K":
        for j in range(25):
            nr = j // 5
            nc = j % 5
            if abs(nr - r) == abs(nc - c):
                forbidden[j] = True
    elif choice == "R":
        #  和 H 相同
        for j in range(5):
            forbidden[r * 5 + j] = True
            forbidden[j * 5 + c] = True
        # 九宮格
        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < 5 and 0 <= nc < 5:
                    forbidden[nr * 5 + nc] = True


def dfs(i, n):
    """
    從第i個格子開始
    已經放了n個棋子
    繼續放剩下的棋子
    """
    global forbidden
    if n == N:
        res.append("".join(graph))
        return

    for j in range(i, 25):
        for choice in ["H", "K", "R"]:
            if graph[j] == "." and not forbidden[j] and can_place(j, choice):
                tmp = forbidden.copy()
                place(j, choice)
                graph[j] = choice
                dfs(j, n + 1)
                forbidden = tmp
                graph[j] = "."


def main():
    global N, graph
    N = int(input())
    S = input()
    graph = list(S)
    for i in range(25):
        if graph[i] != ".":
            place(i, graph[i])
    dfs(0, 0)
    print("\n".join(res))


if __name__ == "__main__":
    main()
