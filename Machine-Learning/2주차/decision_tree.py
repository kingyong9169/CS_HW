import matplotlib.pyplot as plt # 모듈 import
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier, plot_tree
iris = load_iris() # iris를 로드한다.

decision_tree = DecisionTreeClassifier(criterion="entropy", random_state=0, max_depth=3) # 엔트로피, 랜덤 상태0, 최대깊이를 3으로 결정트리분류기를 만든다.
decision_tree = decision_tree.fit(iris.data, iris.target) # 결정트리분류기에 iris의 데이터와 타겟을 넣는다.

plt.figure() # 이 결정트리분류기를 출력한다.
plot_tree(decision_tree, filled=True)
plt.show()
