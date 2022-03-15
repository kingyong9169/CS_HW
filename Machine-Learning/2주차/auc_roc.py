from cProfile import label # 모듈 import
from distutils.log import Log
from turtle import pos
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split

X, y = make_classification(n_samples=1000, n_classes=2, n_features=20, random_state=27)
# 분류를 만든다. 샘플:1000개, 클래스:2개, 특징:20개, 랜덤상태:27게
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=27)
# X, y변수를 학습, 테스트하는 메소드에서 리턴하는 값을 x 학습, x 테스트, y 학습, y 테스트에 넣는다.

from sklearn.linear_model import LogisticRegression
model1 = LogisticRegression() # 선형회귀 모델을 선언
model1.fit(X_train, y_train) # 이 모델에 X 학습, y 학습 변수를 넣는다.
pred_prob1 = model1.predict_proba(X_test) # X테스트 변수로 모델의 확률을 예측한 값을 변수로 선언

from sklearn.metrics import roc_curve
fpr1, tpr1, thresh1 = roc_curve(y_test, pred_prob1[:,1], pos_label=1) # y테스트, 확률 예측, pos 라벨을 변수로 roc커브 메소드에서 리턴한 값을 변수로 선언

random_probs = [0 for i in range(len(y_test))] # y 테스트 길이를 범위로 랜덤 확률에 집어 넣는다.
p_fpr, p_tpr, _ = roc_curve(y_test, random_probs, pos_label=1) # y 테스트, 랜덤 확률을 파라미터로 roc 커브 메소드를 리턴한 값을 변수로 선언

from sklearn.metrics import roc_auc_score
auc_score1 = roc_auc_score(y_test, pred_prob1[:,1]) # y 테스트, 확률 예측 변수를 파라미터로 roc, auc 점수 메소드를 리턴한 값을 변수로 선언
print('AUC value : %s' %auc_score1) # 변수 프린트

import matplotlib.pyplot as plt
plt.style.use('seaborn') # seaborn을 사용하여 스타일 표현
plt.plot(fpr1, tpr1, linestyle='--', color='orange', label='Logistic Regression') # fpr1, tpr1 변수를 오렌지색으로 표현
plt.plot(p_fpr, p_tpr, linestyle='--', color='blue') # p_fpr, p_tpr 변수를 파란색으로 표현
plt.title('ROC curve') # 제목
plt.xlabel('False Positive Rate') # x축 이름
plt.ylabel('True Positive rate') # y축 이름

plt.legend(loc='best')
plt.savefig('ROC', dpi=300) # 이미지 저장
plt.show()
