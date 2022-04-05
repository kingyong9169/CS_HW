import pandas as pd # 모듈 가져오기
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler

pdiabetes = pd.read_csv('Machine-Learning/5주차/diabetes.csv', header=None) # 당뇨병 데이터 가져오기
print(pdiabetes[0:5]) # 프린트하기

x = pdiabetes.iloc[1:,8:] # 당뇨병 데이터의 iloc하기
y = pdiabetes.iloc[1:,8:].values.flatten() # 당뇨병 데이터의 iloc한 값을 평탄화하기
print('x shape: ', x.shape, 'y shape: ', y.shape) # 프린트하기

x_train, x_test, y_train, y_test = train_test_split(x, y, random_state=0) # 학습, 테스트로 나누어 변수 추출
std_scl = StandardScaler() # StandardScaler 실행하기
std_scl.fit(x_train) # x_train으로 fit함수 실행

x_train = std_scl.transform(x_train) # x_train으로 std_scl 변형하기
x_test = std_scl.transform(x_test) # x_test으로 std_scl 변형하기

svc = SVC(kernel='rbf') # SVC실행
svc.fit(x_train, y_train) # x_train, y_train 파라미터로 fit함수 실행

print('학습 데이터 정확도 : ', svc.score(x_train, y_train)) # 프린트하기
print('테스트 데이터 정확도 : ', svc.score(x_test, y_test)) # 프린트하기
