import numpy as np # 모듈 import
from matplotlib import pyplot as plt
from sklearn.datasets._samples_generator import make_blobs
from sklearn.cluster import KMeans

X, y = make_blobs(n_samples=300, centers=4, cluster_std=0.60, random_state=0) # 샘플을 300개, 4개의 centers, 0.6을 군집화, 랜덤 상태 0으로 blob을 만든다.
plt.scatter(X[:,0], X[:,1], s=4) # 그래프를 만든다.
plt.title('Generated Data')
plt.show()

kmeans = KMeans(n_clusters=4, init='k-means++', max_iter=300, n_init=10, random_state=0) # K means알고리즘을 사용하여 그 결과 값을 kmeans 변수에 넣는다.
pred_y = kmeans.fit_predict(X) # kmeans를 X로 예측하여 pred_y에 넣는다.
colormap = np.array(['c', 'g', 'b', 'm']) # 컬러맵을 만든다.
plt.scatter(X[:,0], X[:,1], s=4, c=colormap[pred_y]) # 그래프를 그린다.
plt.scatter(kmeans.cluster_centers_[:,0], kmeans.cluster_centers_[:,1], s=100, c='red')
plt.title('Clustering Results with Centers')
plt.show()