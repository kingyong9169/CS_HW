import numpy as np # 모듈을 import한다.
import matplotlib.pyplot as plt
from sklearn.neighbors import LocalOutlierFactor

np.random.seed(42) # 랜덤 시드는 42
X_inliners = 0.3 * np.random.randn(100, 2) # np의 랜덤 함수를 실행한 값으로 데이터를 만든다.
X_inliners = np.r_[X_inliners + 2, X_inliners - 2] # X_inliners + 2, -2범위로 데이터를 만든다.
X_outliers = np.random.uniform(low = -4, high = 4, size = (20, 2)) # 파라미터 값을 균일화하여 랜덤 함수를 실행하여 데이터를 만든다.
X = np.r_[X_inliners, X_outliers] # X_inliners, X_outliers를 배열로 하여 X를 구한다.
n_outliers = len(X_outliers) # X_outliers의 길이를 구한다.
ground_truth = np.ones(len(X), dtype=int) # X의 길이, dtype을 파라미터로 ones함수를 실행한 값을 ground_truth에 넣는다.
ground_truth[-n_outliers:] = -1 # n_outliers을 음수화한 값을 인덱스로 ground_truth를 선언한다.

clf = LocalOutlierFactor(n_neighbors=20, contamination=0.1) # Local outlier 이상치 감지 모델 생성
y_pred = clf.fit_predict(X) # X를 파라미터로 clf를 계산하여 y_pred를 구한다.
n_errors = (y_pred != ground_truth).sum() # y_pred
X_scores = clf.negative_outlier_factor_ # 부정 이상치를 계산한

plt.title("Local Outlier Factor (LOF)") # 그래프를 그린다.
plt.scatter(X[:, 0], X[:, 1], color='k', s=3, label='Data points')
radius = (X_scores.max() - X_scores) / (X_scores.max() - X_scores.min()) # X_scores의 최대값 - X_scores / X_scores의 최대값 - X_scores의 최소값 계산
plt.scatter(X[:, 0], X[:, 1],s=1000 * radius, edgecolors='r', facecolors='none', label='Outlier scores') # 그래프 그리기
plt.axis('tight')
plt.xlim((-5, 5)) # xlim 범위를 -5에서 5
plt.ylim((-5, 5)) # ylim 범위를 -5에서 5
plt.xlabel("prediction eroors: %d" % (n_errors))
legend = plt.legend(loc = 'upper left') # legend를 지정
legend.legendHandles[0]._sizes = [10] # legend사이즈 지정
legend.legendHandles[1]._sizes = [20] # legend사이즈 지정
plt.show()