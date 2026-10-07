def main():
    n, q, direction = map(int, input().split())
    pure_dict = input()
    # 建立 char: Index的table
    rank = {ch: i for i, ch in enumerate(pure_dict)}

    data = [input() for _ in range(n)]

    # key function 回傳要比較的項目
    # 即key把char轉換成在rank中的順序
    def key(s):
        return [rank[ch] for ch in s]

    data.sort(key=key, reverse=direction == 0)

    out = []
    for _ in range(q):
        k = int(input())
        out.append(data[k])

    print("\n".join(out))


if __name__ == "__main__":
    main()
