import pandas as pd # pandas 모듈 불러오기
from sklearn.datasets import load_wine # sklearn 모듈 호출
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report, confusion_matrix

wine = load_wine() # wine데이터
data = pd.DataFrame(data=wine['data'], columns=wine['feature_names']) # DataFrame리턴 값을 data에 넣는다
print(data.head()) # data의 헤드를 출력한다.

X = wine.data # X에 와인 데이터의 data를 넣는다.
y = wine.target # y에 와인 데이터의 target을 넣는다.
X_train, X_test, y_train, y_test = train_test_split(X, y) # 학습 테스트 스플릿 함수의 결과 값에서 나온 값으로 X 학습, X 테스트, y 학습, y 테스트 값을 정의한다

scaler = StandardScaler() # 표준 스케일러를 정의한다.
scaler.fit(X_train) # X 학습을 파라미터로 스케일러의 fit함수를 호출한다.
StandardScaler(copy=True, with_mean=True, with_std=True) # 표준 스케일러 호출

X_train = scaler.transform(X_train) # X 학습 값에 스케일러를 X 학습으로 변환한 값을 넣는다.
X_test = scaler.transform(X_test) # X 테스트 값에 스케일러를 X 테스트로 변환한 값을 넣는다.

mlp = MLPClassifier(hidden_layer_sizes=(13, 13, 13), max_iter=500) # MLP분류 함수를 호출한다
mlp.fit(X_train, y_train) # X 학습, y 학습을 파라미터로 mlp의 fit함수를 호출한다.
predictions = mlp.predict(X_test) # mlp의 예측함수를 호출한다
print(confusion_matrix(y_test, predictions)) # 출력한다
print(classification_report(y_test, predictions))
