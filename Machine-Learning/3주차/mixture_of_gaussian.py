import numpy as np # 모듈 import
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm
from sklearn import mixture

n_samples = 600 # 샘플은 600개
np.random.seed(0) # 랜덤 시드는 0
shifted_gaussian = np.random.randn(n_samples, 2) + np.array([15, 30]) # 샘플 랜덤함수 결과와 np의 배열을 더하여 shifted_gaussian을 구한다.
C1 = np.array([[0., -0.7], [1.5, .7]]) # 옆의 좌표로 배열을 만들어 C1에 넣는다.
stretched_gaussian1 = np.dot(np.random.randn(n_samples, 2), C1)+ np.array([-5, -25]) # 샘플 랜덤함수 결과를 점으로 나타낸 것과 np의 배열을 더하여 stretched_gaussian1를 구한다.
C2 = np.array([[0.5, 1.7], [-1.5, 0.5]]) # 옆의 좌표로 배열을 만들어 C1에 넣는다.
stretched_gaussian2 = np.dot(np.random.randn(n_samples, 2), C2)+ np.array([-15, 5]) # 샘플 랜덤함수 결과를 점으로 나타낸 것과 np의 배열을 더하여 stretched_gaussian2를 구한다.
X_train = np.vstack([shifted_gaussian, stretched_gaussian1, stretched_gaussian2]) # vstack에 shifted_gaussian, stretched_gaussian1, stretched_gaussian2를 넣어 X_train을 구한다.
plt.xlim(-50,50) # 옆의 범위로 xlim을 구한다.
plt.ylim(-50,50) # 옆의 범위로 ylim을 구한다.
plt.scatter(X_train[:, 0], X_train[:, 1], .8, color='r') # 그래프를 구한다.
plt.show()

clf = mixture.GaussianMixture(n_components=3, covariance_type='full') # 혼성 가우시안을 만들어 clf에 넣는다.
clf.fit(X_train) # X_train을 파라미터로 clf를 fit한다.
x = np.linspace(-50., 50.) # lin공간을 옆 좌표로 하여 x를 구한다.
y = np.linspace(-50., 50.) # lin공간을 옆 좌표로 하여 y를 구한다.
X, Y = np.meshgrid(x,y) # x, y를 파라미터로 meshgrid함수를 계산하여 X, Y를 구한다.
XX = np.array([X.ravel(), Y.ravel()]).T # X의 ravel, Y의 ravel을 배열로 구하여 XX를 계산한다.
Z = -clf.score_samples(XX) # XX값을 파라미터로 score샘플을 만들로 Z를 구한다.
Z = Z.reshape(X.shape) # Z를 X의 shape으로 재조정한다.

plt.contour(X, Y, Z, norm=LogNorm(vmin=1.0, vmax=1000.0), levels=np.logspace(0, 3, 10)) # X, Y, Z와 Log정규화 계산, 계층을 파라미터로 contour함수를 계산한다.
plt.scatter(X_train[:, 0], X_train[:, 1], .8, color='r') # 그래프를 그린다.
plt.title('Mixture of Gaussians')
plt.show()