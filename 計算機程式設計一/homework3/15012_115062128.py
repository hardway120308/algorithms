def dot(a, b):
    res = 0
    for i in range(len(a)):
        res += a[i] * b[i]

    return res


def linear(x, W, b):
    res = []
    for i in range(len(W)):
        res.append(dot(W[i], x) + b[i])

    return res


def relu(x):
    return [max(val, 0) for val in x]


def argmax(x):
    maxidx = 0
    for i in range(len(x)):
        if x[i] > x[maxidx]:
            maxidx = i
    return maxidx


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
