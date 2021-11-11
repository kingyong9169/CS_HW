# -*- coding: utf-8 -*-
import numpy as np


def Conv2D(X, W, w0, p=(0, 0), s=(1, 1)):
    n1 = X.shape[0] + 2*p[0]    # 패딩 반영
    n2 = X.shape[1] + 2*p[1]
    X_p = np.zeros(shape=(n1, n2))
    X_p[p[0]:p[0]+X.shape[0], p[1]:p[1]+X.shape[1]] = X    # 입력 X 복사
    res = []
    for i in range(0, int((X_p.shape[0] - W.shape[0])/s[0])+1, s[0]):
        res.append([])
        for j in range(0, int((X_p.shape[1] - W.shape[1])/s[1])+1, s[0]):
            X_s = X_p[i:i+W.shape[0], j:j+W.shape[1]]   # 컨볼루션 영역
            res[-1].append(np.sum(X_s*W) + w0)   # 컨볼루션
    return (np.array(res))


X = np.array([[1, 1, 1, 0, 0], [0, 1, 1, 1, 0], [
             0, 0, 1, 1, 1], [0, 0, 1, 1, 0], [0, 1, 1, 0, 0]])
W = np.array([[1, 0, 1], [0, 1, 0], [1, 0, 1]])
w0 = 1

conv = Conv2D(X, W, w0, p=(0, 0), s=(1, 1))
print('X = ', X)
print('\nW = ', W)
print('\n컨볼루션 결과 p=(0,0), s=(1,1) \n', conv)
conv = Conv2D(X, W, w0, p=(1, 1), s=(1, 1))
print('\n컨볼루션 결과 p=(1,1), s=(1,1) \n', conv)
conv = Conv2D(X, W, w0, p=(1, 1), s=(2, 2))
print('\n컨볼루션 결과 p=(1,1), s=(1,1) \n', conv)
