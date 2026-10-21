def enc(S):
    if len(S) == 0:
        return ""
    mid = (len(S) - 1) // 2
    return shift(S[mid], len(S)) + enc(S[:mid]) + enc(S[mid + 1 :])


def shift(c, k):
    # ord(c)-97 belong to [0,25], so we can use mod 26 to shift the character
    return chr((ord(c) - 97 + k) % (26) + 97)


S = input()
print(enc(S))
