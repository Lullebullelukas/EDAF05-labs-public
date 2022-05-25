import numpy as np
import math

N, M, C, P = map(int,input().split(" "))
edges = np.zeros((M,), dtype=[('x', 'i4'), ('y', 'i4'), ('z', 'i4')])
adj = []
for i in range(N):
    adj.append([])


for i in range(M):
    u, v, c = map(int,input().split(" "))
    edges[i] = (u, v, c)
    adj[u].append(v)
    adj[v].append(u)
    
# print(adj)

removes = np.zeros(P, dtype=int)
for i in range(P): 
    removes[i] = int(input())

# s = node 0
# t = node N-1
def push(f,h,v,w,e,edges):
    edgeIndex = [index for index in range(len(edges)) if edges[index][0] == v and edges[index][1] == w]
    if w > v: #is this enough?
        #forward edge
        delta = math.min(e[v], edges[edgeIndex]-f[edgeIndex])
        f[edgeIndex] += delta
    else:
        # e=(v,w)
        delta = math.min(e[v], f[edgeIndex])
        f[edgeIndex] -= delta


# def relabel(f,h,v):

    


def preflow_push(edges):
    # set all to 0 but start which has value N
    h = np.zeros(N, dtype=int)
    h[0] = N
    # set all edges including s to c(s,v)
    f = np.zeros(M, dtype=int)
    e = np.zeros(N, dtype=int)
    iLeft = []
    iLeft.append(0)
    for i in range(len(edges)):
        if 0 == edges[i][0]: 
            f[i] = edges[i][2]
            e[i] = edges[i][2]
            e[0] -= edges[i][2]
            iLeft.append(i)

    while len(iLeft) != 0:
        for i in adj[iLeft[-1]]:
            if h[iLeft[-1]] > h[i]:
                push(f,h,iLeft[-1],i,e,edges)
                break
        else:
            # relabel(f,h,iLeft[-1])
            h[iLeft[-1]] += 1
    return f[N-1]
        
print(preflow_push(edges))