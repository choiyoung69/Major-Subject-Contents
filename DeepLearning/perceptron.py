import numpy as np

def SIGMOID(x):
    return 1/(1+np.exp(-x))


X = np.array([0.5, 0.8, 0.2])
w = np.array([0.4, 0.7, 0.8])
d = 1
alpha = 0.5

for i in range(50):
    v = np.sum(w * X)
    y = SIGMOID(v)
    e = d - y
    print("error ", i, e)
    w = w + alpha*y*(1-y)*e*X


from sklearn import datasets
import random

def SLP_SGD(tr_X, tr_y, alpha, rep):
    n = tr_X.shape[1] * tr_y.shape[1]
    random.seed = 123
    w = random.sample(range(1, 100), n)
    w = (np.array(w) - 50)/100
    w = w.reshape(tr_X.shape[1], -1)
    
    for i in range(rep):
        for k in range(tr_X.shape[0]):
            x = tr_X[k, :]
            v = np.matmul(x, w)
            y = SIGMOID(v)
            e = tr_y[k, :] - y
            e = (alpha * y * (1-y) * e).reshape(1, 3)
            x = x.reshape(4, )
            w = w + (np.matmul(e , x)).reshape(4, 3)

        print("error ", i, np.mean(e))
    return w
iris = datasets.load_iris()
X = iris.data
target = iris.target

num = np.unique(target, axis=0)
num = num.shape[0]
y = np.eye(num)[target]
W = SLP_SGD(X, y , alpha=0.01, rep=1000)


pred = np.zeros(X.shape[0])
for i in range(X.shape[0]):
    v = np.matmul(X[i, :], W)
    y = SIGMOID(v)
    pred[i] = np.argmax(y)
    print("target, predict", target[i], pred[i])

print("accuracy: ", np.mean(pred==target))