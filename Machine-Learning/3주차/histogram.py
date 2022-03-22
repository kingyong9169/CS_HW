import numpy as np # 모듈 import
from matplotlib import pyplot as plt

X1 = np.random.randn(1000) # np의 랜덤함수 파라미터를 1000으로 불러와서 X1변수에 저장한다.
X2 = 10 + np.random.randn(1000) # np의 랜덤함수 파라미터를 1000으로 불러와서 X2변수에 저장한다.

plt.figure(figsize=(10,6)) # 그래프를 그린다.
plt.hist(X1, bins=20, alpha=0.4) # X1을 히스토그램으로 그린다.
plt.hist(X2, bins=20, alpha=0.4) # X2를 히스토그램으로 그린다.
plt.show()
