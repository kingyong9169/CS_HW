# SVM 구현
from calendar import c # 모듈 가져오기
import numpy as np
import cvxopt
from sklearn.datasets._samples_generator import make_blobs
from sklearn.model_selection import train_test_split
from matplotlib import pyplot as plt
from sklearn.metrics import confusion_matrix

class SVM: # SVM 클래스 선언
    def fit(self, X, y): # fit메소드 선언
        n_samples, n_features = X.shape # 데이터 개수 속성 개수
        K = np.zeros((n_samples, n_samples)) # H = X ^ T X
        for i in range(n_samples): # 샘플 개수만큼 반복
            for j in range(n_samples): # 샘플 개수만큼 반복
                K[i,j] = np.dot(X[i], X[j]) # np의 i, j점으로 K[i,j]선언
        H = cvxopt.matrix(np.outer(y, y) * K) # np의 outer로 H 선언
        f = cvxopt.matrix(np.ones(n_samples) * -1) # f = -1 (1xN)
        B = cvxopt.matrix(y, (1, n_samples))       # B =y^T
        b = cvxopt.matrix(0.0)                     # b > O
        A = cvxopt.matrix(np.diag(np.ones(n_samples) * -1)) # -1 (NxN)
        a = cvxopt.matrix(np.zeros(n_samples))  # 0 (1xN)
        solution = cvxopt.solvers.qp(H, f, A, a, B, b)  # quadratic problem solver
    
        a = np.ravel(solution['x']) # 라그랑주 승수
        sv = a > 1e-5  # 라그랑주 승수가 0보다 큰것
        ind = np.arange(len(a))[sv] # a길이의 범위로 ind 선언
        self.a = a[sv] # a에 라그랑주 승수 넣기
        self.sv = X[sv] # sv에 라그랑주 승수가 0보다 큰것 넣기
        self.sv_y = y[sv] # sv_y에 라그랑주 승수가 0보다 큰것 넣기
        self.b = 0      # 절편
        for n in range(len(self.a)): # a의 길이만큼 반복
            self.b += self.sv_y[n] # b에 sv_y[n]값 더하기
            self.b -= np.sum(self.a * self.sv_y * K[ind[n], sv]) # b에서 a * sv_y * K[ind, sv] 빼기
        self.b /= len(self.a) # a의 길이로 나누기
        self.w = np.zeros(n_features)   # 가중치
        for n in range(len(self.a)): # a의 길이만큼 반복
            self.w += self.a[n] * self.sv_y[n] * self.sv[n] # w += a(n) * sv_y(n) * sv(n)구하기
            
    def project(self, X): # 프로젝트 함수 선언
        return np.dot(X, self.w) + self.b # np의 X, w로 만든 점 + b값 리턴

    def predict(self, X): # 예측 함수 선언
        return np.sign(self.project(X)) # np에 project(X)값으로 sign하여 리턴하기

X, y = make_blobs(n_samples=250, centers=2, random_state=0, cluster_std=0.60) # 샘플, conters로 blob 만들기
y[y == 0] = -1      # 0값을 -1로 변환
y = y.astype(float) # float으로 변환하기
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0) # 학습, 테스트로 나누어 변수 추출

svm = SVM() # SVM함수 실행
svm.fit(X_train, y_train) # X_train, y_train으로 svm fitgkrl

def f(x, w, b, c=0): # f함수 선언
    return (-w[0] * x - b + c) / w[1] # 계산식 리턴하기

plt.scatter(X_train[:, 0], X_train[:, 1], c=y_train, cmap='winter') # 산점도 그리기

a0 = -2; a1 = f(a0, svm.w, svm.b) # W.X + b = O
b0 = 4; b1 = f(b0, svm.w, svm.b)
plt.plot([a0,b0], [a1,b1], 'k') # plot찍기

a0 = -2; a1 = f(a0, svm.w, svm.b, 1) # W.X + b = 1
b0 = 4; b1 = f(b0, svm.w, svm.b, 1)
plt.plot([a0,b0], [a1,b1], 'k--') # plot찍기

a0 = -2; a1 = f(a0, svm.w, svm.b, -1) # W.X + b = -1
b0 = 4; b1 = f(b0, svm.w, svm.b, -1)
plt.plot([a0,b0], [a1,b1], 'k--') # plot찍기

y_pred = svm.predict(X_test) # X_test로 예측하기
print('training\n', confusion_matrix(y_test, y_pred)) # 프린트
y_pred = svm.predict(X_test) # X_test로 예측하기
print('test\n', confusion_matrix(y_test, y_pred)) # 프린트
plt.title('SVM')
plt.show() # 그리기