from collections import Counter # 모듈 import
from sklearn.datasets import make_classification
from imblearn.over_sampling import SMOTE
from imblearn.under_sampling import RandomUnderSampler
from imblearn.pipeline import Pipeline
from matplotlib import pyplot
from numpy import where
X, y = make_classification(n_samples=10000, n_features=2, n_redundant=0, n_clusters_per_class=1, weights=[0.99], flip_y=0, random_state=1)
# 1000개 샘플, 2개 특징, 0redundatn, 클러스터 당 1 클래스, 0.99무게 등 파라미터로 분류기를 만들어 X, y에 저장

counter = Counter(y) # y를 카운팅하여 저장
print('generated data: %s'% counter) # 카운터를 출력한다.

for label, _ in counter.items(): # 카운터의 각 아이템마다
    row_ix = where(y == label)[0] # y가 라벨인 것의 0인덱스를 저장
    pyplot.scatter(X[row_ix, 0], X[row_ix, 1], label=str(label)) # X[row_ix, 0], X[rod_ix, 1], 라벨을 파라미터로 흩뿌려 그린다.
pyplot.legend()
pyplot.show() # 그린다.

over = SMOTE(sampling_strategy=0.1) # 샘플링 전략을 0.1로 SMOTE를 만든다.
X, y = over.fit_resample(X,y) # 스모트를 리샘플링하여 X, y값을 저장한다.
counter = Counter(y) # y를 카운팅하여
print('SMOTE-based oversampled data : %s'% counter) # 출력한다.

for label, _ in counter.items(): # 카운터의 각 아이템마다
    row_ix = where(y == label)[0] # y가 라벨인 것의 0인덱스를 저장
    pyplot.scatter(X[row_ix, 0], X[row_ix, 1], label=str(label)) # X[row_ix, 0], X[rod_ix, 1], 라벨을 파라미터로 흩뿌려 그린다.
pyplot.legend()
pyplot.show() # 그린다.
