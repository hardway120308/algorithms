from collections import OrderedDict, defaultdict


def getCount(formula: str, i: int):
    j = i
    count = 0
    while j < len(formula):
        if formula[j].isdigit():
            count *= 10
            count += (int)(formula[j])
            j += 1
        else:
            break

    if count == 0:
        count = 1

    return count, j


def parse(formula: str, i: int):
    ans = defaultdict(int)
    while i < len(formula):
        if formula[i].isupper():
            k = i + 1
            while k < len(formula):
                if formula[k].islower():
                    k += 1
                else:
                    break
            name = formula[i:k]

            count, j = getCount(formula, k)

            ans[name] += count
            # mode to next token
            i = j
        elif formula[i] == "(":
            inner, j = parse(formula, i + 1)
            count, k = getCount(formula, j)

            for key in inner:
                ans[key] += inner[key] * count
            i = k
        elif formula[i] == ")":
            i += 1
            return ans, i
        else:
            i += 1
    return ans, i


S = input()
(occurs, _) = parse(S, 0)

ordering = {
    "H": 1,
    "He": 2,
    "Li": 3,
    "Be": 4,
    "B": 5,
    "C": 6,
    "N": 7,
    "O": 8,
    "F": 9,
    "Ne": 10,
    "Na": 11,
    "Mg": 12,
    "Al": 13,
    "Si": 14,
    "P": 15,
    "S": 16,
    "Cl": 17,
    "Ar": 18,
    "K": 19,
    "Ca": 20,
    "Sc": 21,
    "Ti": 22,
    "V": 23,
    "Cr": 24,
    "Mn": 25,
    "Fe": 26,
    "Co": 27,
    "Ni": 28,
    "Cu": 29,
    "Zn": 30,
    "Ga": 31,
    "Ge": 32,
    "As": 33,
    "Se": 34,
    "Br": 35,
    "Kr": 36,
}

ordered_occurs = OrderedDict(sorted(occurs.items(), key=lambda item: ordering[item[0]]))

for k, v in ordered_occurs.items():
    print(k + ": " + (str)(v))
