import pandas as pd # 모듈 가져오기
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC

mushroom = pd.read_csv('Machine-Learning/5주차/mushrooms.csv', header=None) # csv파일을 읽어오기
print(mushroom.head(4)) # 프린트하기

X=[] # X, Y변수 선언
Y=[]
for idx,row in mushroom[1:].iterrows(): # 버섯 데이터 중 row데이터로 idx, row 추출
    Y.append(row.loc[0]) # Y에 row데이터 추가
    row_x=[] # row_x 선언
    for v in row.loc[1:]: # row에서 for문 돌리기
        row_x.append(ord(v)) # row_x에 데이터 추가하기
    X.append(row_x) # X에 데이터 추가하기

print('\n속성: \n', X[0:3]) # 프린트
print('\n부류: \n', Y[0:3]) # 프린트
x_train, x_test, y_train, y_test=train_test_split(X,Y,test_size=0.25) # 학습, 테스트로 나누어 변수 추출

svc=SVC() # SVC한 값 저장
svc.fit(x_train,y_train) # svc에 Xtrain, ytrain 파라미터로 fit 실행

print('학습 데이터 정확도 : ', svc.score(x_train,y_train)) # 프린트하기
print('테스트 데이터 정확도 : ', svc.score(x_test,y_test)) # 프린트하기