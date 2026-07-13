N = int(input())

while (N != 0):
    v = list(map(str,input().split()))
    lastR = lastC = lastH = -1
    res = N+1

    for i, c in enumerate(v):
        if (c == "R"): lastR = i
        elif (c == 'C'): lastC = i
        else: lastH = i
        if (lastR != -1 and lastC != -1 and lastH != -1): res = min(res,i-min(lastR,lastC,lastH)+1)
    
    if res != N+1: print(res)
    else: print("NO SE PUEDE")

    N = int(input())

