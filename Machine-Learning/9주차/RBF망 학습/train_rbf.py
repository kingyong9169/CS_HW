import random
from scipy import *
from scipy.linalg import norm, pinv
from matplotlib import pyplot as plt
import numpy as np

class RBF:  # RBF클래스
    def __init__(self, indim, numCenters, outdim):  # 초기화 함수
        self.indim = indim; self.outdim = outdim; self.numCenters = numCenters  # indim, outdim, numCenters 초기화
        self.centers = [random.uniform(-1, 1, indim) for i in range(numCenters)]    # indim을 정규화한 배열로 초기화
        self.beta = 8   # bet = 8
        self.W = random.random((self.numCenters, self.outdim))  # 난수로 초기화

    def basisFunc(self, c, d):  # basis 함수 정의
        assert len(d) == self.indim     # d의 길이와 indim이 같을 경우
        return np.exp(-self.beta * norm(c - d) ** 2)    # beta * norm(c - d) ** 2의 exp값 반환

    def activationFunc(self, X):    # activation 함수 정의
        G = np.zeros((X.shape[0], self.numCenters), float)  # 0으로 구성된 배열 만들기
        for ci, c in enumerate(self.centers):   # centers 반복
            for xi, x in enumerate(X):  # X 반복
                G[xi, ci] = self.basisFunc(c, x)    # 각각 basis호출하여 exp값 대입
        return G    # G리턴

    def train(self, X, Y):  # train함수 정의
        rnd_idx = random.permutation(X.shape[0])[:self.numCenters]  # numCenters수만큼 난수 배열
        self.centers = [X[i, :] for i in rnd_idx]   # rnd_idx로 배열
        G = self.activationFunc(X)      # activation 호출
        self.W = np.dot(pinv(G), Y)     # pinv(G) * Y 행렬곱

    def predict(self, X):   # predict함수 정의
        G = self.activationFunc(X)  # activation실행한 값
        Y = np.dot(G, self.W)   # G * W 행렬곱
        return Y    # Y리턴

n = 100

x = np.mgrid[-1:1:complex(0, n)].reshape(n, 1)  # shape 맞춘 후 reshape
y = np.sin(3 * (x + 0.5) ** 3 - 1)  # sin계산

rbf = RBF(1, 10, 1) # RBF호출
rbf.train(x, y) # 학습하기
z = rbf.predict(x)  # preduct 실행

plt.figure(figsize=(6, 4))    # 피규어
plt.plot(x, y, 'k-', label='ground truth')  # ground truth plot 그리기
plt.plot(x, z, 'r-', linewidth=2, label='prediction')  # prediction plot 그리기
plt.plot(rbf.centers, np.zeros(rbf.numCenters), 'gs', label='centers of RBFs')   # centers plot 그리기

for c in rbf.centers:   # rbf.centers의 요소 반복
    cx = np.arange(c-0.7, c+0.7, 0.01)  # 배열 형태로 반환
    cy = [rbf.basisFunc(np.array([cx_]), np.array([c])) for cx_ in cx]  # rbf의 basis와 [c] 형태의 배열 대입
    plt.plot(cx, cy, '-', color='gray', linewidth=0.2)  # plot 그리기

plt.xlim(-1.2, 1.2) # xlim -1.2, 1.2
plt.legend()    # legend
plt.show()  # 그래프 그리기