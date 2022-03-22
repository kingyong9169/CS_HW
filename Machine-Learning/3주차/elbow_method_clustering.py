from matplotlib import pyplot as plt # 모듈 import
from sklearn.datasets._samples_generator import make_blobs
from sklearn.cluster import KMeans

X, y = make_blobs(n_samples=300, centers=4, cluster_std=0.60, random_state=0) # 샘플을 300개, 4개의 centers, 0.6을 군집화, 랜덤 상태 0으로 blob을 만든다.
plt.scatter(X[:,0], X[:,1]) # 그래프를 그린다.
plt.show()

SSEs = [] # SSEs배열을 만든다.
for i in range(1, 11): # 범위는 1~11로 반복한다.
    kmeans = KMeans(n_clusters=i, init='k-means++', max_iter=300, n_init= 10, random_state=0) # K means알고리즘을 사용하여 그 결과 값을 kmeans 변수에 넣는다.
    kmeans.fit_predict(X) # kmeans에 X를 예측한다.
    SSEs.append(kmeans.inertia_) # SSE에 kmeans의 inertia를 추가한다.

plt.plot(range(1,11), SSEs, marker='o') # 그래프를 그린다.
plt.show()