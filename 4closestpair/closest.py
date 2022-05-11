import math


n = int(input())
p=[]
for i in range(n):
    line=input().split(" ")
    p.append((int(line[0]), int(line[1])))

Px = p.copy()
Py = p.copy()

Px.sort(key=lambda t:t[0])
Py.sort(key=lambda t:t[1])


def closest(Px, Py, n):
    print("n is", n)
    print("Px is " + str(Px))
    print("Py is " + str(Py))
    if n == 2:
        return math.sqrt((Px[0][0] - Px[0][1])**2 + (Py[0][0] - Py[0][1])**2)
    if n == 3:
        Lx=Px[0:2]
        Rx=Px[1:]
        Ly=Py[0:2]
        Ry=Py[1:]
        return min(closest(Lx,Ly,2), closest(Rx,Ry,2))
    Lx = Px[0:int(n/2)]
    Rx = Px[int(n/2):n]
    Ly = Py[0:int(n/2)]
    Ry = Py[int(n/2):n]
    # print(Lx)
    # print(Rx)
    # print(Ly)
    # print(Ry)
    return min(closest(Lx,Ly,len(Lx)),closest(Rx, Ry, len(Ry)))

print("{:.6f}".format(closest(Px,Py,n))) 