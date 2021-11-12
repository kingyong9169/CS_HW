import numpy as np # numpy 모듈 호출
import matplotlib.pyplot as plt # matplotlib 모듈 호출


class MLP: # MLP 클래스
    def __init__(self, hidden_node=3): # 초기화 함수
        self.input_node = 1 # 입력 노드 개수 초기화
        self.hidden_node = hidden_node # 은닉층 노드 개수 초기화
        self.output_node = 1 # 출력 노드 개수 초기화
        self.w1 = np.random.rand(self.hidden_node, self.input_node) # w1 가중치(입력층->은닉층) 생성
        self.b1 = np.random.rand(self.hidden_node, 1) # b1 가중치(은닉층) 생성
        self.w2 = np.random.rand(self.output_node, self.hidden_node) # w2 가중치(은닉층->출력층) 생성
        self.b2 = np.random.rand(self.output_node, 1) # b2 가중치(출력층) 생성

    def sigmoid(self, x): # 시그모이드 함수
        return 1/(1 + np.exp(-x))

    def d_sigmoid(self, x): # 미분한 시그모이드 함수
        return self.sigmoid(x) * (1 - self.sigmoid(x))

    def train(self, train_x, train_y, alpha=0.1, max_iter=500): # MLP 학습 함수
        np.random.seed(0)
        input_node = self.input_node # 입력층 노드 개수
        hidden_node = self.hidden_node # 은닉층 노드 개수
        output_node = self.output_node # 출력층 노드 개수
        alpha = alpha # 알파 선언
        max_iter = max_iter # 최대 반복 횟수
        for iter in range(1, max_iter): # 최대 반복 횟수만큼 반복
            for i in range(n_train): # n_train 만큼 반복
                z1 = np.dot(self.w1, train_x[i].reshape(1, 1)) + self.b1 # z1(은닉층) 계산
                a1 = self.sigmoid(z1) # 시그모이드 함수의 파라미터로 넘기기
                z2 = np.dot(self.w2, a1) + self.b2 # z2(은닉층) 계산
                y_hat = z2 # z2를 출력값으로
                y_hat_list[i] = y_hat # y_hat을 리스트에 넣는다
                e = 0.5 * (train_y[i] - y_hat) ** 2 # 오차함수
                dy = - (train_y[i] - y_hat) # y를 비분
                dz2 = 1 # z2 미분
                dw2 = a1.T # w2 미분
                delta_w2 = dy * dz2 * dw2 # 델타 w2 계산
                delta_b2 = dy * dz2 # 델타 b2 계산
                da1 = self.w2.T # a1 미분 값
                dz1 = self.d_sigmoid(z1) # 미분한 시그모이드 함수
                dw1 = train_x[i].T # w1 미분
                delta_w1 = dy * dz2 * da1 * dz1 * dw1 # 델타 w1
                delta_b1 = dy * dz2 * da1 * dz1 # 델타 b1
                self.w2 -= alpha * delta_w2 # 가중치 w2 계산
                self.b2 -= alpha * delta_b2 # 가중치 b2 계산
                self.w1 -= alpha * delta_w1 # 가중치 w1 계산
                self.b1 -= alpha * delta_b1 # 가중치 b1 계산

    def predict(self, test_x): # MLP 예측함수
        for i in range(n_test): # n_test만큼 반복
            z1 = np.dot(self.w1, test_x[i].reshape(1, 1)) + self.b1 # 은닉층 계산
            a1 = self.sigmoid(z1) # 시그모이드 함수 계산
            z2 = np.dot(self.w2, a1) + self.b2 # 출력 값 계산
            y_hat = z2 # y^ 선언
            y_hat_list[i] = y_hat # 리스트에 넣는다
        return y_hat_list # 리스트 리턴


n_train = 20 # 20번 학습
train_x = np.linspace(0, np.pi * 2, n_train) # x축
train_y = np.sin(train_x) # y축

n_test = 60 # 60번 학습
test_x = np.linspace(0, np.pi * 2, n_test) # x축
test_y = np.sin(test_x) # y축
y_hat_list = np.zeros(n_test) # y^ 리스트

mlp = MLP(hidden_node=4) # MLP의 은닉층 노드는 4개
mlp.train(train_x, train_y, max_iter=600) # 최대 반복 횟수 600번으로 학습
plt.plot(test_x, test_y, label='ground truth') # 그래프 출력

y_hat_list = mlp.predict(test_x) # MLP를 예측한 값을 y^리스트에 넣는다
plt.plot(test_x, y_hat_list, '-r', label='prediction') # 그래프 출력
plt.legend()
plt.show()
