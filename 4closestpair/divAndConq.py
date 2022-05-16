import math 

def dist(p1, p2):
    return math.sqrt(math.pow(p1[0]-p2[0], 2) + math.pow(p1[1]-p2[1], 2))

def slow_find_dist(P, n):
    min = 999999999.0 #hittade int float max, ska leta mer sen
    for i in range(n):
        for k in range(i+1,n):
            d = dist(P[i], P[k])
            if  d < min:
                min = d
    return min

def check_mid_region(S, j, delta):
    min = delta
    S.sort(key=lambda x:x[1]) #sort based on y-value
    for i in range(j):
        k = i + 1
        while k < j and (S[k][1] - S[i][1]) < min:
            d = dist(S[i], S[k])
            if d < min:
                min = d
            k += 1
    return min

def closest(Px, Py, n):
    if n <= 3:
        return slow_find_dist(Px, n)
    mid = int(n/2)

    Py1 = []
    Py2 = []
    midP = Px[mid]

    for i in range(n):
        if (Py[i][0] < midP[0] or (Py[i][0] == midP[0] and Py[i][1] < midP[1])) and len(Py1) < mid:
            Py1.append(Py[i])
        else:
            Py2.append(Py[i])

    d1 = closest(Px[:mid], Py1, mid)
    d2 = closest(Px[mid:], Py2, n-mid)
    delta = min(d1, d2)
    S = []
    j = 0
    for i in range(n):
        if abs(Py[i][0] - midP[0]) < delta:
            S.append(Py[i])
            j = j + 1
    return min(delta, check_mid_region(S, j, delta))

def main():
    n = int(input())
    P = []
    for i in range(n):
        line = input().split(" ")
        x, y = line
        P.append((int(x),int(y)))
    Px = P.copy()
    Px.sort()
    Py = P.copy()
    Py.sort(key = lambda x:x[1])
    print("{:.6f}".format(closest(Px,Py,n)))

main()
    
