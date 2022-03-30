from sklearn.tree import DecisionTreeRegressor
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('Machine-Learning/4주차/housing.data', header=None, sep='\s+') # 데이터 받아오기
df.columns = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', "AGE", 'DIS', 'RAD',
        'TAX', 'PTRATIO', 'B', 'LSTAT', 'MEDV'] # 컬럼 정의
print(df.head()) # head출력
X = df[['LSTAT']].values # LSTAT값 출력
y = df['MEDV'].values # MEDV값 출력

tree = DecisionTreeRegressor(max_depth=3) # 결정트리 회귀
tree.fit(X,y)

sort_idx = X.flatten().argsort() # 작은 값부터 데이터 위치 정렬
plt.scatter(X[sort_idx], y[sort_idx], c='lightblue') # 그래프 생성
plt.plot(X[sort_idx], tree.predict(X[sort_idx]), color='red', linewidth=2) # 그래프 선 그리기
plt.xlabel('LSTAT(% Lower Status of the Population)') # x 라벨
plt.ylabel('MEDV(Price in $1000)') # y 라벨
plt.show() # 그래프 창 띄우기