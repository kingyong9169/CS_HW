import numpy as np # 모듈 import
from sklearn.metrics import accuracy_score, confusion_matrix
y_true = ["positive", "negative", "negative", "positive", "positive", "positive", "negative"] # y true 변수
y_pred = ["positive", "negative", "positive", "positive", "negative", "positive", "positive"] # y 예측 변수

cm = confusion_matrix(y_true, y_pred) # 위 변수를 혼동 행렬 메소드로 표현
print('confusion matrix')
print(cm) # 혼동행렬 출력

a = accuracy_score(y_true, y_pred) # 위 변수를 파라미터로 정확도 점수 메소드로 표현
print('accuracy: ', a) # 정확도 점수 출력

y_pred = [0, 5, 2, 4] # 실제 값을 넣는다.
y_true = [0, 1, 2, 3] # 실제 값을 넣는다.
a = accuracy_score(y_true, y_pred) # 위 변수를 정확도 점수 메소드로 표현
print('accuracy: ', a) # 정확도 점수 출력
