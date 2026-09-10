Ax1=int(input())
Ay1=int(input())
Ax2=int(input())
Ay2=int(input())
Bx1=int(input())
By1=int(input())
Bx2=int(input())
By2=int(input())

# A contains B

if Ax1 <= Bx1 and Ay1 <= By1 and Bx2 <= Ax2 and By2 <= Ay2:
    print("A")
else:
    print("B")