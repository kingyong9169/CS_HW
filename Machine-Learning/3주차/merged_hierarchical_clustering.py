from sklearn.datasets import make_blobs # 모듈 import
from scipy.spatial.distance import pdist
from scipy.cluster.hierarchy import linkage
from scipy.cluster.hierarchy import dendrogram
import numpy as np
from matplotlib import pyplot as plt

X, Y = make_blobs(n_samples=25, n_features=2, centers=3, cluster_std=1.5) # 샘플을 25개, 2개의 특징, 3개의 centers, 1.5을 군집화으로 blob을 만든다.
colormap = np.array(['r', 'g', 'b']) # 컬러맵을 만든다.
plt.scatter(X[:,0], X[:,1], c=colormap[Y]) # 그래프를 그린다.
plt.title('Generated Data')
plt.show()

Xdist = pdist(X, metric='euclidean') # pdist함수로 거리 행렬 계산하여 Xdist를 구한다.
Z = linkage(Xdist, method='ward') # ward 연결을 통한 계층적 군집화하여 Z를 구한다.
Zd = dendrogram(Z) # Z로 dendrogram을 그린다.
plt.title('Dendrogram') # 그래프를 그린다.
plt.show()
