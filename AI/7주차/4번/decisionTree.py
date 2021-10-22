import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier, plot_tree

iris = load_iris()  # load_iris 데이터를 iris에 넣음
decision_tree = DecisionTreeClassifier(
    criterion="entropy", random_state=0, max_depth=3)  # 결정트리에 엔트로피, state, 깊이를 파라미터로 만든다.
# iris의 데이터와 타겟을 결정 트리에 넣는다.
decision_tree = decision_tree.fit(iris.data, iris.target)

plt.figure()
plot_tree(decision_tree, filled=True)  # 결정트리를 만들어서 출력한다.
plt.show()
