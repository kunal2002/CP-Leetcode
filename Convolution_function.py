import numpy as np
a = [7,8,5,52,82,98,120]
b = [528,720,324,114]
if len(a) < len(b):
    hey = np.ones(len(b) - len(a), dtype=int)
    a = np.append(a,hey)
if len(b) < len(a):
    hey = np.ones(len(a) - len(b), dtype=int)
    b = np.append(b,hey)
ctr = 1
n = len(a) + len(b)
convo = np.zeros(n - 1,dtype=int)
b = np.flip(b)
for i in range(0,n):
    if i < len(a):
        for j in range(0, ctr):
            convo[i] += a[j] * b[len(b) - ctr + j]
        if i + 1 < len(a):
            ctr = ctr + 1
    else:
        ctr = ctr - 1
        for j in range(0, ctr):
            convo[i] += a[len(a) - ctr + j] * b[j]
print(convo)
b = np.flip(b)
print(np.convolve(a,b))
