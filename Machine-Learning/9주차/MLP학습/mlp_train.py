import numpy as np
import matplotlib.pyplot as plt

class MLP:  # MLP클래스
    def __init__(self, hidden_node=3):  # 초기화 함수 정의
        self.input_node = 1;  self.hidden_node = hidden_node;  self.output_node = 1 # 
        self.w1 = np.random.rand(self.hidden_node, self.input_node) # hidden_node, input_node로 난수 배열
        self.b1 = np.random.rand(self.hidden_node, 1)   # (hidden_node, 1)차원 난수 배열 생성
        self.w2 = np.random.rand(self.output_node, self.hidden_node)    # output_node, hidden_node로 난수 배열
        self.b2 = np.random.rand(self.output_node, 1)   # (output_node, 1)차원 난수 배열 생성
         
    def sigmoid(self, x):   # 시그모이드 함수 정의
        return 1/(1+np.exp(-x))

    def d_sigmoid(self, x): # d-시그모이드 함수 정의
        return self.sigmoid(x)*(1-self.sigmoid(x))
    
    def train(self, train_x, train_y, alpha=0.1, max_iter=500): # train함수 정의
        np.random.seed(0)   # 랜덤 시드
        input_node = self.input_node;  hidden_node = self.hidden_node   # input_node, hidden_node 초기화
        output_node = self.output_node;  alpha = alpha;    max_iter = max_iter  # output_node, alpha, max_iter 초기화

        for iter in range(1, max_iter): # max_iter만큼 반복
            for i in range(n_train):    # n_train만큼 반복
                z1 = np.dot(self.w1, train_x[i].reshape(1,1)) + self.b1   # w1 * train_x[i].reshape(1,1) 행렬곱
                a1 = self.sigmoid(z1);  z2 = np.dot(self.w2, a1)+self.b2    # z1의 시그모이드, w2 * a1 행렬곱
                y_hat = z2;  y_hat_list[i] = y_hat  # y_hat과 y_hat_list 계산
                e = 0.5*(train_y[i] - y_hat)**2;  dy = -(train_y[i] - y_hat)    # e, dy 계산
                dz2 = 1;  dw2 = a1.T    # dz2, dw2 계산
                delta_w2 = dy*dz2*dw2;   delta_b2 = dy*dz2; da1 = self.w2.T # delta 계산

                dz1 = self.d_sigmoid(z1);   dw1 = train_x[i].T  # dz1, dw1 계산
                delta_w1 = dy*dz2*da1*dz1*dw1;  delta_b1 = dy*dz2*da1*dz1   # delta 계산
                self.w2 -= alpha*delta_w2;  self.b2 -= alpha*delta_b2   #   w2, b2 계산
                self.w1 -= alpha*delta_w1;  self.b1 -= alpha *delta_b1  # w1, b1 계산

    def predict(self, test_x):  # predict함수 정의
        for i in range(n_test): # n_test만큼 반복
            z1 = np.dot(self.w1, test_x[i].reshape(1,1)) + self.b1    # w1 * test_x[i].reshape(1,1) 행렬곱
            a1 = self.sigmoid(z1)   # 시그모이드 계산
            z2 = np.dot(self.w2, a1) + self.b2  # w2 * a1 행렬곱
            y_hat = z2  # y_hat = z2
            y_hat_list[i] = y_hat   #  y_hat_list계산
        return y_hat_list   # y_hat_list리턴

n_train = 20    # n_train개수 20
train_x = np.linspace(0, np.pi*2, n_train)  # n_train개 간격으로 배열
train_y = np.sin(train_x)   # train_x의 sin 계산

n_test = 60 # n_test개수 60
test_x = np.linspace(0, np.pi*2, n_test)    # n_test개 간격으로 배열
test_y = np.sin(test_x) # test_x의 sin 계산
y_hat_list = np.zeros(n_test)   # zeros계산

mlp = MLP(hidden_node=4)    # hidden_node 4로 MLP호출
mlp.train(train_x, train_y, max_iter=600)   # 학습하기
plt.plot(test_x, test_y, label='ground truth')   # plot그리기

y_hat_list = mlp.predict(test_x)    # predict함수로 예측
plt.plot(test_x, y_hat_list, '-r', label='prediction')  # plot그리기
plt.legend()    # legend
plt.show()  # 그래프 그리기
