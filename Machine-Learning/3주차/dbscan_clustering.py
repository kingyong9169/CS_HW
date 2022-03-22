from sklearn.datasets import make_moons # 모듈 import
from sklearn.cluster import DBSCAN
import numpy as np
from matplotlib import pyplot as plt
X, Y = make_moons(n_samples=1000, noise=0.05) # 샘플 1000개, noise 0.05로 moon을 만든다.

plt.title('Half moons') # 그래프 출력
plt.scatter(X[:,0], X[:,1])
plt.show()
dbs = DBSCAN(eps=0.1) # eps를 0.1로 DBSCAN기법을 사용한 결과를 dbs에 저장
Z = dbs.fit_predict(X) # dbs를 X축으로 예측한 값을 Z에 넣는다.

colormap = np.array(['r', 'b']) # r, b를 배열로 한 결과를 colormap에 저장
plt.scatter(X[:,0], X[:,1], c=colormap[Z]) # 컬러맵 그래프를 그린다.
plt.title('DBSCAN for half moons')
plt.show()
