from sklearn import datasets # 모듈 import
import pandas as pd

iris = datasets.load_iris() # 데이터셋을 load_iris함수를 실행하여 iris에 넣는다.
labels = pd.DataFrame(iris.target) # iris의 target를 DataFrame함수를 실행한다.
labels.columns=['labels'] # labels의 컬럼을 labels로 한다.
data = pd.DataFrame(iris.data) # iris의 data를 DataFrame함수를 실행한다.
data.columns=['Sepal length','Sepal width','Petal length','Petal width'] # data의 컬럼을 지정한다.
data = pd.concat([data, labels],axis=1) # pd에 [data, labels]를 추가한다.
feature = data[['Sepal length','Sepal width','Petal length','Petal width']] # data의 해당 값을 구한다.

import matplotlib.pyplot as plt # 모듈을 import
from sklearn.manifold import TSNE

model = TSNE(learning_rate=100, perplexity=30) # 학습율을 100, perplexity를 30으로 하여 TSNE를 실행한다.
transformed = model.fit_transform(feature) # feature를 파라미터로 모델을 변형한다.

xs = transformed[:,0] # 변형된 값을 xs에 넣는다.
ys = transformed[:,1] # 변형된 값을 ys에 넣는다.
plt.scatter(xs,ys,c=labels['labels']) # 그래프를 출력한다.

plt.show()
