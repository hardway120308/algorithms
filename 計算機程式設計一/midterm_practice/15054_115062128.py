start_position = 0

# target
x = int(input())
# wall
y = int(input())
# hammer
z = int(input())

if x < y:
    print(abs(x - start_position))
elif z < y:
    print(abs(z - start_position) + abs(z - x))
else:
    print(-1)
