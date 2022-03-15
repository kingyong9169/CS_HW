# Random Undersampling
from collections import Counter # 모듈 import
from sklearn.datasets import make_classification
from imblearn.over_sampling import SMOTE
from imblearn.under_sampling import RandomUnderSampler
from imblearn.pipeline import Pipeline
from matplotlib import pyplot
from numpy import where

# make_classification(): n_redundant (no. of redundant features)
#                u        weights (portion of samples assigned to a class)
X, y = make_classification(n_samples=10000, n_features=2, n_redundant=0,
  n_clusters_per_class=1, weights=[0.99], flip_y=0, random_state=1)
# 10000개 샘플, 2개 특징, 0 redundatn, 클러스터 당 1 클래스, 0.99무게 등 파라미터로 분류기를 만들어 X, y에 저장

counter = Counter(y) # y를 카운팅한다.
print('generated data: %s' % counter) # 카운터를 출력한다.
for label, _ in counter.items(): # 카운터의 아이템마다
    row_ix = where(y == label)[0] # y가 라벨인 것의 0인덱스를 저장
    pyplot.scatter(X[row_ix, 0], X[row_ix, 1], label=str(label)) # X[row_ix, 0], X[rod_ix, 1], 라벨을 파라미터로 흩뿌려 그린다.
pyplot.legend()
pyplot.show() # 출력한다.

# sampling_strategy : Iminority samples|/|Imajority saamples| after resampling
under = RandomUnderSampler(sampling_strategy=0.5) # 샘플링 전략을 0.5로 랜덤 언더 샘플링하여 under에 저장
X, y = under.fit_resample(X, y) # under에 X, y를 넣어 새로운 X, y를 만든다.
count = Counter(y) # y를 카운팅한다.
print('Undersampled data: %s' % counter) # 카운터를 출력한다.

for label, _ in counter.items(): # 카운터의 아이템마다
    row_ix = where(y == label)[0] # y가 라벨인 것의 0인덱스를 저장
    pyplot.scatter(X[row_ix, 0], X[row_ix, 1], label=str(label)) # X[row_ix, 0], X[rod_ix, 1], 라벨을 파라미터로 흩뿌려 그린다.
pyplot.legend()
pyplot.show() # 출력한다.
