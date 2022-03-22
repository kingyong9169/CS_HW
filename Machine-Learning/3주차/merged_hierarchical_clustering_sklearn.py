from sklearn.datasets import make_blobs # 모듈 import
from sklearn.cluster import AgglomerativeClustering
import numpy as np
from matplotlib import pyplot as plt

X, Y = make_blobs(n_samples=2000, n_features=2, centers=8, cluster_std=2.0) # 샘플을 2000개, 2개의 특징, 8개의 centers, 2.0을 군집화으로 blob을 만든다.
plt.scatter(X[:,0], X[:,1], s=4) # 그래프를 그린다.
plt.title('Generated Data')
plt.show()

Z = AgglomerativeClustering(n_clusters=8, linkage='complete') # 8개의 군집화, 연결을 파라미터로 agglomerativeClustering을 만들어 Z에 넣는다.
P = Z.fit_predict(X) # Z를 X로 예측하여 P에 넣는다.
colormap = np.array(['r', 'g', 'b', 'k', 'y', 'c', 'm', 'orange']) # 컬러맵을 만든다.
plt.scatter(X[:,0], X[:,1], s=4, c=colormap[P]) # 그래프를 그린다.
plt.title('Clustering results')
plt.show()
