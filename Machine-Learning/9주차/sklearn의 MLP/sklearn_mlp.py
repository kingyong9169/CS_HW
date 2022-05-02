import pandas as pd
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report,confusion_matrix

wine = load_wine()  # 와인 데이터 불러오기
data = pd.DataFrame(data=wine['data'], columns=wine['feature_names'])   # DataFrame적용
print(data.head())  # data의 헤드 출력

X = wine.data   # 와인 데이터
y = wine.target # 와인 target
X_train, X_test, y_train, y_test = train_test_split(X, y)   # 와인 데이터로 학습, 테스트 세트 분리

scaler = StandardScaler()   # StandardScaler
scaler.fit(X_train) # X_train에 fit적용
StandardScaler(copy=True, with_mean=True, with_std=True)    # StandardScaler

X_train = scaler.transform(X_train) # X_train 스케일 조정
X_test = scaler.transform(X_test)   # X_test 스케일 조정

mlp = MLPClassifier(hidden_layer_sizes=(13,13,13),max_iter=500) # MLPClassifier 생성
mlp.fit(X_train,y_train)    # X_train, y_train로 mlp fit 적용
predictions = mlp.predict(X_test)   # 예측하기
print(confusion_matrix(y_test, predictions))    # 혼동행렬 출력
print(classification_report(y_test, predictions))   # 평가지표 출력
