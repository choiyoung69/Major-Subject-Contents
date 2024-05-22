import pandas as pd
import numpy as np

def NN_work(x):
    W = np.array([0.4, -0.1, 0.5])
    b = -0.5
    seta = 0

    v = np.sum(x*W) + b
    if(v>seta):
        y = 1
    else:
        y = 0

    return y

ds = np.array(
    [[0.3, 0.1, 0.8],
    [.5, 0.6, 0.3],
    [0.1, 0.2, 0.1],
    [0.8, 0.7, 0.7],
    [0.5, 0.5, 0.5]]
)

for i in range(len(ds)):
    print(NN_work(ds[i, :]))


input = np.array([0.5, 0.8, 0.2])

w1 = 0.4
w2 = 0.7
w3 = 0.8
for i in range(1, 6):
    w = np.array([w1, w2, w3])
    error = 1- np.sum(w * input)
    w1 = w1 + 0.5*error*input[0]
    w2 = w2 + 0.5*error*input[1]
    w3 = w3 + 0.5*error*input[2]

    print(i, " 번쨰 ")
    print("error: %.3f" %error)
    print("w1: %.3f" %w1)
    print("w2: %.3f" %w2)
    print("w3: %.3f" %w3)
    

