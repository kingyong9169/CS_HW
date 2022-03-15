# multi-class classification
from sklearn.datasets import make_classification # 모듈 import
from sklearn.multiclass import OneVsRestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import roc_curve
from sklearn.metrics import roc_auc_score

X, y = make_classification(n_samples=1000, n_classes=3, n_features=20,
                            n_informative=3, random_state=42)
# 1000개 샘플, 3개 클래스, 20개 기능, 정보 3개, 랜덤 상태 42개로 분류를 만들어 X, y에 넣는다.
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4,
                                                    random_state=42)
# X, y, 테스트 사이즈, 랜덤 상태를 파라미터로 학습 테스트를 만들어 X학습, X테스트, y학습, y테스트 변수를 만든다.
clf = OneVsRestClassifier(LogisticRegression()) # 로지스틱 회귀를 파라미터로 OneVsRest분류기를 만든다.
clf.fit(X_train, y_train) # X학습, y학습 변수를 분류기에 넣는다.
pred = clf.predict(X_test) # X테스트 변수를 분류기에서 예측한 값을 저장
pred_prob = clf.predict_proba(X_test) # X테스트 변수를 파라미터로 분류기에서 확률 예측하여 변수로 저장한다.

fpr = {} # 변수들을 선언한다.
tpr = {}
thresh = {}
n_class = 3
for i in range(n_class): # 3을 범위로 하여
    fpr[i], tpr[i], thresh[i] = roc_curve(y_test, pred_prob[:,i], pos_label=i) # y 테스트, 확률 예측값을 파라미터로한 roc커브한 값을 각 인덱스에 해당하는 변수에 저장

from matplotlib import pyplot as plt
plt.plot(fpr[0], tpr[0], linestyle='--', color='orange', label='Class 0 vs Rest') # 0인덱스에 해당하는 변수를 오렌지색
plt.plot(fpr[1], tpr[1], linestyle='--', color='green', label='Class 1 vs Rest') # 1인덱스에 해당하는 변수를 초록색
plt.plot(fpr[2], tpr[2], linestyle='--', color='blue', label='Class 2 vs Rest') # 2인덱스에 해당하는 변수를 파란색
plt.title('Multiclass ROC curve') # 제목
plt.xlabel('False Positive Rate') # x라벨
plt.ylabel('True Positive rate') # y라벨
plt.legend(loc='best')
plt.savefig('Multiclass ROC', dpi=300) # 사진을 저장
plt.show() # 출력한다.
