import numpy as np # 모듈 가져오기
import matplotlib as mpl
from matplotlib import pyplot as plt
from sklearn.svm import SVC

def plot_xor(X, y, model, title, xmin=-3, xmax=3, ymin=-3, ymax=3): # plot xor 함수 선언
    XX, YY = np.meshgrid(np.arange(xmin, xmax, (xmax-xmin)/1000),
                         np.arange(ymin, ymax, (ymax-ymin)/1000)) # np의 meshgrid함수로 XX, YY구하기
    ZZ = np.reshape(model.predict(np.array([XX.ravel(), YY.ravel()]).T), XX.shape) # XX, YY의 ravel을 배열로 예측하여 reshape하기
    plt.contourf(XX, YY, ZZ, сmap=mpl.cm.Paired_r, alpha=0.5) # XX, YY, ZZ, cmap값으로 countourf 실행
    plt.scatter(X[y == 1, 0], X[y == 1, 1], c='b', marker='o', label='class 1', s=50) # 산점도 구하기
    plt.scatter(X[y == 0, 0], X[y == 0, 1], c='r', marker='s', label='class 0', s=50) # 산점도 구하기
    plt.xlim(xmin, xmax) # xlim구하기
    plt.ylim(ymin, ymax) # ylim구하기
    plt.title(title) # 타이틀 만들기
    plt.xlabel("x1") # x라벨
    plt.ylabel("x") # y라벨

np.random.seed(0) # 랜덤 시드
X_xor = np.random.randn(200, 2) # 랜덤 함수 실행하여 X_xor구하기
y_xor = np.logical_xor(X_xor[:, 0] > 0, X_xor[:, 1] > 0) # 논리 xor함수를 실행하여 y_xor에 대입
y_xor = np.where(y_xor, 1, 0) # y_xor의 where함수를 실행하여 대입
plt.scatter(X_xor[y_xor == 1, 0], X_xor[y_xor == 1, 1], c='b', marker='o', label='class 1', s=50) # 산점도 구하기
plt.scatter(X_xor[y_xor == 0, 0], X_xor[y_xor == 0, 1], c='r', marker='s', label='class 0', s=50) # 산점도 구하기
plt.legend()
plt.xlabel("x1") # x라벨
plt.ylabel("x2") # y라벨
plt.title("XOR problem") # 타이틀 만들기
plt.show() # 그리기

svc = SVC(kernel="linear").fit(X_xor, y_xor) # 선형 SVC함수 실행하여 X_xor, y_xor을 파라미터로 fit함수 실행
polysvc = SVC(kernel="poly", degree=2, gamma=1, coef0=0).fit(X_xor, y_xor) # poly SVC함수 실행하여 X_xor, y_xor을 파라미터로 fit함수 실행
rbfsvc = SVC(kernel="rbf").fit(X_xor, y_xor) # rbf SVC함수 실행하여 X_xor, y_xor을 파라미터로 fit함수 실행
sigmoidsvc = SVC(kernel="sigmoid", gamma=2, coef0=2).fit(X_xor, y_xor) # sigmoid SVC함수 실행하여 X_xor, y_xor을 파라미터로 fit함수 실행

plt.figure(figsize=(10, 14)) # 표현하기
plt.subplot(411) # subplot구하기
plot_xor(X_xor, y_xor, svc, "SVC with linear kernel") # X_xor, y_xor, svc로 plot_xor구하기
plt.subplot(412) # subplot구하기
plot_xor(X_xor, y_xor, polysvc, "SVC with ploynomial kernel") # X_xor, y_xor, polysvc로 plot_xor구하기
plt.subplot(413) # subplot구하기
plot_xor(X_xor, y_xor, rbfsvc, "SVC with RBF kernel") # X_xor, y_xor, rbfsvc로 plot_xor구하기
plt.subplot(414) # subplot구하기
plot_xor(X_xor, y_xor, sigmoidsvc, "SVC with sigmoid kernel") # X_xor, y_xor, sigmoidsvc로 plot_xor구하기
plt.tight_layout()
plt.legend()
plt.show() # 그리기