import math


n = int(input())
p=[]
for i in range(n):
    line=input().split(" ")
    p.append((int(line[0]), int(line[1])))

# print(p)

Px = p.copy()
Py = p
Px.sort(key=lambda b:b[0])
Py.sort(key=lambda b:b[1])

def dist(t_pair):
    return math.sqrt((t_pair[0][0]-t_pair[1][0])**2 + (t_pair[0][1]-t_pair[1][1])**2)

def closest(Px,Py,n):
    if n == 2:
        return min(dist(Px),dist(Py))
    if n == 3:
        Lx = Px[0:2]
        Rx = Px[1:]
        Ly = Py[0:2]
        Ry = Py[1:]
        return min(closest(Lx, Ly, 2), closest(Rx, Ry, 2))
    n = int(n/2)
    Lx = Px[0:n]
    Rx = Px[n:]
    Ly = Py[0:n]
    Ry = Py[n:]
    midX = Px[n-1:n+1] 
    midY = Py[n-1:n+1]
    return min(closest(Lx,Ly,len(Lx)), closest(Rx,Ry,len(Rx)),dist(midX),dist(midY))

print("{:.6f}".format(closest(Px,Py,n))) 
