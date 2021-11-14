from numpy import mgrid, random # 모듈 불러오기
from scipy import *
from scipy.linalg import norm, pinv
from matplotlib import pyplot as plt
import numpy as np


class RBF: # RBF망
    def __init__(self, indim, numCenters, outdim): # 초기화 함수
        self.indim = indim # indim 초기화
        self.outdim = outdim # outdim 초기화
        self.numCenters = numCenters # numCenters 초기화
        self.centers = [random.uniform(-1, 1, indim) # centers에 i부터 numCenters번 반복하여 indim의 랜덤 형태로 배열을 초기화한다
                        for i in range(numCenters)]
        self.beta = 8 # beta 초기화
        self.W = random.random((self.numCenters, self.outdim)) # 가중치는 numCenters, outdim의 랜덤 값으로 초기화한다

    def basisFunc(self, c, d): # 기본함수
        assert len(d) == self.indim # d의 길이에 indim을 넣는다.
        return np.exp(-self.beta * norm(c - d) ** 2) # np의 exp함수 형태로 리턴

    def activationFunc(self, X): # 활성화 함수
        G = np.zeros((X.shape[0], self.numCenters), float) # X, numCenters값을 0에 가깝게 하여 G에 넣는다.
        for ci, c in enumerate(self.centers): # centers의 ci, c를 하나씩 뽑아서
            for xi, x in enumerate(X): # X 중 xi, x를 하나씩 뽑아서
                G[xi, ci] = self.basisFunc(c, x) # G의 xi, ci에 기본 함수에 c, x를 파라미터로한 값을 넣는다.
        return G # G를 리턴한다

    def train(self, X, Y): # 학습함수
        rnd_idx = random.permutation(X.shape[0])[:self.numCenters] # rnd_idx에 X를 랜덤 순열로한 값의 numCenters인덱스에 있는 값을 넣는다.
        self.centers = [X[i, :] for i in rnd_idx] # centers에 rnd_idx에서 하나씩 반복한 인덱스 값을 X의 인덱스에 넣어서 배열을 만든다
        G = self.activationFunc(X) # X를 파라미터로 활성화함수로 만들어 그 결과를 G에 넣는다
        self.W = np.dot(pinv(G), Y) # 가중치에 pinv함수에 G를 파라미터로한 값을 파라미터로 dot 함수의 결과를 넣는다

    def predict(self, X): # 예측함수
        G = self.activationFunc(X) # X를 파라미터로 활성화함수를 G에 넣는다
        Y = np.dot(G, self.W) # G, W를 파라미터로 dot함수 결과를 Y에 넣는다
        return Y # Y를 리턴한다


n = 100 # n 선언
x = mgrid[-1:1:complex(0, n)].reshape(n, 1) # x선언
y = np.sin(3*(x+0.5)**3 - 1) # y 함수 선언

rbf = RBF(1, 10, 1) # RBF함수를 호출한다
rbf.train(x, y) # x, y값으로 학습시킨다
z = rbf.predict(x) # rbf의 예측함수 결과를 z에 저장한다

plt.figure(figsize=(6, 4)) # plt로 그린다
plt.plot(x, y, 'k-', label='ground truth')
plt.plot(x, z, 'r-', linewidth=2, label='prediction')
plt.plot(rbf.centers, np.zeros(rbf.numCenters), 'gs', label='centers of RBFs')

for c in rbf.centers: # rbf의 centers에서 처음부터 하나씩 반복한다
    cx = np.arange(c-0.7, c+0.7, 0.01) # c-0.7, c+0.7의 범위를 cs에 저장한다.
    cy = [rbf.basisFunc(np.array([cx_]), np.array([c])) for cx_ in cx] # cx에서 처음부터 하나씩 반복하여 기본함수에서 리턴한 값을 배열에 만들어 리턴한다.
    plt.plot(cx, cy, '-', color='gray', linewidth=0.2) # plt로 그린다.

plt.xlim(-1.2, 1.2) # plt로 그린다.
plt.legend()
plt.show()
