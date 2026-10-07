def dot(a, b):
    # TODO
    ans = 0
    for i in range(len(a)):
        ans += a[i] * b[i]
    return ans


def linear(x, W, b):
    # TODO
    ans = []
    for i in range(len(W)):
        ans.append(dot(x, W[i]) + b[i])
    return ans


def relu(x):
    # TODO
    return [max(0, i) for i in x]


def argmax(x):
    # TODO
    return x.index(max(x))


def neural_network(x, W1, b1, W2, b2):
    h = linear(x, W1, b1)
    h = relu(h)

    y = linear(h, W2, b2)

    return argmax(y)


D, H, C = map(int, input().split())

W1 = []
for _ in range(H):
    W1.append(list(map(int, input().split())))

b1 = list(map(int, input().split()))

W2 = []
for _ in range(C):
    W2.append(list(map(int, input().split())))

b2 = list(map(int, input().split()))

Q = int(input())

for _ in range(Q):
    x = list(map(int, input().split()))
    print(neural_network(x, W1, b1, W2, b2))
