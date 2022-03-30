#KNN 기반 분류
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier

iris = datasets.load_iris() # iris로 데이터 로딩해오기
X = iris.data # x 데이터
y = iris.target  # y 타겟

# 학습 데이터 테스트 데이터 분류
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
scaler = StandardScaler() # 표준화
scaler.fit(X_train)
X_train = scaler.transform(X_train) # train데이터의 속성값 정규화
X_test = scaler.transform(X_test) # 테스트데이터의 속성값 정규화

classifier = KNeighborsClassifier(n_neighbors=5) #KNN 분류기
classifier.fit(X_train, y_train)
y_pred = classifier.predict(X_test) # KNN 예측값 구하기

print(confusion_matrix(y_test, y_pred)) #혼동행렬 생성
print(classification_report(y_test, y_pred)) # 평가지표 확인하기

error = [ ]
for i in range(1, 40): # K값의 범위 (1..40)
        knn = KNeighborsClassifier(n_neighbors=i) # K근접 이웃 분류
        knn.fit(X_train, y_train)
        pred_i = knn.predict(X_test) # KNN 예측값 구하기
        error.append(np.mean(pred_i != y_test)) # 에러 범위에 넣기

plt.figure(figsize=(12, 6))
plt.plot(range(1, 40), error, color='red', linestyle='dashed', marker='o', markerfacecolor='blue', markersize=10)
plt.title('Error Rate K Value') # title 붙이기
plt.xlabel('K Value') # x 라벨
plt.ylabel('Mean Error') # y 라벨
plt.show() # 그래프 창 띄우기