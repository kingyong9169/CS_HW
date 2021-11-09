import numpy as np
import matplotlib.pyplot as plt 

class MLP:
    def __init__(self, hidden_node = 3):
        self.input_node = 1; self.hidden_node = hidden_node; self.output_node = 1
        self.w1 = np.random.rand(self.hidden_node, self.input_node)
        self.b1 = np.random.rand(self.hidden_node, 1)
        self.w2 = np.random.rand(self.output_node, self.hidden_node)
        self.b2 = np.random.rand(self.output_node, 1)
    def sigmoid(self, x):
        return 1/(1 + np.exp(-x))
    
    def d_sigmoid(self, x):
        return self.sigmoid(x) * (1 - self.sigmoid(x));
    
    def train(self, train_x, train_y, alpha = 0.1, max_iter = 500):
        np.random.seed(0)
        input_node = self.input_node; hidden_node = self.hidden_node
        output_node = self.output_node; alpha = alpha; max_iter = max_iter
        for iter in range(1, max_iter):
            for i in range(n_train):
                z1 = np.dot(self.w1, train_x[i].reshape(1,1)) + self.b1; a1 = self.sigmoid(z1)
                z2 = np.dot(self.w2, a1) + self.b2; y_hat = z2; y_hat_list[i] = y_hat
                e = 0.5 * (train_y[i] - y_hat) ** 2; dy = - (train_y[i] - y_hat)
                dz2 = 1; dw2 = a1.T
                delta_w2 = dy * dz2 * dw2; delta_b2 = dy * dz2
                da1 = self.w2.T; dz1 = self.d_sigmoid(z1); dw1 = train_x[i].T
                delta_w1 = dy * dz2 * da1 * dz1 * dw1; delta_b1 = dy * dz2 * da1 * dz1
                self.w2 -= alpha * delta_w2; self.b2 -= alpha * delta_b2
                self.w1 -= alpha*  delta_w1; self.b1 -= alpha * delta_b1

    def predict(self, test_x):
        for i in range(n_test):
            z1 = np.dot(self.w1, test_x[i].reshape(1,1)) + self.b1
            a1 = self.sigmoid(z1)
            z2 = np.dot(self.w2, a1) + self.b2
            y_hat = z2
            y_hat_list[i] = y_hat
        return y_hat_list

n_train = 20
train_x = np.linspace(0, np.pi * 2, n_train)
train_y = np.sin(train_x)

n_test = 60
test_x = np.linspace(0, np.pi * 2, n_test)
test_y = np.sin(test_x)
y_hat_list = np.zeros(n_test)

mlp = MLP(hidden_node = 4)
mlp.train(train_x, train_y, max_iter = 600)
plt.plot(test_x, test_y, label = 'ground truth')

y_hat_list = mlp.predict(test_x)
plt.plot(test_x, y_hat_list, '-r', label = 'prediction')
plt.legend()
plt.show()
