#-*- coding: utf-8 -*-

from sklearn.datasets import fetch_openml # 모듈을 불러온다.
mnist = fetch_openml('mnist_784', version=1, cache=True) # 모듈을 불러온다.

X = mnist.data/255 # X 값
y = mnist.target # y 값

import matplotlib.pyplot as plt # 모듈을 불러온다.
plt.imshow(X[0].reshape(28,28), cmap='gray') # plt로 보여준다.
plt.show()
print("이미지 레이블 : {}".format(y[0]))

import torch # 토치를 불러온다.
from torch.utils.data import TensorDataset, DataLoader # 모듈을 불러온다.
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X,y, test_size=1/7, random_state=0) # X 학습, 테스트 y 학습, 테스트를 초기화한다.
X_train = torch.Tensor(X_train) # X 학습에 토치.텐서 값을 넣어준다.
X_test = torch.Tensor(X_test) # X 테스트에 토치.텐서 값을 넣어준다.
y_train = torch.LongTensor(list(map(int, y_train))) # y 학습에 y 학습 값을 맵핑한 값을 파라미터로 토치.롱텐서에 넣은 값으로 변경한다.
y_test = torch.LongTensor(list(map(int, y_test))) # y 테스트에 y 테스트 값을 맵핑한 값을 파라미터로 토치.롱텐서에 넣은 값으로 변경한다.

ds_train = TensorDataset(X_train, y_train) # ds 학습에 X 학습, y 학습을 파라미터로 텐서데이터셋을 넣어준다.
ds_test = TensorDataset(X_test, y_test) # ds 테스트에 X 테스트, y 테스트를 파라미터로 텐서데이터셋을 넣어준다.

loader_train = DataLoader(ds_train, batch_size=64, shuffle=True) # 로더 학습에 ds 학습값을 파라미터로 데이터로더 함수를 호출한다.
loader_test = DataLoader(ds_test, batch_size=64, shuffle=False) # 로더 테스트에 ds 테스트값을 파라미터로 데이터로더 함수를 호출한다.

from torch import nn # 모듈을 불러온다.
model = nn.Sequential() # 모델을 정의한다.
model.add_module('fc1', nn.Linear(28*28*1, 100)) # fc1 모듈을 추가하여 모델 구성
model.add_module('relu1', nn.ReLU()) # relu1 모듈을 추가하여 모델 구성
model.add_module('fc2', nn.Linear(100,100)) # fc2 모듈을 추가하여 모델 구성
model.add_module('relu2', nn.ReLU()) # relu2 모듈을 추가하여 모델 구성
model.add_module('fc3', nn.Linear(100,10)) # fc3 모듈을 추가하여 모델 구성

from torch import optim # 모듈을 불러온다.
loss_fn = nn.CrossEntropyLoss() # 손실 함수를 정의한다.
optimizer = optim.Adam(model.parameters(), lr=0.01) # 옵티마이저를 Adam 방식으로 정의한다.

def train(epoch): # 학습 함수
  model.train() # 학습 모드로 변환
  for data, targets in loader_train: # 로더 학습에서 data, targets을 처음부터 하나씩 불러온다.
    optimizer.zero_grad() # 그레디언트 초기화
    outputs = model(data) # 결과에 모델(데이터)값을 넣는다.
    loss = loss_fn(outputs, targets) # 손실도에 손실함수의 결과 값을 넣는다.
    loss.backward() # 손실을 되돌린다.
    optimizer.step() # 옵티마이저의 다음 단계로 넘어간다.
  print('에포크 {}: 완료'.format(epoch))

def test(head): # 테스트 함수
  model.eval() # 테스트 모드로 변환
  correct = 0 # 정확도 초기화
  with torch.no_grad(): # 추론 과정이므로 그레디언트 계산 불필요
    for data, targets in loader_test: # 로더 테스트에서 data, targets을 처음부터 하나씩 불러온다.
      outputs = model(data) # 결과에 모델(데이터)값을 넣는다.
      _, predicted = torch.max(outputs.data, 1) # 예측값에 토치.최대(결과의 데이터)를 넣는다.
      correct += predicted.eq(targets.data.view_as(predicted)).sum() # 정확도에 target의 데이터와 예측값을 비교하여 합산 값을 증가한다.
  data_num = len(loader_test.dataset) # 로더 테스트의 데이터셋의 길이를 데이터 길이에 넣는다.
  print('{} 정확도: {}/{}({:.Of}%)'.format(head, correct, data_num, 100.*correct/data_num))

test('시작')
for epoch in range(3): # epoch를 3번 반복한다.
  train(epoch) # epoch를 3번 학습한다
  test('학습중')
test('학습 후')

index = 10 # 테스트 데이터 중에서 확인해볼 데이터의 인덱스
model.eval() # 모델 테스트 모드로 전환
data = X_test[index] # X 테스트[인덱스] 값을 데이터에 넣고
output = model(data) # 모델 적용한다.
print('{} 번째 학습데이터의 테스트 결과 : {}'.format(index,output))
_, predicted = torch.max(output.data, 0) # 예측값에 토치.최대(결과의 데이터)를 넣는다.
print('{} 번째 데이터의 예측 : {}'.format(index, predicted))
X_test_show = (X_test[index]).numpy() # X 테스트를 보여준다.
plt.imshow(X_test_show.reshape(28,28), cmap='gray') # plt로 보여준다.
print('실제 레이블: {}'.format(y_test[index]))
