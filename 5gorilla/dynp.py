import numpy as np
letters = input().split(" ")
letter_dict = {}
for i in range(len(letters)):
    letter_dict[letters[i]] = i

costs = np.zeros((len(letters),len(letters)), dtype=int)
for i in range(len(letters)): 
    row = input().split(" ")
    for j in range(len(letters)):
        costs[i][j] = int(row[j])

# print(costs)

nQuery = int(input())
gap_cost = -4
for n in range(nQuery):
    strings = input().split(" ")
    s1 = strings[0]
    s2 = strings[1]
    D = np.zeros((len(s1)+1,len(s2)+1), dtype=int)
    for i in range(len(s2)+1):
        D[0][i] = gap_cost * i

    for j in range(len(s1)+1):
        D[j][0] = gap_cost * j

    for i in range(1, len(s1)+1):
        for j in range(1, len(s2)+1):
            match = D[i-1][j-1] + costs[letter_dict[s2[j-1]]][letter_dict[s1[i-1]]]
            gaps1 = D[i][j-1] + gap_cost
            gaps2 = D[i-1][j] + gap_cost
            D[i][j] = max(match, gaps1, gaps2)
    #score = D[len(s1)-1][len(s2)-1]      
    # print(D)
    # print(score)

    i = len(s1)
    j = len(s2)

    #traceback
    s1_align = ""
    s2_align = ""
    while i > 0 and j > 0:
        if D[i][j] - costs[letter_dict[s2[j-1]]][letter_dict[s1[i-1]]] == D[i-1][j-1]:
            s1_align = s1[i-1] + s1_align
            s2_align = s2[j-1] + s2_align
            i -= 1
            j -= 1
        elif D[i][j] - gap_cost == D[i][j-1]:
            s1_align = "*" + s1_align
            s2_align = s2[j-1] + s2_align
            j -= 1
        elif D[i][j] - gap_cost == D[i-1][j]:
            s1_align = s1[i-1] + s1_align
            s2_align = "*" + s2_align
            i -= 1
        else:
            print("oops")

    
    if j > 0:
        while j > 0:
            s1_align = "*" + s1_align
            s2_align = s2[j-1] + s2_align
            j -= 1
    elif i > 0:
        while i > 0:
            s1_align = s1[i-1] + s1_align
            s2_align = "*" + s2_align
            i -= 1

    print(s1_align, s2_align)
