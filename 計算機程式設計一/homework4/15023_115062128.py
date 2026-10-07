import sys

input = sys.stdin.readline


def spmul(d: list, pos: list, val: list, v: list) -> list:
    """
    d      為 對角線元素 \n
    pos[i] 為 第i 列的所有非零元素的行，除了對角線之外 \n
    val[i] 為 第i 列的所有非零元素的值，除了對角線之外 \n
    v      是 Av=X的v
    """
    n = len(d)
    res = [0.0] * n
    for i in range(n):
        s = d[i] * v[i]
        for j, a in zip(pos[i], val[i]):
            s += a * v[j]
        res[i] = s
    return res


def dot(v1: list, v2: list) -> float:
    s = 0.0
    for a, b in zip(v1, v2):
        s += a * b
    return s


def vec_add(v1: list, v2: list) -> list:
    return [a + b for a, b in zip(v1, v2)]


def vec_sub(v1: list, v2: list) -> list:
    return [a - b for a, b in zip(v1, v2)]


def vec_const_mul(c: float, v: list) -> list:
    return [c * x for x in v]


def CG(A_d: list, A_pos: list, A_val: list, b: list, x0: list, step: int) -> list:
    r = vec_sub(b, spmul(A_d, A_pos, A_val, x0))
    p = r[:]
    x = x0[:]

    for k in range(step):
        rT_mul_r = dot(r, r)
        A_pK = spmul(A_d, A_pos, A_val, p)
        pK_T_A_pK = dot(p, A_pK)
        alpha_k = rT_mul_r / pK_T_A_pK

        x = vec_add(x, vec_const_mul(alpha_k, p))
        r = vec_sub(r, vec_const_mul(alpha_k, A_pK))

        r_k1_T_r_k1 = dot(r, r)

        beta_k = r_k1_T_r_k1 / rT_mul_r
        p = vec_add(r, vec_const_mul(beta_k, p))

    return x


if __name__ == "__main__":
    n, step = map(int, input().split())

    b = list(map(int, input().split()))
    x0 = list(map(int, input().split()))
    d = list(map(int, input().split()))

    pos = [[] for _ in range(n)]
    val = [[] for _ in range(n)]

    for i in range(n):
        tmp = list(map(int, input().split()))
        m = tmp[0]

        if m == 0:
            continue

        arr = tmp[1:]
        pos[i] = arr[:m]
        val[i] = arr[m : 2 * m]
    ans_x = CG(d, pos, val, b, x0, step)
    for x in ans_x:
        print(f"{x:.5f}", end=" ")
