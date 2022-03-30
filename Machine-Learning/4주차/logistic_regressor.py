import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

dataset = pd.read_csv('Machine-Learning/4주차/User_Data.csv') # csv파일 불러오기
                      
x = dataset.iloc[:, [2, 3]].values # 2,3번째 행 선택
y = dataset.iloc[:, 4].values # 4번째 열만 선택

# 학습 데이터 테스트 데이터 분류하기
from sklearn.model_selection import train_test_split
xtrain, xtest, ytrain, ytest = train_test_split(x, y, test_size = 0.25, random_state = 0)

# 표준화하기
from sklearn .preprocessing import StandardScaler
sc_x = StandardScaler() # 표준화 진행
xtrain = sc_x.fit_transform(xtrain) # 2차원으로 변환
xtest = sc_x.transform(xtest) # 정규화
print(xtrain[0:10, :])  # xtrain 출력

from sklearn.linear_model import LogisticRegression
classifier = LogisticRegression(random_state = 0) # 로지스틱 회귀 진행
classifier.fit(xtrain, ytrain) # fit
y_pred = classifier.predict(xtest) # 예측값 구하기

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(ytest, y_pred) # 혼동행렬 만들기
print("혼동행렬 : \n", cm) # 혼동행렬 출력

from sklearn.metrics import accuracy_score
print("정확도 : ", accuracy_score(ytest, y_pred)) # 정확도 계산 후 출력

from matplotlib.colors import ListedColormap
X_set, y_set = xtest, ytest # 테스트 데이터를 set데이터로
X1, X2 = np.meshgrid(np.arange(start = X_set[:, 0].min() - 1, # 격자 그리드 만들기
                               stop = X_set[:, 0].max() + 1, step = 0.01),
                     np.arange(start = X_set[:, 1].min() -1, # 최소, 최대, step
                               stop = X_set[:, 1].max() + 1, step = 0.01))

plt.contourf(X1, X2, classifier.predict( # 2차원 등차선 표현
            np.array([X1.ravel(), X2.ravel()]).T).reshape( # reshape하기
                X1.shape), alpha = 0.75, cmap = ListedColormap(('red', 'green')))
            
plt.xlim(X1.min(), X1.max()) # x 좌표 축 값 범위
plt.ylim(X2.min(), X2.max()) # y 좌표 축 값 범위

for i, j in enumerate(np.unique(y_set)): # 중복 빼고 반복
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1], # X_set으로 산점도 그리기
                c = ListedColormap(('red', 'green'))(i), label = j) # color맵 그리기
    
plt.title('Classifier (Test set)') # title붙이기
plt.xlabel('Age') # x 라벨
plt.ylabel('Estimated Salary') # y 라벨
plt.legend() # 그래프 범례 그리기
plt.show() # 그래프 창 띄우기