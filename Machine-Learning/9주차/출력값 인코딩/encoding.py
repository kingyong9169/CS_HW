from numpy import array
from numpy import argmax 
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import OneHotEncoder

data = ['cold', 'cold', 'warm', 'cold', 'hot', 'hot', 'warm', 'cold', 'warm', 'hot']    # 배열 정의
values = array(data)    # 배열로 만들기

label_encoder = LabelEncoder() # 정수 인코딩
integer_encoded = label_encoder.fit_transform(values)   # fit_transform으로 정수 인코딩
print('\n정수 인코딩: \n', integer_encoded) # 정수 인코딩 값 출력

onehot_encoder = OneHotEncoder(sparse=False) # one-hot 인코딩
integer_encoded = integer_encoded.reshape(len(integer_encoded), 1)  # reshape로 정수 인코딩
onehot_encoded = onehot_encoder.fit_transform(integer_encoded)   # fit_transform으로 one-hot 인코딩
print('\none-hot 인코딩\n', onehot_encoded) # one-hot인코딩 출력

inverted = label_encoder.inverse_transform([argmax(onehot_encoded[0, :])])  # one-hot인코딩 변환하기
print('\n', onehot_encoded[0], ' => ', inverted)    # 인코딩 된 데이터 값 출력
