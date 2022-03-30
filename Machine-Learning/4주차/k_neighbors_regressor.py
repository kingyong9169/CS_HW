#KNN기반 회귀
import numpy as np
import matplotlib.pyplot as plt
from sklearn import neighbors
np.random.seed(0) # 난수 생성하기
X = np.sort(5*np.random.rand(40,1), axis = 0) # 정렬하기
T = np.linspace(0,5,500)[:, np.newaxis] # 선형 간격 벡터 생성
y = np.sin(X).ravel() # sin구하고 1차원으로

y[::5] += 1*(0.5 - np.random.rand(8)) #잡음 추가

n_neighbors = 5 # 이웃 수 = 5
for i, weights in enumerate(['uniform','distance']): # weight = uniform, distance
  knn = neighbors.KNeighborsRegressor(n_neighbors, weights=weights) # KNN 회귀 진행
  y_ = knn.fit(X,y).predict(T) # knn fit 진행

  plt.subplot(2, 1, i+1) # 서브 플롯구하기
  plt.scatter(X, y, color='darkorange',label='data') # 산점도 그리기
  plt.plot(T,y_,color='navy', label='rediction') # plot 구하기
  plt.axis('tight') # 축
  plt.legend()
  plt.title("KNeighbrosRegressor (k=%i, weights='%s')"%(n_neighbors, weights))

plt.tight_layout() # 서브플롯 파라미터 조정
plt.show() # 그래프 창 띄우기