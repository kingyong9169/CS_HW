from sklearn.decomposition import PCA # 모듈 import
from sklearn import datasets
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
import numpy as np

iris = datasets.load_iris() # 데이터셋을 load_iris함수를 실행하여 iris에 넣는다.
print(list(iris.keys())) # 출력한다.
X = iris["data"[0:4]] # iris[data]값을 X에 넣는다.
label = iris["target"] # label[target]에 넣는다.

pca = PCA(n_components = 2) # 컴포넌트 개수를 2로하여 PCA함수를 실행한다.
X2D = pca.fit_transform(X) # pca를 X변형하여 X2D를 구한다.

for i, j in enumerate(np.unique(label)): # label의 유일한 값으로 i, j를 반복문 초기화 변수로 하여
    plt.scatter(X2D[label == j, 0], X2D[label == j, 1], # X2D, c를 파라미터로 그래프를 그린다.
                c = ListedColormap(('red', 'green', 'blue'))(i), label = j)
plt.legend()
plt.show()
