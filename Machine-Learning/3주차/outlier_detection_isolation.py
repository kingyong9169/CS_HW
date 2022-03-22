import numpy as np # 모듈을 import
import pandas as pd
from sklearn.ensemble import IsolationForest
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

n_samples = 500 # 샘플 500개
outliers_fraction = 0.05 # 이상치 결함을 0.05
n_outliers = int(outliers_fraction * n_samples) # 이상치 결함과 샘플을 곱하여 n이상치를 구한다.
n_inliers = n_samples - n_outliers # 샘플 - 이상치를 계산하여 n inliers를 구한다.
blobs_params = dict(random_state=0, n_samples=n_inliers, n_features=2) # 랜덤 상태, 샘플, 특징을 파라미터로 dict함수로 계싼한 값을 blobs_params에 넣는다.
X = make_blobs(centers=[[0, 0], [4, 3]], # 중앙, 군집화 수치, blobs_params를 마라미터로 blob 함수를 실행하여 X에 넣는다.
               cluster_std=0.5,
               **blobs_params)[0]
rng = np.random.RandomState(42) # 랜덤함수의 랜덤 상태를 계산하여 rng에 넣는다.
X = np.concatenate([X, rng.uniform(low=-6, high=6, size=(n_outliers, 2))], axis=0) # X, rng를 균일화한 값을 붙여넣어 X를 구한다.

iForest = IsolationForest(n_estimators=20, verbose=2) # estimator를 20, verbose를 2로 IsolationForest함수를 실행한 값을 구한다.
iForest.fit(X) # iForest X를 fit한다.

pred = iForest.predict(X) # iForest를 X로 얘측하여 pred를 구한다.
plt.scatter(X[:, 0], X[:, 1], c=pred, cmap='RdBu') # 그래플 그린다.
plt.show()

pred_scores = -1 * iForest.score_samples(X) # iForest의 점수 샘플을 음수화한 값을 구한다.
plt.scatter(X[:, 0], X[:, 1], c=pred_scores, cmap='RdBu') # 그래프를 그린다.
plt.colorbar(label='Simplified Anomaly Score')
plt.show()